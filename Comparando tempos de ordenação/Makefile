all: main

main:	main.o utilid.o ordena.o
	gcc main.o utilid.o ordena.o -o main

main.o: main.c utilid.h ordena.h
	gcc -c main.c

utilid.o:	utilid.c utilid.h
	gcc -c utilid.c

ordena.o:	ordena.c ordena.h
	gcc -c ordena.c
