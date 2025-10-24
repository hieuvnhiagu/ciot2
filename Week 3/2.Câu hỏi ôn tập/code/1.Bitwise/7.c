#include <stdio.h>

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Check the least significant bit (LSB)
    if (n & 1) {
        printf("%d is ODD.\n", n);   // If bit 0 is 1 → odd
    } else {
        printf("%d is EVEN.\n", n);  // If bit 0 is 0 → even
    }

    return 0;
}
