#Makefile

CFLAGS = -c -ansi -g



all: signal1
signal1: signal1.o
	gcc -o signal1 signal1.o

signal1.o: signal1.c
	gcc $(CFLAGS) signal1.c

all: signal1

all: signal2
signal2: signal2.o
	gcc -o signal2 signal2.o

signal2.o: signal2.c
	gcc $(CFLAGS) signal2.c

all: signal2

clean:
	rm -f *.o signal1