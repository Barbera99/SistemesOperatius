#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pokedex.c"

#define MAX_POKEMON 10

Pokemon pokemons[MAX_POKEMON];

int init_pokedex()
{
    char *buf = malloc(10);
    char info;
    FILE *f = fopen("./pokedex.csv", "r");
    int i = 0;
    while (fgets(buf, MAX_POKEMON, f) != NULL)
    {
        if ((strlen(buf) > 0) && (buf[strlen(buf) - 1] == '\n'))
        {
            buf[strlen(buf) - 1] = '\0';
            info = strtok(buf, ",");
            int id = atoi(info);
            info = strtok(buf, ",");
            char *name = info;
            info = strtok(buf, ",");
            double height = atof(info);
            info = strtok(buf, ",");
            double weigth = atof(info);

            // Un cop tot llegit realitzem la creació d'un pokemon amb les dades extretes.
            Pokemon p = new_pokemon(id, name, height, weigth);

            // Creem l'array on guardarem els diferents pokemons.
            pokemons[i] = p;
            i++;
        }
    }
}

int add_pokemon(int id, char *name, double wieght, double height)
{
    new_pokemon(id, name, wieght, height);

    return EXIT_SUCCESS;
}

int show_pokemon(int pos)
{
    Pokemon p = pokemons[pos];

    printf("id: %d \n", pokemon_id(p));
    printf("name: %s \n", pokemon_name(p));
    printf("weight: %lf \n", pokemon_weight(p));
    printf("height: %d \n", pokemon_height(p));

    return EXIT_SUCCESS;
}

int remove_pokemon()
{
    printf("[remove_pokemon]: @NOT IMPLEMENTED \n");
    return EXIT_SUCCESS;
}