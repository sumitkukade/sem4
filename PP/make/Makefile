CC=gcc
CFLAGS=-I.
hellomake.o: hellomake.h
	gcc -c -o hellomake.o hellomake.c
hellofunc.o:
	gcc -c -o hellofunc.o hellofunc.c
hellomake: hellomake.o hellofunc.o
	   $(CC) -o hellomake hellomake.o hellofunc.o -I.
