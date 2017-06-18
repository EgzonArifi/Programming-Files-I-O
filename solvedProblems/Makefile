#Makefile

CFLAGS = -c -ansi -g


all:afati

afati: afati.o
	gcc -o afati afati.o

afati.o: afati.c
	gcc $(CFLAGS) afati.c

clean:
	rm -f *.o afati
