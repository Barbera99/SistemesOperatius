## Explica per què necessitem la línia amb el comentari  //******* TIP: Taula ASCII.
- El primer valor (\015) serveix per a realitzar el salt de linia, i el (\012) serveix per a començar una nova linia.

## Act 01: Analitzeu la següent situació i comenteu amb detall que succeeix al sistema i quins perills pot comportar per l'usuari.
SYSCALL_DEFINE1(my_syscall , char *, msg) 
{
    printk(KERN_INFO "my_syscall :\"%s\"\n", msg);
    return 0;
}

- Si no realitzem cap tipus de comprovació amb l'adreça, podriem veure les dades que hi han a l'adreça, independement de l'usuari, ja que el kernel te accés a totes.

## Explicació de l'última part.
- En el fitxer rootkit.c basicament si volem afegir un nou tractament de crida del sistema, afegirem una nova funció amb asmlinkage i establirem el tractament que voldrem realitzar sobre aquesta, la qual posteriorment afegirem en el hook_trace aquesta, per a que quan detecti la crida, executi la funció corresponent.
- En el fitxer helper.c establim les funcions per enganxar i desenganxar el rootkit al kernel, enganxant aquest quan es realitza la crida de sistema pertinent i desenganxant-lo per a que no es trobin petjades d'aquest. 