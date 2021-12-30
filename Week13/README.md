# Activitat 02 (1punt): Completeu la comanda per obtenir la següent sortida. Bàsicament ha de comptar tots els pokémons del tipus Dragon, Fire o others.
```
awk ' 
    BEGIN { print "Counting pokemons..." } \
    /Fire/ { ++f } /Dragon/ { ++d } $0 !~ /Fire/ && $0 !~ /Dragon/ {++o}\
    END   { print "Fire:",f, "\nDragon:",d, "\nOthers:",o }' \
    pokemon.csv
```
# Activitat 03 (1 punt): Completeu la comanda per obtenir la següent sortida. Implementeu un filtre a AWK per imprimir el nom dels pokémons que coincideixin amb la restricció següent:  tipus Fire or Fight i que el seu nom comença amb M.
```
awk -F, '
BEGIN{OFS = ""} \
$2 ~ /^[mM]/ \
{
    if ($3 == "Fire" || $4 == "Fire" || $3 == "Fighting" || $4 == "Fighting")
        print $2, " types[", $3,",",$4,"]";
}' pokemon.csv
```
# Activitat 04 (1 punt): Realitzar la mateixa acció sense utilitzar una estructura de bucle.
```
awk '{gsub(",",";",$0);print}' pokemon.csv > pokedex.csv
```

# Activitat 06 (2 punt): Tv Shows. Implementeu un script podeu fer servir awk i bash per transformar la informació input en la informació output.
```

```
