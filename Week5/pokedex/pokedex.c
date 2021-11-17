#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include "pokemon.h"
#include "pokedex.h"
#define N_POKEMONS 151

Pokemon pokemons[N_POKEMONS];

char *info;
int init_pokedex()
{
    int i = 0;
    char *buf = malloc(100);
    FILE *f = fopen("./pokedex/pokemon.csv", "r");

    while (fgets(buf, 100, f) != NULL)
    {
        if ((strlen(buf) > 0) && (buf[strlen(buf) - 1] == '\n'))
        {
            info = strtok(buf, ",");
            int id = atoi(info);

            char *name = NULL;
            info = strtok(NULL, ",");
            name = info;

            char **type;
            type = malloc(2);

            info = strtok(NULL, ",");
            type[0] = info;
            info = strtok(NULL, ",");
            type[1] = info;

            info = strtok(NULL, ",");
            int total = atoi(info);

            info = strtok(NULL, ",");
            int hp = atoi(info);

            info = strtok(NULL, ",");
            int attack = atoi(info);

            info = strtok(NULL, ",");
            int defense = atoi(info);

            info = strtok(NULL, ",");
            int spAttack = atoi(info);

            info = strtok(NULL, ",");
            int spDefense = atoi(info);

            info = strtok(NULL, ",");
            int speed = atoi(info);

            info = strtok(NULL, ",");
            int generation = atoi(info);

            info = strtok(NULL, ",");
            int legendary = atoi(info);

            Pokemon p = new_pokemon(id, name, type, total, hp, attack, defense, spAttack, spDefense, speed, generation, legendary, 0, 0);

            pokemons[i] = p;
            i++;
        }
    }
    fclose(f);

    return EXIT_SUCCESS;
}

int show_pokemon(int pos)
{
    Pokemon p = pokemons[pos];
    char **type = pokemon_type(p);
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@");
    printf("\n%s (%d)", pokemon_name(p), pokemon_id(p));
    printf("\n+++ Type1: %s, Type2: %s", type[0], type[1]);
    printf("\n+++ Total: %d, Hp: %d", pokemon_total(p), pokemon_hp(p));
    printf("\n+++ Attack: %d, Defense: %d", pokemon_attack(p), pokemon_defense(p));
    printf("\n+++ spAttack: %d, spDefense: %d, Speed: %d", pokemon_spAttack(p), pokemon_spDefense(p));
    printf("\n+++ Gen: %d, Legendary: %d", pokemon_gen(p), pokemon_legendary(p));
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@\n");

    return EXIT_SUCCESS;
}
