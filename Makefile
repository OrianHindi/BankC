all: functions

myBank:libmyBank.so

functions:main.o myBank.o libmyBank.so
	gcc *.o -L. -lmyBank -o functions

libmyBank.so: myBank.o
	gcc -shared myBank.o -o libmyBank.so

myBank.o:myBank.c myBank.h
	gcc -c -fpic myBank.c -o myBank.o

main.o: main.c myBank.h
	gcc -c main.c -o main.o

.PHONY:clean all

clean:
	rm -f *.o *.a *.so functions