// C has a lot more types than java
char is_a_character; // often used as a "byte", since it is always 1 byte of data
short is_a_small_int; // is half of the size of an int
int gee_what_could_this_be; // ... you know
long double_the_size_of_an_int; // says it all (aka 'long int')
long long well_keep_doubling; // doubled again (aka 'long long int')
float single_precision; // this is familiar
double double_a_float; // still familiar
long double say_what; // yes, this exists. Poorly standardized

// But, of course, things are more complex than that.
// Any integer type can be 'signed' or 'unsigned'. As you know, unsigned integers
// have double the maximum value of signed integers, so in C it is good practice
// to use signed integers only when it makes sense for the value to be able to go
// negative.
signed char example; // this has the range -128 - 127
unsigned char other_example; // this has the range 0 - 255

// Other possibilities include

unsigned char usch; 
signed char sch; 
unsigned short ussh; 
signed short ssh; 
unsigned int usi; 
signed int si; 
unsigned long usl; 
signed long sl; 
unsigned long long usll; 
signed long long sll; 

// But wait, what about booleans?
// C didn't have them (as their own type) for a looooooong time.
// A more "recent" revision of the language, C99, added:
_Bool this_is_a_boolean = 1; // we just made this true

// Now, we can get a nicer version if we
#include <stdbool.h>
bool this_is_also_a_boolean = true; // thanks to the header, we have a better type name and value
// without stdbool.h, bool and true/false are undefined. Yes, you read that right.

// Historically, C has used integers for booleans. 0 is false. All other values are true.
void demo() { // yes, we have void functions!
    if (19) {
        // always
    } else {
        // never
    }
}
// Yes, if statements will still interpret any integer type as a boolean if you use it
// in a condition.

// OKAY, time for challenge 1! See chal1.c

// Arrays
void demo_arrays() {
    // You can create an array of 10 ints like so:
    int basic_array[10]; // note that the square brackets are after the variable name, not the type
    // C arrays do not know their own length (no array.length field), so you have to keep track of
    // it yourself.

    // **important** Arrays created using the above syntax cannot be returned from the function in
    // which they were created because they are allocated on the stack and destroyed when the function
    // returns. C will let you return them, but your code will suffer from catastrophic failure if you do.
    // They do work okay if defined globally, however.

    int element = basic_array[5];

    // How do we iterate through an array without knowing it's length? We can't. We need it as a
    // variable or constant;
    for (int i = 0; i < 10; i++) {
        element = basic_array[i];
    }
    // Since we know that the array is 10 elements long this is easy right now, but you have to
    // be really careful about it.
}

// OKAY, time for challenge 2! See chal2.c

// Pointers
// A pointer is like a reference variable in Java (well, references were modeled off of pointers,
// but whatever). A pointer is literally the address in memory of some value. An int pointer tells
// us where the int is in memory. A long pointer tells us where a long is in memory. How is this
// useful? Well, knowing where something is is all you need to be able to change it.
int *iptr;
int * iptr2;
int* iptr3;

// All of the above are legal syntax for delcaring pointers to ints. You can have a pointer to any
// type. Examples:
double *dptr;
unsigned short* shptr;

void demo_pointer_assignment() {
    // To initialize a pointer, we need to provide the address of the thing that it points at.
    int victim = 24; // here is an ordindary int
    int *vptr = &victim; // here is a pointer to victim
    // The & is the "address-of" operator. It gives you the address of any variable;
    int *vptr2 = vptr; // This makes vptr2 point at the same thing that vptr points at. It literally
    			// sets the value in vptr2 (the address of an int) to the value of vptr
    			// (the address of victim). 

    // So how do we use a pointer to victim to modify victim?
    *vptr += 5; // increment victim by 5
    // Using a * with a pointer (when you're not creating the pointer) is called "dereferencing"
    // the pointer. It allows you to modify the value at the address stored in the pointer, instead
    // of modifying the address (which is why this doesn't move the address 5 bytes further into
    // memory).
}

// Arrays and Pointers
// An array in C is just a pointer to the first element of the array. You can treat arrays as pointers
// and pointers as arrays. As I'm sure you can imagine, this creates some interesting possibilities.
void pointer_and_array_demo() {
    double dubs[100];
    double *dptr = dubs; // why don't we need "&"? Arrays are already pointers.

    double first = dubs[0]; // get the first element;
    first = *dubs; // get the first element by dereferencing the array (it's just a pointer)
    first = *dptr; // basically the same as the previous line
}

// Need a main function to compile
int main() {
}
