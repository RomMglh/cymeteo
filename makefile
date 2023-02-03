all: Meteo

avl.o:		avl.c avl.h
			gcc -c avl.c -o avl.o

main.o:		main.c avl.h
			gcc -c menu.c -o menu.o

Meteo: 		 main.o avl.o
		gcc main.o avl.o -o Meteo
