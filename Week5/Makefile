all: game pokemon

pokedex/pokedex.o: pokedex/pokedex.c 
	gcc -c pokedex/pokedex.c -o pokedex/pokedex.o

pokedex/pokemon.o: pokedex/pokemon.c
	gcc -c pokedex/pokemon.c -o pokedex/pokemon.o

game: game.o pokedex/pokedex.o pokedex/pokemon.o
	gcc game.o pokedex/pokemon.o pokedex/pokedex.o -o game

pokemon: pokemon.o
	gcc pokemon.o -o pokemon

pokemon.o: pokemon.c
	gcc -c pokemon.c

game.o: game.c
	gcc -c game.c

clean:
	/bin/rm -r *.o ./pokedex/*.o game pokemon

execute:
	./game