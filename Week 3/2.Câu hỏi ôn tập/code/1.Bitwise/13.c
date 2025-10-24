#include <stdio.h>

int main() {
    unsigned int x = 44; // Example: 44 = 101100b

    unsigned int isolated = x & (-x); // Isolate the rightmost 1-bit

    printf("Number: %u (binary: 101100)\n", x);
    printf("Isolated rightmost 1-bit value: %u\n", isolated);

    return 0;
}
