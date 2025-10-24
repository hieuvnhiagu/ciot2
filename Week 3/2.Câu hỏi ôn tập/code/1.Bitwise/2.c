#include <stdio.h>

int main() {
    unsigned int x = 0b11101111; // Example: 239 (binary: 11101111)
    int n = 4;                   // Bit position to clear (counting from 0)

    printf("Before: %u (binary: 11101111)\n", x);

    x = x & ~(1 << n); // Clear the n-th bit

    printf("After:  %u (binary: 11100111)\n", x);

    return 0;
}
