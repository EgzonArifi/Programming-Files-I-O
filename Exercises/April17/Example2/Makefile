#Makefile

CFLAGS = -c -ansi -g


all:detyre2

detyre2: detyre2.o
	gcc -o detyre2 detyre2.o

detyre2.o: detyre2.c
	gcc $(CFLAGS) detyre2.c

clean:
	rm -f *.o detyre2
