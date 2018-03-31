#include <stdio.h>
#include <string.h>
// So... we've talked about all of the types, but we haven't see Strings yet. What's up with that?
// In C, there is no string type. None whatsoever. A string is a null-terminated character array.
// This means that a string is a bunch of chars that ends with a char containing the value `0`.
// The compiler does allow us to declare strings in a human-readable way though:
void str_demo() {
    char *s = "this is a string in C";
    char s2[] = "note that we can also declare it like an array";

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
    strcpy(big, s); // copy s into big
    strcat(big, s2); // concatenate s2 to the end of our new copy of s
    // big now contains s concatenated with s2.

    // NOTE: we CANNOT return big to another function. The storage space for the big array is
    // part of the current function's stack, and it will be overwritten by subsequent function
    // calls once it returns.
    // In this case, how can we possibly return strings (and other arrays) from a function?
    // We need to learn a bit about how C memory is managed.
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
    // Well cool, we have some space on the heap! We can return that and then never worry about it
    // again, right?
    // ...
    // C doesn't have a garbage collector. That means that memory, once allocated to something,
    // stays allocated until the programmer says otherwise.
    // Our newly allocated 128 bytes will belong to our program forever if we don't get rid
    // of them when we're finished with them.
    return new_space;
}

void destroy_str(char *victim) {
    // So how do we give the memory back to the operating system? There's another function
    // that does that. It's called "free".
    free(victim);
    // Bam, all of the memory in victim has been returned to the OS and to other programs
    // running on the system.
    // Unless, of course, the char* that was passed in wasn't allocated with malloc. If it was
    // a pointer to a char on the stack, undefined behavior occurs. If free was already called
    // on that pointer, undefined behavior occurs.

    // The moral of the story? Be careful to free memory that you allocate, but be EXTRA careful
    // not to free memory twice or to free memory that you didn't allocate on the heap.
}

// Okay, time for a string manipulation challenge! See chal6.c
