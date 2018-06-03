CFLAGS=-c -g
LDFLAGS=

all: main test_pile test_tas test_graphes test_hachage test_listes_arc

main: main.o liste_hachage.o graphes.o liste.o algo.o pile.o liste_arc.o dijkstra.o dijkstra_tas.o tas.o
	gcc  -o $@ $^ $(LDFLAGS)

test_pile: test_pile.o liste.o pile.o
	gcc  -o $@ $^ $(LDFLAGS)

test_tas: test_tas.o liste_hachage.o graphes.o liste.o algo.o pile.o liste_arc.o tas.o
	gcc  -o $@ $^ $(LDFLAGS)

test_graphes: test_graphes.o liste_hachage.o graphes.o liste.o algo.o liste_arc.o pile.o
	gcc  -o $@ $^ $(LDFLAGS)

test_hachage: test_hachage.o liste_hachage.o graphes.o liste.o algo.o liste_arc.o pile.o
	gcc  -o $@ $^ $(LDFLAGS)

test_listes_arc: test_listes_arc.o liste_hachage.o graphes.o liste.o algo.o liste_arc.o pile.o
	gcc  -o $@ $^ $(LDFLAGS)

%.o: %.c
	gcc $(CFLAGS) $<

clean :
	rm *.o main test_pile test_tas test_graphes test_hachage test_listes_arc
