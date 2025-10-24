#include <stdio.h>

int main() {
    int n = 5; 

    int twosComplement = (~n) + 1; // Two's complement calculation

    printf("Number: %d\n", n);
    printf("Two's complement: %d\n", twosComplement);

    return 0;
}
