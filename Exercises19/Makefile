#Makefile

CFLAGS = -c -ansi -g


all:arguments

arguments: arguments.o
	gcc -o arguments arguments.o

arguments.o: arguments.c
	gcc $(CFLAGS) arguments.c

clean:
	rm -f *.o arguments
