#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int main(void)
{
        char *argv[3] = {"find", ".", NULL};

        int pid = fork();

        if (pid == 0)
        {
                /*
                Per a poder utilitzar el programa amb execv(), hem hagut d'indicar
                la ruta completa de la comanda find.
                */
                execv("/usr/bin/find", argv);
        }

        /* El pare dorm 2 segons (més endavant veure com amb wait podem sincronitzar millor pare i fill*/

        sleep(2);

        printf("Final del proces pare\n"
               " - el fill no arribarà mai a aquest punt d'execució a causa del recobriment\n");

        return 0;
}