#include <stdio.h>

int main() {
    printf("I hereby declare that ");
    #ifndef YES
    printf("it wasn't defined");
    #else
    printf("it was defined");
    #endif
    printf(", so there!");
}
