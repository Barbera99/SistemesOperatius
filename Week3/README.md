## Explica per què necessitem la línia amb el comentari  //******* TIP: Taula ASCII.
- El primer valor (\015) serveix per a realitzar el salt de linia, i el (\012) serveix per a començar una nova linia.

## Act 01: Analitzeu la següent situació i comenteu amb detall que succeeix al sistema i quins perills pot comportar per l'usuari.
SYSCALL_DEFINE1(my_syscall , char *, msg) 
{
    printk(KERN_INFO "my_syscall :\"%s\"\n", msg);
    return 0;
}

- Si no realitzem cap tipus de comprovació amb l'adreça, podriem veure les dades que hi han a l'adreça, independement de l'usuari, ja que el kernel te accés a totes.

