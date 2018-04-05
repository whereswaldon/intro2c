#include <stdio.h>
#include <string.h>
// Okay, let's review strings in C: They don't exist.
// Well, they're just arrays of characters that end will a null byte.
// And what's the difference between an array and a pointer? Arbitrary. Arrays
// are just pointers that we know point to one of several data elements.

void str_demo() {
    char *s = "I am string";
    char s2[] = "I am string that looks like array";
    // C automatically inserts a null character at the end of these strings.

    // to iterate over all characters in the string:
    for (char *c = s; *c != 0; c++) {
        printf("%c\n", *c);
    }
    // note that we don't have to count iterations, since we can just go until we hit a character
    // with the integer value 0 (the null character).

    // since strings are just character arrays (pointers), concatenation with the + operator makes
    // no sense whatsoever (s + s2) is the sum of the addresses of those strings.

    // instead, we manipulate strings through helper functions defined in string.h and strings.h
    // to see a list of these helpers, type `man 3 string`

    // to properly concatenate C strings, we can do this:
    char big[128];
    big[0] = '\0'; // ensure that our array begins with a null byte and
    			// is therefore equivalent to the empty string
    strcpy(big, s); // copy s into big
    strcat(big, s2); // concatenate s2 to the end of our new copy of s
    // big now contains s concatenated with s2.

    // NOTE: we CANNOT return big to another function. The storage space for the big array is
    // only allocated as a local variable (on the stack) and will be invalidated the moment that
    // this function returns.
}

// we need stdlib.h for the malloc and free functions
#include <stdlib.h>

char * mem_demo() {
    // In C, we can allocate memory in two places:
        // the stack - the default
        // the heap - using special functions
    // memory allocated on the stack is safe **until** we return, but not after.
    // memory allocated on the heap is safe to use **until** we manually say otherwise.

    // So how do we allocate magic heap memory?
    char * new_space = (char *) malloc(128 * sizeof(char));
    // Okay, what the heck did we just do? Let's break it down:
        // - malloc is a function that allocated a quantity of *bytes* on the heap and
        // returns a pointer to the start of those bytes.
        // - We asked for 128 * sizeof(char) bytes, which is enough space for 128 chars.
        // - malloc will ask the operating system for 128 bytes of memory and then return
        // the address of the start of that memory to us.
        // - So why do we have to cast it? The return type of malloc is **weird**. It is
        // (void *), a pointer without a type. This is because malloc doesn't know or
        // care what you want to use the memory for. You ask for X number of bytes, and
        // it gives them to you. So it is good practice to cast the return value of
        // malloc to the pointer type that you actually want.

    // Here we can safely return this pointer, since it points to the heap.
    return new_space;
}

void destroy_str(char *victim) {
    // So how do we give the memory back to the operating system? There's another function
    // that does that. It's called "free".
    free(victim);
    // You can only free memory that was allocated with malloc.
    // You can only free a given pointer once.
    // If you violate either of the above, there's no telling what will happen.
}

void other_types() {
    // we can, of course, malloc things other than char arrays. Let's say we want an array
    // of longs
    int length = 57;
    long *arr = (long *) malloc(length * sizeof(long));

    for (int i = 0; i < length; i++) {
        arr[i] = i;
    }

    // yay, now we should be responsible and free the memory we don't need anymore:
    free(arr);
}

// Okay, challenge time. Open chal_mem.c and go from there.
