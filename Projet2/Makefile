CFLAGS=-c -g
LDFLAGS=

all: main

main: main.o liste_hachage.o graphe.o liste.o algo.o pile.o liste_arc.o dijkstra.o dijkstra_tas.o tas.o
	gcc  -o $@ $^ $(LDFLAGS)

%.o: %.c
	gcc $(CFLAGS) $<

clean :
	rm *.o main
