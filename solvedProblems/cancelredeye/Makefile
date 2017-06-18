#Makefile

CFLAGS = -c -ansi -g


all:cancelredeye

cancelredeye: cancelredeye.o
	gcc -o cancelredeye cancelredeye.o

cancelredeye.o: cancelredeye.c
	gcc $(CFLAGS) cancelredeye.c

clean:
	rm -f *.o cancelredeye
