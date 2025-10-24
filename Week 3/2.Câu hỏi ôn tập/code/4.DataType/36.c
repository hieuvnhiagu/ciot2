#include <stdio.h>

union data {
    int a;
    char b;
};

int main(void) {
    union data ab;

    ab.a = 64;
    ab.a = 2500; // 0x09C4

    printf("Value of ab.b (type: hex) = 0x%X\n", (unsigned char)ab.b);

    return 0;
}
