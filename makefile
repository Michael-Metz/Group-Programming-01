#followed this make file tutorial
#http://mrbook.org/blog/tutorials/make/

#variable for the compiler
CC = g++

CFLAGS = -c

all: driver

driver: driver.o NoSuchElementException.o Queue.o
	$(CC) driver.o NoSuchElementException.o Queue.o -o main

driver.o:
	$(CC) $(CFLAGS) driver.cpp

NoSuchElementException.o:
	$(CC) $(CFLAGS) NoSuchElementException.cpp
Queue.o:
	$(CC) $(CFLAGS) Queue.cpp

clean:
	rm *.o main

#clean and then compile
refresh: clean all
