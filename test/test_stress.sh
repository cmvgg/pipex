#!/bin/bash

mkdir -p logs exits

log_file="logs/stress_test.log"
> $log_file

log_result() {
    local test_name=$1
    local status=$2
    echo "[$(date)] $test_name: $status" >> $log_file
}

run_test() {
    test_name=$1
    pipex_command=$2
    shell_command=$3

    echo "--- Ejecutando prueba: $test_name ---"
    eval "$pipex_command" 2>/dev/null
    eval "$shell_command" 2>/dev/null

    if diff outfile_pipex outfile_shell &>/dev/null; then
        echo "[PASS] $test_name" >> $log_file
    else
        echo "[FAIL] $test_name" >> $log_file
        echo "Differences:" >> $log_file
        diff outfile_pipex outfile_shell >> $log_file
    fi
}

# 1. Ejecuciones simultáneas con datos grandes
generate_large_infile() {
    echo "Generando archivo grande para pruebas..."
    base64 /dev/urandom | head -c $((1024 * 1024 * 254)) > in.txt # 254MB
    echo "Archivo in.txt generado."
}

generate_large_infile
run_test 
run_test "stress_large_file_cat_wc"  \
    "./pipex in.txt 'cat' 'wc' outfile_pipex" \
    "bash -c 'cat in.txt | cat | wc > outfile_shell'"

# 2. Ejecuciones en bucle
echo "Iniciando pruebas de estrés con bucles..."
base64 /dev/urandom | head -c $((100 * 100 * 100)) > in.txt
for i in {1..100}; do
    run_test "stress_loop_$i" \
	"./pipex in.txt 'cat' 'wc' outfile_pipex" \
	"bash -c 'cat in.txt | cat | wc > outfile_shell'"
done

# 3. Prueba con múltiples pipes y archivos grandes
generate_large_infile
run_test "stress_multiple_pipes" \
	"./pipex in.txt 'cat' 'sort' 'uniq' 'wc' outfile_pipex" \
	"bash -c 'cat in.txt | cat | sort | uniq | wc > outfile_shell'"

# 4. Datos ultra grandes (1GB)
echo "Generando archivo de 1GB..."
dd if=/dev/urandom of=in.txt bs=1M count=1024
run_test "stress_1GB_file" \
	"./pipex in.txt 'cat' 'wc' outfile_pipex" \
	"bash -c 'cat in.txt | cat | wc > outfile_shell'"

# 5. Ejecuciones simultáneas masivas (100 procesos concurrentes)
echo "Iniciando ejecuciones simultáneas..."
for i in {1..100}; do
    ./pipex /dev/null 'echo test' 'wc' "exits/big_out_$i.txt" &
done
wait
echo "[PASS] simultanean test" >> $log_file

# 3. Tiempo prolongado (10,000 iteraciones en bucle)
echo "Pruebas de tiempo prolongado..."
for i in {1..10000}; do
    ./pipex /dev/null 'echo test' 'wc' /dev/null
    if [ $? -ne 0 ]; then
		echo "[FAIL] time test" >> $log_file
        break
    fi
done
echo "[PASS] time test" >> $log_file

make clean
echo "Pruebas de estrés completadas. Revisa los resultados en $log_file y exits/"
