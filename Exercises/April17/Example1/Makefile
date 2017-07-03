#Makefile

CFLAGS = -c -ansi -g


all:detyre1

detyre1: detyre1.o
	gcc -o detyre1 detyre1.o

detyre1.o: detyre1.c
	gcc $(CFLAGS) detyre1.c

clean:
	rm -f *.o detyre1
