#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"

struct pokemon{
    int pokemon_id;
    char *name;
    double height;
    double weight;
};

typedef struct pokemon *Pokemon;

Pokemon create_pokemon();

Pokemon new_pokemon(int pokemon_id, char *name, double height, double weight)
{
    Pokemon pokemon = malloc(sizeof(struct pokemon));
    pokemon -> pokemon_id = pokemon_id;
    pokemon -> name = name;
    pokemon -> height = height;
    pokemon -> weight = weight;

    return pokemon;
};

int pokemon_id(Pokemon pokemon)
{
    return pokemon->pokemon_id;
};

char *pokemon_name(Pokemon pokemon)
{
    return pokemon->name;
};

double pokemon_height(Pokemon pokemon)
{
    return pokemon->height;
};

double pokemon_weight(Pokemon pokemon)
{
    return pokemon->weight;
};

/*


add_pokemon(char *line)
{
}

show_pokemon(int position)
{
}
*/