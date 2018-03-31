#include <stdio.h>

//#define YES 1

int main() {
    printf("I hereby declare that ");
    #ifndef YES
    printf("it wasn't defined");
    #else
    printf("it was defined (%d)", YES);
    #endif
    printf(", so there!");
}
