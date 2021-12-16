## Activitat01: Escriu un script count_txt.sh que conti el nombre total de fitxers “.txt” en el directori actual, i que mostri aquest número per pantalla. Pots utilitzar comandes existents com ls i wc, o pots usar una estructura iterativa.
- count_txt.sh

## Activitat02: La comanda rm estàndard no demana confirmació abans d’eliminar un arxiu. Escriu un script anomenat safe_rm, tal que faci una còpia abans d’eliminar un únic arxiu (és a dir, únicament permetrà eliminar un sol arxiu a la vegada):
- safe_rm.sh
- Desa aquest script en un directori anomenat bin dins del teu directori inicial. Després afegeix el directori “$HOME/bin” al PATH del sistema de forma que puguis executar el script safe_rm des de qualsevol directori. Indica el procediment seguit per afegir el script al PATH. 
    - Per a fer-ho tenim dos opcions: 
        - De forma temporal: 
        ```
        export PATH="$HOME/bin:$PATH"
        ```
        - De forma permanent: 
        ```
        nano ~/.bashrc
        ```
        Escrivim aquesta linia a l'arxiu:
        ```
        export PATH="$HOME/bin:$PATH"
        ```
        I tornem a executar el arxiu:
        ```
        source ~/.bashrc
        ```

## Activitat 03: Completar aquest script.
- check.sh

## Activitat 04: Completar aquest script.
- check_rm_exec.sh

## Activitat 05: Modificar-la per tenir en compte els signes.
 - check_args.sh

## Activitat 06: Completar el script següent de manera que que si no li passem cap argument a la funció imprimeixi el seu PID amb la data i si li passem un argument imprimeixi aquest argument amb la data.
- activitat_06.sh

## Activitat 07: Explicar detalladament que fa el script següent : 
- activitat_07.sh

##  Activitat 08:  Modificar activitat07.sh per utilitzar un array on es guardin els pids dels processos que es van generant.  
- activitat_08.sh

## Activitat 09: Heu d'entregar un script que faci:
- Comprovi que no existeix un altre script amb el mateix nom i diferent pid executant-se.
- Assegurar que l’usuari executi el script amb 2 arguments.L’argument 1 ha de ser el nombre de processos a generar. I l’argument 2 ha de ser el programa a recobrir (tota la ruta).
- Cal verificar que argument 1 és un enter més gran que 0.
- Cal verificar que argument 2 existeix com a fitxer regular.
- Si l’argument 2 no té permisos d’execució, se li atorgaran.
- Es mostrarà un menú a la pantalla, on: 
    - Opció 1: executarà la fàbrica de processos amb els arguments rebuts.
    - Opció 2:  eliminarà l’executable passat com a paràmetre.
    - Opció 3:  traurà els permisos d’execució de l’argument 2. 

- activitat_09.sh

## Activitat 10: Si executeu aquest script, observareu que el script no realitza la suma de forma correcta. Expliqueu quin és el problema i proposeu una solució.
- activitat_10.sh
- El problema esta en que al sumar el 072, aquest 0 no deixa que la suma és realitzi correctament.