#Makefile

CFLAGS = -c -ansi -g


all:myStudentsFile

myStudentsFile: myStudentsFile.o
	gcc -o myStudentsFile myStudentsFile.o

myStudentsFile.o: myStudentsFile.c
	gcc $(CFLAGS) myStudentsFile.c

clean:
	rm -f *.o myStudentsFile
