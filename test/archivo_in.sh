#!/bin/bash

echo "Introduce el número de caracteres por línea (separados por espacios): "
read -a num_caracteres
echo -n "" > ./in
for num in "${num_caracteres[@]}"; do
  cadena_aleatoria=$(openssl rand -base64 $((num * 4 / 3)) | tr -dc 'a-zA-Z0-9' | head -c $num)
  echo "$cadena_aleatoria" >> ./in
  done

echo "Archivo creado: in"