## Q1: Repetir els passos amb l'ordre yes > /dev/null. Què fa aquesta ordre? Quines diferències trobeu amb l'execució de l'ordre anterior? (0,5 punts)

- L'ordre ```yes```, imprimeix infinitament una cadena fins finalitzar el procés,i l'arxiu */dev/null* és buit, per tant el proces 'yes' es queda funcionant sense imprimir res.
    
- Que l'estat d'aquest procés es R, i l'execució anterior té com a estat S.


## Q2: Modificar aquest procés per obtenir una sortida indicant Hola sóc el procés pare i Hola sóc el procés fill. (0,5 punts)

```c
        pid_t p1 = fork();
        if (p1 == 0) {
                printf("Hola sóc el procés fill \n");
        } else if(p1 > 0) {
                printf("Hola sóc el procés pare \n");
        }
````

## Q3: Modificar aquest exemple fent anar la funció execv(). (0,5 punts)

Aquest apartat s'ha solucionat al fitxer **exercici03.c**

## Q4: Explica el funcionament del programa. Indicant quants senyals s'envien, quin procés envia el senyal, i on l'envia. (2,5 punts)

Primer es crea un procés pare i imprimeix el seu pid. Tot seguit crida a un waitpid(),que esperarà a que el seu fill acabi, canvie o retorni una senyal.El fill imprimeix el seu pid i envia un senyal a ell mateix per a parar(SIGSTOP),al canviar l'estat tornem al procés pare.Tornem al procés pare, que imprimeix una frase i envia al seu fill una senyal de continuar(SIGCONT) i fa un altre waitpid() per a processar aquest canvi d'estat. El pare fa un altre waitpid() que durarà mentre el fill imprimeix algo i acaba. Per últim el pare imprimeix una frase i acaba.

Els canvis d'estat del fill generats per SIGCON i SIGSTOP generen la senyal SIGCHL que notifica el pare d'aquest events. L'ordre ```exit()```també la genera.

## Q5: Programeu un programa pare, fill net que tingui la següent sortida (mantenint l’ordre). A més a més els fills, hauran de generar un enter aleatori entre els valors 0,1 i 2. El 0=apunyalat, 1=decapitat.  (4 punts)

Aquest apartat s'ha solucionat al fitxer **ex5.c**


