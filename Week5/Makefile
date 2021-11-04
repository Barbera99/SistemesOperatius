game: game.o
	gcc game.o -o game

game.o: game.c
	gcc -c pokedex.c
	gcc -c game.c 
	gcc -c pokemon.c

clean:
	/bin/rm -rf *.o game
execute:
	./game