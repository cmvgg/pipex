#!/bin/bash

make 

generate_large_infile() {
    echo "Generando archivo grande de $1 líneas..."
    base64 /dev/urandom | head -c $((1024 * 1024 * $1)) > in.txt
    echo "Archivo in.txt generado: $(du -h in.txt)"
}

generate_empty_infile() {
    echo "Generando archivo vacío..."
    > in.txt
    echo "Archivo vacío generado: in.txt"
}

generate_special_infile() {
    echo "Generando archivo con caracteres especiales..."
    printf "%s\n" "!@#$%^&*()_+{}:<>?" "áéíóúñç" "漢字仮名交じり文" > in.txt
    echo "Archivo con caracteres especiales generado: in.txt"
}

run_test() {
    description=$1
    pipex_command=$2
    shell_command=$3

    echo "--- $description ---"
    eval "$pipex_command" 2>/dev/null
    eval "$shell_command" 2>/dev/null

    if diff outfile_pipex outfile_shell &>/dev/null; then
        echo "[PASS] $description" >> logs/funtional2.log
    else
        echo "[FAIL] $description" >> logs/funtional2.log
        echo "Differences:" >> logs/funtional2.log
        diff outfile_pipex outfile_shell >> logs/funtional2.log
    fi
}

echo "=== Pruebas Extremas ==="

# 1. Archivo vacío
generate_empty_infile
run_test "Archivo vacío (ls | wc)" \
    "./pipex in.txt 'ls' 'wc' outfile_pipex" \
    "bash -c 'cat in.txt | ls | wc > outfile_shell'"

# 2. Archivo grande
generate_large_infile 1024 # 1GB
run_test "Archivo grande (cat | wc)" \
    "./pipex in.txt 'cat' 'wc' outfile_pipex" \
    "bash -c 'cat in.txt | cat | wc > outfile_shell'"

# 3. Archivo con caracteres especiales
generate_special_infile
run_test "Archivo con caracteres especiales (grep á | wc)" \
    "./pipex in.txt 'grep á' 'wc' outfile_pipex" \
    "bash -c 'cat in.txt | grep á | wc > outfile_shell'"

# 4. Comando que falla
run_test "Comando inválido (cmd_fail | wc)" \
    "./pipex in.txt 'cmd_fail' 'wc' outfile_pipex" \
    "bash -c 'cat in.txt | cmd_fail | wc > outfile_shell'"

echo -e "¿Vas a probar los bonus? y/n"
read bonus
if( ! bonus = y); then

make bonus
# 5. Múltiples pipes
generate_large_infile 128 # 128MB
run_test "Múltiples pipes (cat | sort | uniq | wc)" \
    "./pipex in.txt 'cat' 'sort' 'uniq' 'wc' outfile_pipex" \
    "bash -c 'cat in.txt | sort | uniq | wc > outfile_shell'"
fi

make
# 6. Archivo sin permisos de lectura
chmod -r in.txt
run_test "Archivo sin permisos de lectura (cat | wc)" \
    "./pipex in.txt 'cat' 'wc' outfile_pipex" \
    "bash -c 'cat in.txt | wc > outfile_shell'"
chmod +r in.txt

# 7. Archivo sin permisos
chmod -777 in.txt
chmod +r in.txt
run_test "Archivo sin permisos (cat | wc)" \
    "./pipex in.txt 'cat' 'wc' outfile_pipex" \
    "bash -c 'cat in.txt | wc > outfile_shell'"
chmod +rxw in.txt
