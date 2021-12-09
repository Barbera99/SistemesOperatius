#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "pokemon.h"
typedef struct pokemon *Pokemon;

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
    pokemon->type = malloc(2 * sizeof(char *));
    pokemon->type[0] = strdup(type[0]);
    pokemon->type[1] = strdup(type[1]);
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

int pokemon_id(Pokemon pokemon)
{
    return pokemon->id;
}
char *pokemon_name(Pokemon pokemon)
{
    return pokemon->name;
}
char **pokemon_type(Pokemon pokemon){
    return pokemon->type;
}
int pokemon_total(Pokemon pokemon)
{
    return pokemon->total;
}
int pokemon_hp(Pokemon pokemon)
{
    return pokemon->hp;
}
int pokemon_attack(Pokemon pokemon)
{
    return pokemon->attack;
}
int pokemon_defense(Pokemon pokemon)
{
    return pokemon->defense;
}
int pokemon_spAttack(Pokemon pokemon)
{
    return pokemon->spAttack;
}
int pokemon_spDefense(Pokemon pokemon)
{
    return pokemon->spDefense;
}
int pokemon_speed(Pokemon pokemon)
{
    return pokemon->speed;
}
int pokemon_gen(Pokemon pokemon)
{
    return pokemon->generation;
}
int pokemon_legendary(Pokemon pokemon)
{
    return pokemon->legendary;
}
int pokemon_seen(Pokemon pokemon){
    return pokemon->seen;
}
int pokemon_captured(Pokemon pokemon){
    return pokemon->captured;
}
  
void incSeen(Pokemon pokemon){
    pokemon->seen = pokemon->seen +1;
}

void incCaptured(Pokemon pokemon){
    pokemon->captured = pokemon->captured + 1;    
}