#include <stdio.h>

struct Flags {
    unsigned int a : 1;  // 1 bit
    unsigned int b : 3;  // 3 bits
    unsigned int c : 4;  // 4 bits
};

int main(void) {
    struct Flags f;

    printf("Size of struct Flags: %zu bytes\n", sizeof(struct Flags));
    printf("Size of variable f: %zu bytes\n", sizeof(f));

    return 0;
}
