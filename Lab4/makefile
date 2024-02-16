CC=gcc
CGLAGS=-Wall

.PHONY: all clean start

all: lab4

lab4: lab4.o
	$(CC) $(CFLAGS) lab4.o -o lab4

lab4.o: lab4.c
	$(CC) $(CFLAGS) -c lab4.c -o lab4.o
	
start: lab4
	sudo ./lab4
	
clean:
	rm -f lab4 lab4.o 
