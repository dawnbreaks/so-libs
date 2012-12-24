all: FIFO.o

test: FIFO_TEST

FIFO.o: src/FIFO.cpp src/FIFO.h
	g++ -c -o bin/FIFO.o src/FIFO.cpp

FIFO_TEST: FIFO.o
	g++ -o bin/FIFO bin/FIFO.o
