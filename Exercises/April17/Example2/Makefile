#Makefile

CFLAGS = -c -ansi -g


all:rrjeta

rrjeta: rrjeta.o
	gcc -o rrjeta rrjeta.o

rrjeta.o: rrjeta.c
	gcc $(CFLAGS) rrjeta.c

clean:
	rm -f *.o rrjeta
	rm -f *.o nyja

all:nyja

nyja: nyja.o
	gcc -o nyja nyja.o

nyja.o: nyja.c
	gcc $(CFLAGS) nyja.c