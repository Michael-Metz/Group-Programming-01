#followed this make file tutorial
#http://mrbook.org/blog/tutorials/make/

#variable for the compiler
CC = g++

CFLAGS = -std=c++11 -c

all: simulator calculator

calculator: StackDriver.o Stack.o
	$(CC) StackDriver.o Stack.o -o calculator

#for running the
simulator: QueueDriver.o NoSuchElementException.o Queue.o
	$(CC) QueueDriver.o NoSuchElementException.o Queue.o -o simulator

StackDriver.o:
	$(CC) $(CFLAGS) StackDriver.cpp

QueueDriver.o:
		$(CC) $(CFLAGS) QueueDriver.cpp

NoSuchElementException.o:
	$(CC) $(CFLAGS) NoSuchElementException.cpp
Queue.o:
	$(CC) $(CFLAGS) Queue.cpp
Stack.o:
	$(CC) $(CFLAGS) Stack.cpp

clean:
	rm *.o calculator simulator

#clean and then compile
refresh: clean all
