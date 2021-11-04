#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define N_POKEMONS 151

typedef struct pokemon *Pokemon;
Pokemon pokemons[N_POKEMONS];

struct pokemon
{
    int id;
    char *name;
    char **type;
    int total;
    int hp;
    int attack;
    int defense;
    int spAttack;
    int spDefense;
    int speed;
    int generation;
    int legendary;
    int seen;
    int captured;
};

Pokemon new_pokemon(int id, char *name, char **type, int total, int hp, int attack, int defense, int spAttack, int spDefense, int speed, int generation, int legendary, int seen, int captured)
{
    Pokemon pokemon = malloc(sizeof(struct pokemon));
    pokemon->id = id;
    pokemon->name = strdup(name); //Serveix per guardar el valor en una altra adreça de memòria i d'aquesta manera no anar sobreescrivint el nom tot el rato.
    pokemon->type[0] = strdup(type);
    pokemon->type[1] = strdup(type);
    pokemon->total = total;
    pokemon->hp = hp;
    pokemon->attack = attack;
    pokemon->defense = defense;
    pokemon->spAttack = spAttack;
    pokemon->spDefense = spDefense;
    pokemon->speed = speed;
    pokemon->generation = generation;
    pokemon->legendary = legendary;
    pokemon->seen = seen;
    pokemon->captured = captured;

    return pokemon;
}

char *info;
int init_pokedex()
{
    int i = 0;
    char *buf = malloc(100);
    FILE *f = fopen("./pokedex.csv", "r");
    while (fgets(buf, 100, f) != NULL)
    {
        if ((strlen(buf) > 0) && (buf[strlen(buf) - 1] == '\n'))
        {
            info = strtok(buf, ",");
            int id = atoi(info);
            printf("%d ", id);

            char name;
            info = strtok(NULL, ",");
            strcpy(name, info);
            printf("%s ", name);

            char **type;
            type = malloc(2);
            type[0] = malloc(32);
            type[1] = malloc(32);
            info = strtok(NULL, ",");
            strcpy(type[0], info);
            printf("%s ", type[0]);

            info = strtok(NULL, ",");
            strcpy(type[1], info);
            printf("%s ", type[1]);

            info = strtok(NULL, ",");
            int total = atoi(info);
            printf("%d ", total);

            info = strtok(NULL, ",");
            int hp = atoi(info);
            printf("%d ", hp);

            info = strtok(NULL, ",");
            int attack = atoi(info);
            printf("%d ", attack);

            info = strtok(NULL, ",");
            int defense = atoi(info);
            printf("%d ", defense);

            info = strtok(NULL, ",");
            int spAttack = atoi(info);
            printf("%d ", spAttack);

            info = strtok(NULL, ",");
            int spDefense = atoi(info);
            printf("%d ", spDefense);

            info = strtok(NULL, ",");
            int speed = atoi(info);
            printf("%d ", speed);

            info = strtok(NULL, ",");
            int generation = atoi(info);
            printf("%d ", generation);

            info = strtok(NULL, ",");
            int legendary = atoi(info);
            printf("%d ", legendary);

            info = strtok(NULL, ",");
            int seen = atoi(info);
            printf("%d ", seen);

            info = strtok(NULL, ",");
            int captured = atoi(info);
            printf("%d ", captured);

            Pokemon p = new_pokemon(id, name, type, total, hp, attack, defense, spAttack, spDefense, speed, generation, legendary, seen, captured);
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
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@");
    printf("\n%s (%d)", p->name, p->id);
    printf("\n+++ Type1: %s, Type2: %s", p->type[0], p->type[1]);
    printf("\n+++ Attack: %s, Defense: %s", p->attack, p->defense);
    printf("\n+++ spAttack: %s, spDefense: %s, Speed: %s", p->spAttack, p->spDefense, p->speed);
    printf("\n+++ Gen: %s, Legendary: %s", p->generation, p->legendary);
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@%s");

    return EXIT_SUCCESS;
}
