#Makefile

CFLAGS = -c -ansi -g



all: test
test: test.o
	gcc -o test test.o

test.o: test.c
	gcc $(CFLAGS) test.c

clean:
	rm -f *.o test