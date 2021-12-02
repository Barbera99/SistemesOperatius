## Quin problema podria tenir un procés que executa el codi següent, si rebem un SIGINT. Com podem solucionar-ho?  (2 punts)
Si rebem un SIGINT, podria passar que el codi no s'acabes d'executar al complet, en aquest cas podria passar que l'arxiu no es tanques o que l'arxiu temp.txt no es borrés.
Ho podem solucionar de dos formes. La primera és ignorar les senyals de SIGINT. L'altra és que quan rebem un SIGINT tanquem l'arxiu i borrem l'arxiu "temp.txt".

En aquest cas hem decidit ignorar els SIGINT, hem fet servir un bucle infinit per a comprovar que funciona correctament.
```
int main(void) {
    signal(SIGINT, SIG_IGN);
    FILE *psFile;
    psFile = fopen("temp.txt", "w");
    fclose(psFile);
    remove("temp.txt");
    while(true) {
    }  
    return 0;
}
```