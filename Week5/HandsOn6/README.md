## Descriu les diferències entre aquests dos codi i raona el motiu de les diferències observades. (Fixa't en el fork() i en l'obertura del descriptor open()).
- En el primer codi, aquest crea 2 descriptors de un mateix fitxer que funcionen de manera independent, de manera que el primer que obre aquest, escriurà "so" i el segon, sobreescriurà el primer fitxer amb "so".
- En el segon codi, el fill hereda el descriptor, de manera que els dos operen amb el mateix i per tant quan un escriu "so", es mou l'apuntador i el segon, escriu "so" a continuació.

## Modifiqueu el codi anterior per tenir una comunicació bidireccional seguint els passos anteriors.
- activitatsPipes1.c

## On van les dades després de l’escriptura a una pipe, però abans de la lectura del pipe?
- Es mouen pel nucli(Kernel).

## Es comparteix l’espai d'adreces entre dos processos Pare-Fill que comparteixen un pipe?
- No, ja que al realitzar el fork, és creen en 2 espais d'adreces diferents i tant pare com fill comparteixen pipe perque aquesta la hem definit abans de fer el fork.

## Explica que fa el codi següent i raona l'efecte de comentar i descomentar la línia marcada amb //(X).
- El fill va escrivint i a mesura que aquest escriu, el pare va llegint i imprimint. Si no descomentem aquesta linia, el pare es queda esperant a que algu escrigui infinitament, ja que ningú tanca l'escriptura del pipe. ç

## Completeu aquest codi amb c per aconseguir replicar la comanda (ls | wc -l).
- activitatsPipes2.c

## Modifiqueu el codi anterior per tenir dos processos fills, un farà el ls i l'altre el wc -l. El pare esperarà que els dos fills acabin per acabar.
- activitatsPipes3.c

## Milloreu el codi presentat, eliminar repeticions, simplificant la lògica, millorant el Makefile... Com a mínim heu de fer una aportació.
- EscapeRoom/sala.c
- Línia 168, hem canviat la condició del if per a fer-ho de manera mes curta.

## Activtat final: Pokémon
## Millorant la pokédex a partir de l'aventura (1 punts)
## Simulant combats Pokémon (3 punts)