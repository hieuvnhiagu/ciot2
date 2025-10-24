#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Use XOR to compare without using comparison operators
    if ((a ^ b) == 0) {
        printf("%d and %d are EQUAL.\n", a, b);
    } else {
        printf("%d and %d are NOT EQUAL.\n", a, b);
    }

    return 0;
}
