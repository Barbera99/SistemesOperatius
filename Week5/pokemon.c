#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define RUNNINGDIR "./"
#define LOGFILE RUNNINGDIR "log.txt"

#define MAX_BERRIES 3
int berries = 0;

enum accions
{
    pokemonEscaped = 7
};

void logger(char *missatge)
{

    time_t actual_time;
    time(&actual_time);

    FILE *f = fopen(LOGFILE, "a");

    fprintf(f, "%s: %s \n", ctime(&actual_time), missatge);
    fclose(f);
}

int getRandom()
{
    return rand() % 10;
}

void tractament()
{
    int num = getRandom();
    char log[100];
    sprintf(log, "El valor del num:%d\n", num);
    logger(log);

    for (int i = 0; i <= berries; i++)
    {
        if (num == 2 + (i * 2))
        {
            exit(2);
        }
    }
    if (num == pokemonEscaped)
    {
        exit(7);
    }
    else
    {
        kill(getpid(), SIGSTOP);
    }
}

void berry()
{
    if (berries != MAX_BERRIES)
    {
        berries++;
        //exit(berries);
    }
    /*
    else if (berries == MAX_BERRIES)
    {
        exit(berries);
    }
    */
}

int main()
{
    srand(getpid());
    signal(SIGUSR1, tractament);
    signal(SIGUSR2, berry);
    while (true)
    {
    }
}