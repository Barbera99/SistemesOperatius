#include "pokemon.h"
#include <stdio.h>

typedef struct
{
    int pokemon_id;
    char *name;
    double height;
    double weight;
} Pokemon;

Pokemon new_pokemon(int pokemon_id, char *name, double height, double weight)
{
    Pokemon pokemon;
    pokemon.pokemon_id = pokemon_id;
    pokemon.name = *name;
    pokemon.height = height;
    pokemon.weight = weight;

    return pokemon;
};

int pokemon_id(Pokemon pokemon)
{
    return pokemon.pokemon_id;
};

char *pokemon_name(Pokemon pokemon)
{
    return pokemon.name;
};

double pokemon_height(Pokemon pokemon)
{
    return pokemon.height;
};

double pokemon_weight(Pokemon pokemon)
{
    return pokemon.weight;
};

// Estructura del csv
// id,name,weight,height
init_pokedex()
{
int buf; 
char info;
    FILE *f = fopen("./pokedex.csv", "r");
    while (fgets(buf, 151, f) != NULL)
    {
        if ((strlen(buf) > 0) && (buf[strlen(buf) - 1] == '\n'))
            buf[strlen(buf) - 1] = '\0';
        info = strtok(buf, ",");
        int id = atoi(info);
        
    }
}

add_pokemon(char *line)
{
}

show_pokemon(int position)
{
}