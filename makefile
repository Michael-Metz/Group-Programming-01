#followed this make file tutorial
#http://mrbook.org/blog/tutorials/make/

#variable for the compiler
CC = g++

CFLAGS = -c

all: driver

driver: driver.o NoSuchElementException.o Queue.o Stack.o
	$(CC) driver.o NoSuchElementException.o Queue.o Stack.o -o main

driver.o:
	$(CC) $(CFLAGS) driver.cpp

NoSuchElementException.o:
	$(CC) $(CFLAGS) NoSuchElementException.cpp
Queue.o:
	$(CC) $(CFLAGS) Queue.cpp
Stack.o:
	$(CC) $(CFLAGS) Stack.cpp

clean:
	rm *.o main

#clean and then compile
refresh: clean all
