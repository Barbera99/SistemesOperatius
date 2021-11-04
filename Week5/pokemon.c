#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "pokedex.c"

#define RUNNINGDIR "./"
#define LOGFILE RUNNINGDIR "log.txt"

enum accions
{
    pokemonEscaped = 7,
    pokemonCaptured = 2
};

void logger(char *missatge)
{

    time_t actual_time;
    time(&actual_time);

    FILE *f = fopen(LOGFILE, "a");

    fprintf(f, "%s: %s \n", ctime(&actual_time), missatge);
    fclose(f);
}

void tractament_2()
{

    exit(0);
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
    if (num == pokemonEscaped)
    {
        exit(pokemonEscaped);
    }
    else if (num == pokemonCaptured)
    {
        exit(pokemonCaptured);
    }
    else{
        kill(getpid(),SIGSTOP);
    }
}

int main()
{
    srand(getpid());
    signal(SIGUSR1, tractament);
    signal(SIGINT, SIG_IGN);
    while (true)
    {
    }
}