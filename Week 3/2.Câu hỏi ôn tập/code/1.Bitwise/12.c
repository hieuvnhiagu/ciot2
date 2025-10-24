#include <stdio.h>

int main() {
    unsigned int x = 44; // Example: 44 = 101100b

    printf("Before: %u (binary: 101100)\n", x);

    x = x & (x - 1); // Turn off the rightmost set bit

    printf("After:  %u (binary: 101000)\n", x);

    return 0;
}
