#Makefile

CFLAGS = -c -ansi -g



all: sharedm1
sharedm1: sharedm1.o
	gcc -o sharedm1 sharedm1.o

sharedm1.o: sharedm1.c
	gcc $(CFLAGS) sharedm1.c


all: sharedm2
sharedm2: sharedm2.o
	gcc -o sharedm2 sharedm2.o

sharedm2.o: sharedm2.c
	gcc $(CFLAGS) sharedm2.c

all: sharedm2

clean:
	rm -f *.o sharedm1