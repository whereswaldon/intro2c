// In C, functions resemble Java methods:

/*
<return type> <function name>(<param type> <param name>, ...) {
    //body
}
*/

// The major difference is that they are not defined within classes. C does not have classes.


// Here is a function that prints a list of integers. Note that we **must** pass the length
// of the array as a parameter, otherwise we couldn't tell when our loop should stop.
#include <stdio.h>
void print_ints(int list[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d: %d\n", i, list[i]);
    }
}

// must include values.h to get the MINDOUBLE value
#include <values.h>
// Here is a function that finds the maximum of a list of doubles
double find_max_double(double input[], int length) {
    double max = MINDOUBLE;
    for (int i = 0; i < length; i++) {
        if (max < input[i]) {
            max = input[i];
        }
    }
    return max;
}

// Here's an odd function: It accepts an integer pointer and sets the integer that it points
// to equal to the value 5.
void make_5(int *in) {
    *in = 5;
}
// Because it is modifying the value at the address contained in "in", the value of whatever
// variable the calling function provided has changed. This is very different from Java. In
// Java, you can't easily pass primitive values by reference, so functions don't usually modify
// their inputs.

// Here's a function that sets every element in an array to 5.
void set_all_to_5(int input[], int length) {
    int count = 0;
    for (int *ptr = input; count < length; ptr++) {
        make_5(ptr);
        count++;
    }
}

// Challenge time. Look at chal5.c
