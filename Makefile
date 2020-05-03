CC=gcc
CFLAGS= -Wall -c

all: main

main: main.o
	$(CC) main.o -o main

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean: 
	rm -rf *o main
