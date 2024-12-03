#!/bin/bash

echo "=== Pruebas Funcionales Profundas ==="

# Función para generar in.txt dinámicamente
generate_infile() {
    echo "Generando in.txt con líneas de longitud: $*"
    echo -n "" > in.txt
    for num in "$@"; do
        cadena_aleatoria=$(openssl rand -base64 $((num * 4 / 3)) | tr -dc 'a-zA-Z0-9' | head -c $num)
        echo "$cadena_aleatoria" >> in.txt
    done
    echo "Archivo creado: in.txt"
}
make
# Función para ejecutar y comparar
run_test() {
    description=$1
    pipex_command=$2
    shell_command=$3

    echo "--- $description ---"
    # Ejecutar con pipex
    eval "$pipex_command"
    # Ejecutar con shell
    eval "$shell_command"

    # Comparar resultados
    if diff outfile_pipex outfile_shell; then
        echo "[PASS] $description" >> logs/funtional.log
    else
        echo "[FAIL] $description" >> logs/funtional.log
        echo "Salida esperada:" >> logs/funtional.log
        cat outfile_shell >> logs/funtional.log
        echo "Salida obtenida:" >> logs/funtional.log
        cat outfile_pipex >> logs/funtional.log
    fi
}

# 1. Mandatory: Pruebas con 2 comandos
generate_infile 10 20 30
run_test "Comando simple (ls | wc)" \
    "./pipex in.txt "ls" "wc" outfile_pipex" \
    "bash -c 'cat in.txt | ls | wc > outfile_shell'"


echo "¿Vas a probar los bonus? y/n"
read bonus
if( ! bonus = y); then
# 2. Bonus: Múltiples pipes
make bonus
generate_infile 50 100 200
run_test "Múltiples pipes (ls | sort | wc)" \
    "./pipex in.txt 'ls' 'sort' 'wc' outfile_pipex" \
    "bash -c 'cat in.txt | ls | sort | wc > outfile_shell'"
fi

make re

# 4. Errores intencionales: Comando inválido
run_test "Comando inválido (invalid_cmd | wc)" \
    "./pipex in.txt 'invalid_cmd' 'wc' outfile_pipex" \
    "bash -c 'cat in.txt | invalid_cmd | wc > outfile_shell'"

