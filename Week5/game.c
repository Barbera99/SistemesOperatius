#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include "pokemon.c"
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

char *args[] = {"pokemon", "pokemon", NULL};

int getRandomPokemon()
{
    return rand() % 151;
}

int main(int arc, char *arv[])
{
    int endFlag = 1;
    while (endFlag == 1)
    {
        int endFlag1 = 1;
        int status = 0;
        char s[100];
        char choice;
        //init_pokedex(); // Carregar fitxer CSV amb els 151 pokemons
        sprintf(s, "################\n# E. Explore \n# Q. Quit\n################\n");
        if (write(1, s, strlen(s)) < 0)
            perror("Error writting the menu");
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'Q':
            endFlag = 0;
            break;
        case 'E':;
            int num = getRandomPokemon();
            while (endFlag1 == 1)
            {
                pid_t pid = fork();
                if (pid > 0)
                {

                    char choice1;
                    //printf("%s", KCYN);
                    // show_pokemon(num);
                    // printf("%s", KNRM);
                    sprintf(s, "################\n# P. Throw Pokeball \n# B. Throw Berry \n# R. Run\n################\n");
                    if (write(1, s, strlen(s)) < 0)
                        perror("Error writting the menu");
                    scanf(" %c", &choice1);

                    switch (choice1)
                    {
                    case 'P': //THROW POKEBALL
                        kill(pid, SIGUSR1);
                        waitpid(-1, &status, WUNTRACED);
                        int estat = WEXITSTATUS(status);
                        if (estat == 2)
                        {
                            printf("Captured\n");
                            endFlag1 = 0;
                            break;
                        }
                        else if (estat == 7)
                        {
                            printf("Escaped\n");
                            endFlag1 = 0;
                            break;
                        }
                        else
                        {
                            printf("No capturat\n");
                        }
                        break;
                    case 'B': //THROW BERRY
                        
                        break;
                    case 'R': //RUN
                        kill(pid, SIGSTOP);
                        printf("Has escapat corrent\n");
                        endFlag1 = 0;
                        break;
                    default:
                        sprintf(s, "%s!!!!Invalid option. Try again. %s\n", KRED, KNRM);
                        if (write(1, s, strlen(s)) < 0)
                            perror("Error writting invalid option");
                        break;
                    }
                }
                else if (pid == 0)
                {
                    execv("./pokemon", args);
                }
            }
            break;
        default:
            sprintf(s, "%s!!!Invalid option. Try again. %s\n", KRED, KNRM);
            if (write(1, s, strlen(s)) < 0)
                perror("Error writting invalid option");
            break;
        }
    }

    char s[100];
    sprintf(s, "%s!!!!I'm tired from all the fun... %s\n", KMAG, KNRM);
    if (write(1, s, strlen(s)) < 0)
        perror("Error writting the ending msg");
    exit(0);
}