CC = c99
CFLAGS = -pedantic -Wall -Wextra -g

first-all: first first.o first.s first.E

first: first.o
	$(CC) $(CFLAGS) -o first first.o
	
first.o: first.c
	$(CC) $(CFLAGS) -c first.c
	
first.s: first.c
	$(CC) $(CFLAGS) -S first.c
	
first.E: first.c
	$(CC) $(CFLAGS) -o first.E -E first.c

clean:
	rm *.o *.s *.E first


