#!/bin/bash
directori="./safe_rm_recycle"
if [[ $# -eq 1 ]]; then
    if [[ ! -d $directori ]]; then
        mkdir $directori
    fi
    cp ./$1 $directori
    rm ./$1
else 
    echo "Nombre d'arguments incorrecte ($# arguments de 1 necessari)"
fi