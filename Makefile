all: FIFO.o MessageQueue.o SharedMemory.o Semaphore.o

test: FIFO_TEST 

#
# all
#

FIFO.o: src/FIFO.cpp src/FIFO.h
	g++ -c -o bin/FIFO.o src/FIFO.cpp

MessageQueue.o: src/MessageQueue.cpp src/MessageQueue.h
	g++ -c -o bin/MessageQueue.o src/MessageQueue.cpp

SharedMemory.o: src/SharedMemory.cpp src/SharedMemory.h
	g++ -c -o bin/SharedMemory.o src/SharedMemory.cpp

Semaphore.o: src/Semaphore.cpp src/Semaphore.h
	g++ -c -o bin/Semaphore.o src/Semaphore.cpp

#
# tests
#

FIFO_TEST: FIFO.o
	g++ -o bin/FIFO bin/FIFO.o

MessageQueue_TEST: MessageQueue.o
	g++ -o bin/MessageQueue bin/MessageQueue.o
