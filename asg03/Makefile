CC = g++

INCLUDE = -I.

CFLAGS = -g -Wall -std=c++11

LDFLAGS = -L. -L/usr/lib

LDLIBS = -lc -lm

.cpp.o:
	$(CC) $(INCLUDE) $(CFLAGS) -c -o $@ $<

OBJS = \
ppm.o \
pgm.o

all: main

main: main.o main.cpp $(OBJS)
	$(CC) $(CFLAGS) -o $@ $@.o $(OBJS) $(LDFLAGS) $(LDLIBS)

main.o: main.cpp
pgm.o: pgm.cpp
ppm.o: ppm.cpp

clean:
	rm -f *.o
	rm -rf main
	rm -rf copy.pgm
