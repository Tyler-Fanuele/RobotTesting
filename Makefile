CC = g++
CFLAGS = -Werror -pedantic -Wall

all: main

main : main.o
	$(CC) $(CFLAGS) -o main main.o -lrtde

main.o : main.cpp
	$(CC) $(CFLAGS) -c  main.cpp

clean:
	rm -f *.o main