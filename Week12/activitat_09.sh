#!/bin/bash
name=$(basename $2)
x=$(pidof -x $(basename $2))

if [ -z "$x" ]; then                     ##Comprovi que no existeix un altre script amb el mateix nom i diferent pid executant-se.
    if [[ $# -eq 2 ]]; then              #Assegurar que l’usuari executi el script amb 2 arguments.
        if [[ $1 -gt 0 && -f $2 ]]; then #Cal verificar que argument 1 és un enter més gran que 0 i que argument 2 existeix com a fitxer regular.
            chmod +x $2                  #Donar permisos d'execució al argument 2
            options=("1) Executar la fàbrica\n2) Eleminar executable\n3) Traure permisos d'execució\n4) Sortir\nInsereix una opcio:")

            ##Menú
            while :; do
                echo -e $options
                read opt
                case $opt in
                1) ## Executar fabrica de processos amb els arguments rebuts.
                    /bin/bash ./activitat_08.sh $1
                    ;;
                2) ## Eliminarà l’executable passat com a paràmetre.
                    rm $2
                    ;;
                3) ## Traurà els permisos d’execució de l’argument 2.
                    chmod -x $2
                    ;;
                4) # Sortir
                    break
                    ;;
                *) echo "Opció no vàlida" ;;
                esac
            done
        fi
    fi
fi