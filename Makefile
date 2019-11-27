CC=gcc
FLAGS= -Wall -g
all: functions

myBank:libmyBank.so

functions:main.o myBank.o libmyBank.so
	$(CC) $(FLAGS) *.o -L. -lmyBank -o functions

libmyBank.so: myBank.o
	$(CC) -shared myBank.o -o libmyBank.so

myBank.o:myBank.c myBank.h
	$(CC) $(FLAGS) -c -fpic myBank.c -o myBank.o

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c -o main.o

.PHONY:clean all 

clean:
	rm -f *.o  *.so functions