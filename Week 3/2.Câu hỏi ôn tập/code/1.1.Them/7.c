#include <stdio.h>

// Hàm cộng 2 giá trị unsigned char
unsigned char Add(unsigned char a, unsigned char b) {
    return (a + b);
}

int main() {
    unsigned char x = 200;
    unsigned char y = 100;
    unsigned char result;

    result = Add(x, y);

    printf("x = %u\n", x);
    printf("y = %u\n", y);
    printf("x + y = %u\n", result);

    return 0;
}
