#include <stdio.h>

struct A {
    char a;   // 1 byte
    int b;    // 4 byte
    short c;  // 2 byte
};

int main(void) {
    printf("sizeof(struct A) = %zu\n", sizeof(struct A));
    return 0;
}
