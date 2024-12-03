#!/bin/bash

# Crear directorios para los resultados
mkdir -p logs exits

log_file="logs/stress_tests.log"
> $log_file

# Función para registrar resultados de las pruebas
log_result() {
    local test_name=$1
    local status=$2
    echo "[$(date)] $test_name: $status" >> $log_file
}

# Función para ejecutar una prueba y guardar resultados
run_test() {
    local test_name=$1
    local command=$2
    local output_file="exits/${test_name}.txt"

    echo "--- Ejecutando prueba: $test_name ---"
    eval "$command" > $output_file 2>&1

    if [ $? -eq 0 ]; then
        log_result "$test_name" "PASS"
    else
        log_result "$test_name" "FAIL"
    fi
}

# Pruebas de estrés

# 1. Ejecuciones simultáneas con datos grandes
generate_large_infile() {
    echo "Generando archivo grande para pruebas..."
    base64 /dev/urandom | head -c $((1024 * 1024 * 512)) > in.txt # 512MB
    echo "Archivo in.txt generado."
}

generate_large_infile
run_test "stress_large_file_cat_wc" "./pipex in.txt 'cat' 'wc' outfile_pipex"

# 2. Ejecuciones en bucle
echo "Iniciando pruebas de estrés con bucles..."
for i in {1..100}; do
    run_test "stress_loop_$i" "./pipex in.txt 'cat' 'wc' outfile_pipex"
done

# 3. Prueba con múltiples pipes y archivos grandes
run_test "stress_multiple_pipes" "./pipex in.txt 'cat' 'sort' 'uniq' 'wc' outfile_pipex"

# Limpieza
rm -f in.txt
echo "Pruebas de estrés completadas. Revisa los resultados en $log_file y exits/"
