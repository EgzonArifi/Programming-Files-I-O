#Makefile

CFLAGS = -c -ansi -g


all:ForkPipes

ForkPipes: ForkPipes.o
	gcc -o ForkPipes ForkPipes.o

ForkPipes.o: ForkPipes.c
	gcc $(CFLAGS) ForkPipes.c

clean:
	rm -f *.o ForkPipes
