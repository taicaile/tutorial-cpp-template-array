
CC = g++
CFLAGS = -Wall -g

all: main.o MyArray.o
	$(CC) $(CFLAGS) -o main main.o MyArray.o
	./main

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

MyArray.o: MyArray.hpp
	$(CC) $(CFLAGS) -c MyArray.hpp -o MyArray.o

clean:
	rm -f *.o  main
