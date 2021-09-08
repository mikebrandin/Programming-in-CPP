CC = g++

INCLUDE = -I.

CFLAGS = -g -Wall -std=c++11

LDFLAGS = -L. -L/usr/lib

LDLIBS = -lc -lm

.cpp.o:
	$(CC) $(INCLUDE) $(CFLAGS) -c -o $@ $<

all: main

main: pgm.o main.o main.cpp
	$(CC) -o $@ $@.o pgm.o $(LDFLAGS) $(LDLIBS)

main.o: main.cpp
pgm.o: pgm.cpp

clean:
	rm -f *.o
	rm -rf main
	rm -rf gray.pgm copy.pgm
