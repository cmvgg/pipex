#!/bin/bash

echo "=== Verificando Entregables ==="

if [ -f "Makefile" ]; then
    echo "[OK] Makefile presente"
else
    echo "[FAIL] Makefile no encontrado"
    exit 1
fi

for target in all clean fclean re; do
    make $target &>/dev/null
    if [ $? -eq 0 ]; then
        echo "[OK] make $target funciona correctamente"
    else
        echo "[FAIL] make $target falló"
    fi
done
