#include <stdio.h>

int main() {
    unsigned int n = 40; // Example: 40 = 101000b

    unsigned int lsb = n & (-n); // Find Least Significant Bit

    printf("Number: %u\n", n);
    printf("Least Significant Bit (LSB) value: %u\n", lsb);

    return 0;
}
