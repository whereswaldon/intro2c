// for printf
#include <stdio.h>
// for string helpers
#include <string.h>
#include <strings.h>
// for malloc and free
#include <stdlib.h>

// for help, see:
    // - `man 3 malloc`
    // - `man 3 string`
    // - `man 3 printf`

// to compile this file:
    // gcc -o chal6 chal6.c

// to execute this code:
    // ./chal6


// This function should accept two strings, copy the first one, and then
// concatenate the second to the end of the copy. Then it should return
// the new string
char * cat_with_dup(char *first, char *second) {
    // TODO: First, make a new char[] that is big enough to hold the contents of both strings.
    // Make sure that the new array is allocated on the heap so that it's safe to return!
    // hint: there is a string function that returns the length of a string (but does not
    // account for a terminating null byte, you should account for that byte yourself)

    // TODO: Then, copy first into the new char[]
    // hint: there might be a string function for this too ;P

    // TODO: Then, concatenate second onto first
    // hint: see previous hint
}

int main() {
    char *a = "In the beginning";
    char *b = " there was a byte.";
    char *c = cat_with_dup(a, b);
    printf("%s", c);
    // TODO: free all allocated memory
}
