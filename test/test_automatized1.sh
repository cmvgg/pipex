#!/bin/bash

mkdir -p exits logs
make
make
make re

directorio_archivos="./"

chmod +x ./test/archivo_in.sh
./test/archivo_in.sh

contador_succ=0
contador_rev=0
contador_seg=0

function generar_comando() {
  local num_palabras=$((RANDOM % 5 + 1))
  comando=""
  contenido_archivo=$(cat ./in)
  comandos=( "ps "  "" " " "grep a" "wc -w" "ls -l" "wc -l" "cat" "head" "tail" "sort" "uniq" "grep s" "tr -d s" "" "tee" "split" "nl" "fold" "expand" "unexpand" "wc" "sort -u" "uniq -c" "grep -E w" "sed" "awk '{print $1}'" "dd" "cpio -p in" )
  excluidos=()

  for i in $(seq 1 $num_words); do
    random_index=$((RANDOM % ${#comandos[@]}))
    comando_seleccionado=${comandos[$random_index]}
    
    if [[ ! " ${excluidos[@]} " =~ " $comando_seleccionado " ]]; then
      comando="$comando $comando_seleccionado"
    fi
  done
  echo "$comando"
}

echo "Introduce el numero de pruebas: "
read num_pruebas

if [[ ! $num_pruebas =~ ^[0-9]+$ ]]; then
  echo "El valor introducido no es un número válido."
  exit 1
fi

for i in $(seq 1 $num_pruebas); do
  comando1=$(generar_comando "$i")
  comando2=$(generar_comando "$i")
 
  <./in $comando1 | $comando2 > ./bash.txt
  
  ./pipex ./in "$comando1" "$comando2" ./out 


if [[ $? -eq 139 ]]; then
  ((contador_seg++))
  tput setaf 1
  echo "El proceso recibió la señal Segmentation fault"
  tput sgr0
else
    diff -q ./out ./bash.txt
    if [[ $? -eq 0 ]]; then
    ((contador_succ++))
    tput setaf 2
      echo "prueba superada con éxito"
    tput sgr0
    else
    ((contador_rev++))
      tput setaf 1
        echo "prueba no superada (si el comando es ps o ps aux el diff da error pero es normal)"
      tput sgr0
    fi
fi 
  echo "La prueba realizada es: ./pipex in "\"$comando1"\" "\"$comando2"\" out 
  
  "
rm -rf ./out
rm -rf ./bash.txt
done



echo -e "Ejecución finalizada con "$num_pruebas" pruebas:"

tput setaf 2 
      echo ""$contador_succ" superadas"  
tput sgr0
tput setaf 1 
      echo ""$contador_rev" para revisar"  
tput sgr0
tput setaf 1 
      echo ""$contador_seg" segfault"  
tput sgr0 

#make clean: 

      make fclean >> fclean

rm -rf fclean
rm -rf xaa

#correct bonus:
echo "¿Vas a probar los bonus? y/n"
read bonus
if( ! bonus = y); then

      make bonus
      clear

contador_succ=0
contador_rev=0
contador_seg=0

function generar_comando() {
  local num_palabras=$((RANDOM % 5 + 1))
  comando=""
  contenido_archivo=$(cat ./in)
  comandos=( "ps "  "" " " "grep a" "wc -w" "ls -l" "wc -l" "cat" "head" "tail" "sort" "uniq" "grep s" "tr -d s" "" "tee" "split" "nl" "fold" "expand" "unexpand" "wc" "sort -u" "uniq -c" "grep -E w" "sed" "awk '{print $1}'" "dd" "cpio -p in" )
  excluidos=()

  for i in $(seq 1 $num_words); do
    random_index=$((RANDOM % ${#comandos[@]}))
    comando_seleccionado=${comandos[$random_index]}
    
    if [[ ! " ${excluidos[@]} " =~ " $comando_seleccionado " ]]; then
      comando="$comando $comando_seleccionado"
    fi
  done
  echo "$comando"
}

echo "Introduce el numero de pruebas: "
read num_pruebas

if [[ ! $num_pruebas =~ ^[0-9]+$ ]]; then
  echo "El valor introducido no es un número válido."
  exit 1
fi

for i in $(seq 1 $num_pruebas); do
  comando1=$(generar_comando "$i")
  comando2=$(generar_comando "$i")
 
  <./in $comando1 | $comando2 > ./bash.txt
  
  ./pipex ./in "$comando1" "$comando2" ./output 


if [[ $? -eq 139 ]]; then
  ((contador_seg++))
  tput setaf 1
  echo "El proceso recibió la señal Segmentation fault"
  tput sgr0
else
    diff -q ./output ./bash.txt
    if [[ $? -eq 0 ]]; then
    ((contador_succ++))
    tput setaf 2
      echo "prueba superada con éxito"
    tput sgr0
    else
    ((contador_rev++))
      tput setaf 1
        echo "prueba no superada (si el comando es ps o ps aux el diff da error pero es normal)"
      tput sgr0
    fi
fi 
  echo "La prueba realizada es: ./pipex in "\"$comando1"\" "\"$comando2"\" output 
  
  "
rm -rf ./output
rm -rf ./bash.txt
done



echo -e "Ejecución finalizada con "$num_pruebas" pruebas:"

tput setaf 2 
      echo ""$contador_succ" superadas"  
tput sgr0
tput setaf 1 
      echo ""$contador_rev" para revisar"  
tput sgr0
tput setaf 1 
      echo ""$contador_seg" segfault"  
tput sgr0 
#make clean:
    make fclean >> fclean

rm -rf xaa
rm -rf ./output.txt
rm -rf fclean

fi