// So far, we've only ever worked directly with a single source code file.
// You may have observed some annoying constraints from that:
    // 1. You have to put unrelated logic in the same file, which is kinda gross
    // 2. You can only use things after you define them, which can make it difficult to write functions that use one another.

// demonstrating problem #2 is easy:

int is_even(int input) {
    if (input == 0) {
        return 1;
    }
    return is_odd(input - 1);
}

int is_odd(int input) {
    return is_even(input - 1);
}

// This isn't really idiomatic C (it's more of a functional programming paradigm), but it
// does demonstrate the problem well. No matter which order we define these functions in,
// the compiler will be unhappy because we're using them without defining them.
// It isn't terribly uncommon to have a variant of this structure occur in your
// code unintentionally. How do we resolve this?

// C has a construct called a "prototype". It tells the compiler enough information about
// a method that the compiler can check whether you're using it correctly, but it doesn't
// completely define that method. The prototypes for those methods would be:

int is_even(int input); // even the word "input" is optional, the compiler
                        // just needs to know the type of the parameter
int is_odd(int input);

// If you move those two prototypes above the definitions of those functions, this file
// should compile without warnings.

// So now a big question: What is a header file?
// We've been #including them this whole time without discussing their purpose.
// A header file is prototypes for a collection of functions, as well as the definitions
// of any special types that they use. Headers typically declare structs and the
// prototypes of functions that operate on them (methods). When we include stdio.h,
// we are importing prototypes for functions like `printf` so that the compiler
// knows their arguments and return types.

// We can define our own header files. They simply include the prototypes for all of the
// functions that we define (as well as the type definitions for any types that those
//                           functions use).

// NOTE: Given that we have only used standard library header files before,
// you'll notice something strange. Standard library headers are included
// with <> symbols:
#include <stdio.h>
// But custom headers are included with double quotes:
#include "room.h"
// The double quotes indicate to the compiler that the header is in the
// current working directory.

// Let's see this in action. In this directory, there exists a `game.c` and a `room.h`
// file. `game.c` implements a text-based game using a room struct defined in `room.h`.
// `room.h` provides prototypes for a number of functions that operate on the room
// struct. Your job is to implement a `room.c` file that implements those functions.

// In order to do that, you'll need to compile your C files separately and then combine
// them into an executable.
// C has these files called object files that are contain already-compiled
// code. We can combine object files in a process called "linking" to produce
// a program. When you only have one source code file, this process is
// unnecessary, but now we have to do it. To convert a single C file into
// an object file, you can do:

// $ c99 -c file.c
// This will create a file.o in the current working directory that is ready
// to be linked. Once you have several object files that you'd like to combine,
// you can run:
// $ c99 file1.o file2.o file3.o
// This will link them into a program called `a.out` that is ready to be run.
// To control the name of the output program, we can use the `-o` flag:
// $ c99 -o game game.o room.o
// The above will produce an executable called "game".

// The workshop materials include an example implementation of the room.h
// functions in object file form. You can use that to see how the game
// works with:
// $ c99 game.o example-room.o && ./a.out
