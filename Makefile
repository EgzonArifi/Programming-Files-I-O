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

all:signals

signals: signals.o
	gcc -o signals signals.o

signals.o: signals.c
	gcc $(CFLAGS) signals.c

all:pipe

pipe: pipe.o
	gcc -o pipe pipe.o

pipe.o: pipe.c
	gcc $(CFLAGS) pipe.c

clean:
	rm -f *.o test