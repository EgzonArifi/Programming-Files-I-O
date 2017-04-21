#Makefile

CFLAGS = -c -ansi -g



all: messageQ1
messageQ1: messageQ1.o
	gcc -o messageQ1 messageQ1.o

messageQ1.o: messageQ1.c
	gcc $(CFLAGS) messageQ1.c

all: messageQ2

messageQ2: messageQ2.o
	gcc -o messageQ2 messageQ2.o

messageQ2.o: messageQ2.c
	gcc $(CFLAGS) messageQ2.c

all: messageQ2

clean:
	rm -f *.o messageQ2