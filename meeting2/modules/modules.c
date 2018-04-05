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

// Let's see this in action. In this directory, there exists a `game.c` and a `room.h`
// file. `game.c` implements a text-based game using a room struct defined in `room.h`.
// `room.h` provides prototypes for a number of functions that operate on the room
// struct. Your job is to implement a `room.c` file that implements those functions.
