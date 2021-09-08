CC = gcc

INCLUDE = -I.

CFLAGS = -g

LDFLAGS = -L. -L/usr/lib

LDLIBS = -lc -lm

.c.o:
	$(CC) $(INCLUDE) $(CFLAGS) -c -o $@ $<

all: pgmtest ppmtest

pgmtest: pgm.o pgmtest.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

ppmtest: ppm.o ppmtest.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

pgmtest.o: pgmtest.c
ppmtest.o: ppmtest.c
pgm.o: pgm.c pgm.h
ppm.o: ppm.c ppm.h

clean:
	rm -f *.o
	rm -rf pgmtest ppmtest
