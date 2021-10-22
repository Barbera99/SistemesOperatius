#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pokedex.h"
#include "pokemon.h"
#include <string.h>
#define MAX_POKEMON 10

Pokemon pokemons[MAX_POKEMON];

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
            info = strtok(NULL, ",");
            char *name = info;
            printf("%s ", name);
            info = strtok(NULL, ",");
            double height = atof(info);
            printf("%lf ", height);
            info = strtok(NULL, ",");
            double weight = atof(info);
            printf("%lf \n", weight);
            Pokemon p = new_pokemon(id, name, height, weight);
            pokemons[i] = p;
            i++;
        }
    }
    fclose(f);

    return EXIT_SUCCESS;
}

int add_pokemon(int id, char *name, double weight, double height)
{
    // Indiquem el nom del fitxer a inserir les dades
    char *nombreArchivo;
    
    // Amb el sprintf assignem la quantitat de memòria que ha de reservar.
    sprintf(nombreArchivo, "pokedex.csv");

    // a es para añadir al existente
    char *modo;
    // Amb el sprintf assignem la quantitat de memòria que ha de reservar.
    sprintf(modo, "a");

    /* File pointer to hold reference of input file */
    FILE *archivo = fopen("./pokedex.csv", "a");

    // Escrivint el contingut indicant el fitxer i el contingut a escriure.
    fprintf(archivo, "%d,%s,%d,%d", id, name, weight, height);

    /* Done with file, hence close file. */
    fclose(archivo);

    return EXIT_SUCCESS;
}

int show_pokemon(int pos)
{
    Pokemon p = pokemons[pos];
    printf("id: %d \n", pokemon_id(p));
    printf("name: %s \n", pokemon_name(p));
    printf("weight: %lf \n", pokemon_weight(p));
    printf("height: %lf \n", pokemon_height(p));
    return EXIT_SUCCESS;
}
/*
int remove_pokemon(int id_pokemon)
{
    printf("he accedit al remove");
    for (int i = 0; i < sizeof(pokemons); i++)
    {
        if (pokemon_id(pokemons[i]) == id_pokemon)
        {
            for (int j = i; j < sizeof(pokemons); j++)
            {
                pokemons[i] = pokemons[j + 1];
            }
        }
        else
        {
            printf("Pokemon not found");
        }
    }
    return EXIT_SUCCESS;
}
*/
