// for printf
#include <stdio.h>
// for malloc and free
#include <stdlib.h>

// for help, see:
    // - `man 3 malloc`
    // - `man 3 printf`

// to compile this file:
    // gcc -o chal_mem chal_mem.c

// to execute this code:
    // ./chal_mem

#define LENGTH 25

// fib should create an array of ints (on the heap) with the specified length.
// It should then fill out the array with fibonacci numbers until it reaches
// the end of the array. Then it should return the array.
// Effectively, it returns the first "length" fibonacci numbers.
int * fib(int length) {
	// TODO
}

int main() {
	int * results = fib(LENGTH);
	for (int i = 0; i < LENGTH; i++) {
    		printf("results[%d] = %d\n", i, results[i]);
	}
    // TODO: free all allocated memory
}
