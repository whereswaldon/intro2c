#include <stdlib.h>

// In C, we use structures to bundle data together. Structures are like objects in the sense that
// they have fields. We can delcare a new struct like this:

struct birthday {
    char * name;
    int day;
    int month;
    int year;
};

void make_struct() {
    // To create a birthday, we can do the following:
    struct birthday on_stack;

    // We can then access its fields with:
    on_stack.day = 30;
    on_stack.month = 7;
    on_stack.year = 2018;
    on_stack.name = "Person";

    // As its name attempts to demonstrate, we have allocated this struct on the stack.
    // It is not safe to return it from this function. To make a struct on the heap, we
    // use our good friend malloc.
    struct birthday *on_heap = (struct birthday *) malloc(sizeof(struct birthday));

    // When you have a pointer to a struct, accessing and modifying its fields gets weird.
    // You need to dereference the pointer (so that you're accessing the struct itself,
    // not its address), and then use dot notation to access a specific field.
    (*on_heap).day = 1;
    (*on_heap).month = 1;
    (*on_heap).year = 1970;
    (*on_heap).name = "Epoch";

    // Fortunately, C provides a nicer syntax that automatically dereferences the pointer:
    on_heap->day = 25;
    on_heap->month = 8;
    on_heap->year = 1991;
    on_heap->name = "Kernel";

    // Of course, we can get rid of our allocated memory the usual way:
    free(on_heap);
}

// It is a C convention to write functions that operate on structs so that they accept a struct
// pointer as their first parameter. This is essentially how you write methods in C.
void inc_year(struct birthday *bday) {
    bday->year++;
}

// Of course, everyone tires of writing "struct birthday" all over the place, so C provides a
// convenient syntax for shortening the type's name.
typedef struct birthday birthday_t;

// You can even create constructors in C:
birthday_t * new_birthday() {
    birthday_t * bday = (birthday_t *) malloc(sizeof(birthday_t));
    bday->day = 0;
    bday->month = 0;
    bday->year = 0;
    bday->name = "";
    return bday;
}

// Challenge: write a new C file (yes, from scratch) that declares a struct of your own design.
// Write a function that accepts no arguments and creates a new instance of your struct on the heap
// (returning a pointer to it).
// Write a function that modifies the data in a struct that is passed in as a pointer.
// Write a function that pretty-prints your struct.
// Write a main function to test it all out.
// Ideas for your struct:
    // data about a car
    // data about a book
    // data about a character in an RPG
