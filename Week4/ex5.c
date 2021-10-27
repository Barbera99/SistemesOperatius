#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <stdlib.h>

int generar_random()
{
    srand(getpid());
    return rand() % 2;
}


int main()
{
    int status = 0;

    pid_t pid = fork();
    pid_t pid_1;

    if (pid > 0)
    {
        printf("\nBenvinguts a la casa Stark");
        fflush(stdout);
        pid = getppid();
        printf("\nHola sóc Rickard Stark casat amb Lyarra Stark amb pid = %d", pid);
        fflush(stdout);
        wait(&status);
        // char *msgN, *msgR;
        int estat = WEXITSTATUS(status);

        
/*
        if (estat == 0)
        {
            msgN = "decapitat";
            msgR = "decapitat";
        }
        else if (estat == 1)
        {
            msgN = "decapitat";
            msgR = "apunyalat";
        }
        else if (estat == 2)
        {
            msgN = "apunyalat";
            msgR = "decapitat";
        }
        else if (estat == 3)
        {
            msgN = "apunyalat";
            msgR = "apunyalat";
        }*/


        //printf("\nEn resum el meu fill Robb ha estat %s, en Ned %s i jo en Rickard amb pid = %d i m’han executat.\nThe winter is coming!!!!!", msgR, msgN, pid);

        // Una simplificació xD
        printf("\nEn resum el meu fill Robb ha estat %s, en Ned %s i jo en Rickard amb pid = %d i m’han executat.\nThe winter is coming!!!!!",  (estat == 3 || estat == 1)? "apunyalat": "decapitat", (estat == 3 || estat == 2)? "apunyalat": "decapitat", pid);
    }
    else
    {
        printf("\n Hola sóc en Ned fill del matrimoni del Richard i la Lyarra amb pid = %d", getpid());
        fflush(stdout);
        pid_1 = fork();

        if (pid_1 > 0)
        {
            wait(&status);
            int estat_Ned = generar_random();

            char *msg;
            if (estat_Ned == 0)
            {
                msg = "decapitat";
            }
            else
            {
                msg = "apunyalat";
            }
            printf("\nSóc en Ned amb pid = %d i m’acaben de %s.", getpid(), msg);
            int estat_Robb = WEXITSTATUS(status);

            // Decapitat | Decapitat
            if (estat_Ned == 0 && estat_Robb == 0)
            {
                exit(0);
            }
            // Decapitat | Apunyalat
            if (estat_Ned == 0 && estat_Robb == 1)
            {
                exit(1);
            }
            // Apunyalat | Decapitat
            if (estat_Ned == 1 && estat_Robb == 0)
            {
                exit(2);
            }
            // Apunyalat | Apunyalat
            if (estat_Ned == 1 && estat_Robb == 1)
            {
                exit(3);
            }
        }
        else
        {
            int estat_Robb = generar_random();
            char *msg;
            if (estat_Robb == 0)
            {
                msg = "decapitat";
            }
            else
            {
                msg = "apunyalat";
            }
            pid_1 = getpid();
            printf("\n Hola sóc en Robb Stark amb pid = %d, soc un fill del matrimoni de la Catelyn Stark i Ned Stark", pid_1);
            printf("\nSoc en Robb amb pid = %d i he estat %s.", getpid(), msg);
            fflush(stdout);
            exit(estat_Robb);
        }
    }
}