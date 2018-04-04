#include <stdio.h>

// to compile this file:
    // gcc -o chal_ptr chal_ptr.c

// to execute this code:
    // ./chal_ptr

// Make the value pointed to by c be equal to the sum of the values pointed to by a and b.
// So *c == *a + *b
void add(int *a, int *b, int *c) {
}

int main() {
    int first = 4;
    int second = 7;
    int result;
    add(&first, &second, &result);
    printf("%d + %d = %d\n", first, second, result);
} 
