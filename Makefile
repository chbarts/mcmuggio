CC=gcc
CFLAGS=-O3 -march=native
OBJ=mcmuggio.o unmuggio.o

all: mcmuggio unmuggio

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

mcmuggio: mcmuggio.o
	$(CC) mcmuggio.o -o mcmuggio

unmuggio: unmuggio.o
	$(CC) unmuggio.o -o unmuggio

clean:
	rm mcmuggio unmuggio $(OBJ)
