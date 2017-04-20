#Makefile

CFLAGS = -c -ansi -g



all: namedPipe
namedPipe: namedPipe.o
	gcc -o namedPipe namedPipe.o

namedPipe.o: namedPipe.c
	gcc $(CFLAGS) namedPipe.c

all: secondNamedPipe

all: secondNamedPipe
secondNamedPipe: secondNamedPipe.o
	gcc -o secondNamedPipe secondNamedPipe.o

secondNamedPipe.o: secondNamedPipe.c
	gcc $(CFLAGS) secondNamedPipe.c

all: secondNamedPipe

clean:
	rm -f *.o namedPipe