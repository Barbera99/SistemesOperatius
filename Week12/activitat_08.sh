#!/bin/bash

N=$1 ## Guardem el nombre de processos a crear.
complete=0
fail=0
echo "Hi, I am the factory [$$]..." ##Imprimim el PID del script actual.
pids=()
for ((i=0;i<N;i++)) ## Per cada proces a crear realitzarem el següent:
do

# Donar a p.sh permissos d'execució abans d'executar.
( ./p.sh ) &
sleep 3
pids+=(" $!") ## Anem guardant els PID's dels últims processos, (es a dir els que hem creat)
echo "Hi, the factory creates: ${pids[i]} ..." ## Mostrem el PID del process creat.

done

for p in "${pids[@]}"; ## Recorrem els PID's anteriorment guardats.
do
    
    if wait $p; then ## Si el process creat es finalitza correctament augmentem el contador complete.

        (( complete++ ))

    else ## Cas contrari augmentem fail.

        (( fail++ ))

    fi

done

echo "$complete processes completed successfully." 

echo "$fail processes failed to completed."

echo "Done."