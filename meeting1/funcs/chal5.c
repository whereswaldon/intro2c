#include <stdio.h>

// to compile this file:
    // gcc -o chal5 chal5.c

// to execute this code:
    // ./chal5

#define NUM_DOUBLES 6

void reverse(double input[], int length) {
    // reverse the order of the input array
    // hint: iterate until the middle of the array, swapping each element with the one at length-i
}

void print_doubles(double input[], int length) {
    // print each element in the array separated by spaces
    // hint: printf("%f ", something);
}

int main() {
    double ds[NUM_DOUBLES];
    ds[0] = 1.2;
    ds[1] = 4.0;
    ds[2] = 99.9;
    ds[3] = 78.1;
    ds[4] = 78.3;
    ds[5] = -11;
    print_doubles(ds, NUM_DOUBLES);
    reverse(ds, NUM_DOUBLES);
    print_doubles(ds, NUM_DOUBLES);
}
