#include <stdio.h>

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Cách 1: Dùng phép chia dư (%)
    if (n % 8 == 0) {
        printf("%d is a multiple of 8 (checked by modulus).\n", n);
    } else {
        printf("%d is NOT a multiple of 8 (checked by modulus).\n", n);
    }

    // Cách 2: Dùng phép toán bit (&)
    if ((n & 0x7) == 0) {  // 0x7 = 00000111b
        printf("%d is a multiple of 8 (checked by bitwise AND).\n", n);
    } else {
        printf("%d is NOT a multiple of 8 (checked by bitwise AND).\n", n);
    }

    return 0;
}
