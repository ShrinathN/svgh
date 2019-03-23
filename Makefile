CC=gcc
CFLAGS=--static -Wall

all: vectorgenerator

vectorgenerator: vectorgenerator.o

vectorgenerator.o: vectorgenerator.c

clean:
	rm vectorgenerator *.o