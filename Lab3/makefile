CC=gcc
CFLAGS=-Wall

.PHONY: all test clean

all: lab3

lab3: lab3.o to_char.o to_morse.o
	$(CC) $(CFLAGS) lab3.o to_char.o to_morse.o -o lab3
	
lab3.o: lab3.c
	$(CC) $(CFLAGS) -c lab3.c -o lab3.o
	
to_char.o: to_char.c
	$(CC) $(CFLAGS) -c to_char.c -o to_char.o
	
to_morse.o: to_morse.c
	$(CC) $(CFLAGS) -c to_morse.c -o to_morse.o
	
test: lab3 input.txt output.txt
	echo ".... . .-.. .-.. ---  .-- --- .-. .-.. -.." | ./lab3 char > temp_output.txt;
	act=$$(cat temp_output.txt); \
	exp=$$(cat output.txt); \
	if [ "$$act" = "$$exp" ]; then \
		echo "Test passed"; \
	else \
		echo "Test failed. Exp: $$exp, got $$act"; \
	fi; \

clean:
	rm -f lab3 lab3.o to_char.o to_morse.o

