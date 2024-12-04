#!/bin/bash

mkdir -p exits logs

make
make

directorio_archivos="./"

chmod +x ./test/archivo_in.sh
./test/archivo_in.sh

contador_succ=0
contador_rev=0
contador_seg=0

function generar_comando() {
  local num_palabras=$((RANDOM % 5 + 1))
  comando=""
  contenido_archivo=$(cat ./in.txt)
  comandos=( "ps "  "" " " "grep a" "wc -w" "ls -l" "wc -l" "cat" "head" "tail" "sort" "uniq" "grep s" "tr -d s" "" "tee" "split" "nl" "fold" "expand" "unexpand" "wc" "sort -u" "uniq -c" "grep -E w" "sed --null-data in" "awk '{print $1}'" "dd" "cpio -p in" )
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
 
  <./in.txt $comando1 | $comando2 > ./bash.txt
  
  ./pipex ./in.txt "$comando1" "$comando2" ./out 


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
		echo "prueba no superada MANDATORY (si el comando es ps o ps aux el diff da error pero es normal)" >> exits/automatized1.txt
		echo "La prueba realizada es: ./pipex in "\"$comando1"\" "\"$comando2"\" out 
		" >> exits/automatized1.txt
      tput sgr0
    fi
fi 
  echo "La prueba realizada es: ./pipex in "\"$comando1"\" "\"$comando2"\" out "
rm -rf ./out
rm -rf ./bash.txt
done



echo "Ejecución MANDATORY finalizada con "$num_pruebas" pruebas:" > logs/automatized1.log

tput setaf 2 
      echo ""$contador_succ" superadas"  >> logs/automatized1.log
tput sgr0
tput setaf 1 
      echo ""$contador_rev" para revisar"  >> logs/automatized1.log
tput sgr0
tput setaf 1 
      echo ""$contador_seg" segfault"  >> logs/automatized1.log
tput sgr0 

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
  contenido_archivo=$(cat ./in.txt)
  comandos=( "ps "  "" " " "grep a" "wc -w" "ls -l" "wc -l" "cat" "head" "tail" "sort" "uniq" "grep s" "tr -d s" "" "tee" "split" "nl" "fold" "expand" "unexpand" "wc" "sort -u" "uniq -c" "grep -E w" "sed --null-data" "awk '{print $1}'" "dd" "cpio in" )
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
 
  <./in.txt $comando1 | $comando2 > ./bash.txt
  
  ./pipex ./in.txt "$comando1" "$comando2" ./output 


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
		echo "prueba no superada BONUS (si el comando es ps o ps aux el diff da error pero es normal)" >> exits/automatized1.txt
		echo "La prueba realizada es: ./pipex in "\"$comando1"\" "\"$comando2"\" out 
		" >> exits/automatized1.txt
      tput sgr0
    fi
fi 
  echo "La prueba realizada es: ./pipex in "\"$comando1"\" "\"$comando2"\" output 
  
  "
rm -rf ./output
rm -rf ./bash.txt
done

echo -e "Ejecución de BONUS finalizada con "$num_pruebas" pruebas:" >> logs/automatized1.log

tput setaf 2 
      echo ""$contador_succ" superadas"  >> logs/automatized1.log
tput sgr0
tput setaf 1 
      echo ""$contador_rev" para revisar"  >> logs/automatized1.log
tput sgr0
tput setaf 1 
      echo ""$contador_seg" segfault"  >> logs/automatized1.log
tput sgr0

rm -rf xaa
rm -rf ./output.txt

fi