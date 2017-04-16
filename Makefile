#Makefile

CFLAGS = -c -ansi -g



all: test
test: test.o
	gcc -o test test.o

test.o: test.c
	gcc $(CFLAGS) test.c

all:studentiFile

studentiFile: studentiFile.o
	gcc -o studentiFile studentiFile.o

studentiFile.o: studentiFile.c
	gcc $(CFLAGS) studentiFile.c

clean:
	rm -f *.o test