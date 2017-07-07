#Makefile

CFLAGS = -c -ansi -g



all: client
client: client.o
	gcc -o client client.o

client.o: client.c
	gcc $(CFLAGS) client.c

all: client

server: server.o
	gcc -o server server.o

server.o: server.c
	gcc $(CFLAGS) server.c

all: server

clean:
	rm -f *.o server
	rm -f *.o client