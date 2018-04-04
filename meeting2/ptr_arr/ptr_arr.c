// So first let's review pointers and arrays

void ptr_arr_demo() {
    // Let's make some data
    double weight = 3.5;

    // Pointers are a way of referencing data of a specific type. They literally are
    // the address of a piece of data in memory. Let's make some pointers.
    double * dubstep;
    double * quickstep;

    // Right now, those pointers do not point at anything, but we can make them refer
    // to any piece of data of the right type.
    // The & operator is the "address-of" operator. It takes the address of a variable
    // so that we can create a pointer to that variable.

    dubstep = &weight; // dubstep now points at weight in memory.
    // Note that the value of dubstep is not 3.5. The value is an address.
    // If we want to get the thing that the pointer references, we must *dereference*
    // the pointer. The dereference operator is "*"
    double new_one = *dubstep;

    // new_one is now equal to the double that dubstep points at, so it has the value 3.5

    // This is how we can make one pointer point at the same piece of data as another:
    quickstep = dubstep; 
    // Note that we do not need to dereference or take the address of either pointer.

    // Okay, so how are arrays different? They aren't, really. In C, an array is just a pointer
    // to the first of many pieces of data. Here's a double array:
    double data[10];
    data[0] = 3.14;
    data[3] = 11.1111;

    // But we can set our pointer to point at this array
    quickstep = data; // this is fine, because they are both pointers

    new_one = quickstep[3]; // this sets new_one equal to 11.1111
    new_one = *data; // this sets new_one equal to pi

    // The only important difference between an array and a pointer in C is that we know
    // that there are more things in the array. Arrays do not keep track of their own
    // length, so we must do that for them
}
