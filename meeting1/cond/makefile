CC = c99
CFLAGS = -pedantic -Wall -Wextra -g

cond-all: cond.E cond

cond.E: cond.c
	$(CC) $(CFLAGS) -o cond.E -E cond.c

cond: cond.c
	$(CC) $(CFLAGS) -o cond cond.c
	
clean:
	rm *.E cond


