#Makefile

CFLAGS = -c -ansi -g


all:arkivo

arkivo: arkivo.o
	gcc -o arkivo arkivo.o

arkivo.o: arkivo.c
	gcc $(CFLAGS) arkivo.c

clean:
	rm -f *.o arkivo
