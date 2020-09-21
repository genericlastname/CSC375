CC=gcc
CFLAGS=-Wall -g -O2
EXE=wc

all: $(EXE)

$(EXE): main.o wc.o
	$(CC) -o $(EXE) wc.o main.o

wc.o: wc.c wc.h
	$(CC) $(CFLAGS) -c wc.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -rf *.o $(EXE)
