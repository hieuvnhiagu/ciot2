#include <stdio.h>

int main() {
    int a = 5;  // first number
    int b = 10; // second number

    printf("Before swap: a = %d, b = %d\n", a, b);

    // XOR swap algorithm
    a ^= b;  // Step 1: a = a ^ b
    b ^= a;  // Step 2: b = b ^ a (now b = original a)
    a ^= b;  // Step 3: a = a ^ b (now a = original b)

    printf("After swap:  a = %d, b = %d\n", a, b);

    return 0;
}
