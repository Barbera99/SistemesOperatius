#ifndef _POKEMON_H_
#define _POKEMON_H_

typedef struct pokemon *Pokemon;

Pokemon create_pokemon();

Pokemon new_pokemon(int id, char *name, char **type, int total, int hp, int attack, int defense, int spAttack, int spDefense, int speed, int generation, int legendary, int seen, int captured);
int pokemon_id(Pokemon pokemon);
char *pokemon_name(Pokemon pokemon);
char **pokemon_type(Pokemon pokemon);
int pokemon_total(Pokemon pokemon);
int pokemon_hp(Pokemon pokemon);
int pokemon_attack(Pokemon pokemon);
int pokemon_defense(Pokemon pokemon);
int pokemon_spAttack(Pokemon pokemon);
int pokemon_spDefense(Pokemon pokemon);
int pokemon_speed(Pokemon pokemon);
int pokemon_gen(Pokemon pokemon);
int pokemon_legendary(Pokemon pokemon);
int pokemon_seen(Pokemon pokemon);
int pokemon_captured(Pokemon pokemon);
void incCaptured(Pokemon pokemon);
void incSeen(Pokemon pokemon);
#endif