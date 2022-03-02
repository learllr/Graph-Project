# ----- make all -----

all: bin/main bin/mainTest


# ----- Les exécutables -----

bin/main: obj/main.o obj/Graphe.o
	g++ -g -W -Wall obj/main.o obj/Graphe.o -o bin/main

bin/mainTest: obj/mainTest.o obj/Graphe.o
	g++ -g -W -Wall obj/mainTest.o obj/Graphe.o -o bin/mainTest


# ----- Les fichiers obj -----

obj/main.o: src/main.cpp src/Graphe.h src/Graphe.cpp
	g++ -g -W -Wall -c src/main.cpp -o obj/main.o

obj/mainTest.o: src/mainTest.cpp src/Graphe.h src/Graphe.cpp
	g++ -g -W -Wall -c src/mainTest.cpp -o obj/mainTest.o
	
obj/Graphe.o: src/Graphe.h src/Graphe.cpp
	g++ -g -W -Wall -c src/Graphe.cpp -o obj/Graphe.o


# ----- Nettoyage -----

cleanObj:
	rm obj/*

cleanBin:
	rm bin/*

veryclean: 
	rm obj/*
	rm bin/*
