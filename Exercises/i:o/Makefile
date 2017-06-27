#Makefile

CFLAGS = -c -ansi -g


all:exampleio

exampleio: exampleio.o
	gcc -o exampleio exampleio.o

exampleio.o: exampleio.c
	gcc $(CFLAGS) exampleio.c

clean:
	rm -f *.o exampleio
