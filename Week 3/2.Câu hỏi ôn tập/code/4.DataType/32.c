#include <stdio.h>

typedef struct {
    char x;   // 1 byte
    int y;    // 4 byte
} mystruct;

int main(void) {
    printf("sizeof(mystruct) = %zu\n", sizeof(mystruct));
    return 0;
}
