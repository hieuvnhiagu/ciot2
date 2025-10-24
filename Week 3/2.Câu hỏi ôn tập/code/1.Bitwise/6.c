#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(unsigned int n) {
    // A number is a power of 2 if:
    // 1. It is not zero
    // 2. n & (n - 1) equals 0
    return (n != 0) && ((n & (n - 1)) == 0);
}

int main() {
    unsigned int n;

    printf("Enter a number: ");
    scanf("%u", &n);

    if (isPowerOfTwo(n)) {
        printf("%u is a power of 2.\n", n);
    } else {
        printf("%u is NOT a power of 2.\n", n);
    }

    return 0;
}
