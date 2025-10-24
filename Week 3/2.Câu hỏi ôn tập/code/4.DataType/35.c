#include <stdio.h>

struct Inner {
    char c;   // 1 byte
    int d;    // 4 byte
};

struct Outer {
    int a;            // 4 byte
    struct Inner in;  // gồm 1 char + 3 padding + 4 byte int
    char e[3];        // 3 byte
};

int main(void) {
    printf("sizeof(struct Inner) = %zu\n", sizeof(struct Inner));
    printf("sizeof(struct Outer) = %zu\n", sizeof(struct Outer));
    return 0;
}
