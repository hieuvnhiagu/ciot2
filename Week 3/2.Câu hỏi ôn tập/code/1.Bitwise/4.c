#include <stdio.h>

int main() {
    unsigned int x = 0b00001010; // Example value (binary: 00001010)
    int n = 3;                   // Bit position to check (starting from 0)

    // Check if the n-th bit is set using bitwise AND
    if (x & (1 << n)) {
        printf("Bit %d is ON (1)\n", n);
    } else {
        printf("Bit %d is OFF (0)\n", n);
    }

    return 0;
}
