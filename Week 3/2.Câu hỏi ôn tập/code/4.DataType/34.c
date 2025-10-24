#include <stdio.h>

#pragma pack(push, 1)
struct B {
    char a;    // 1 byte
    int b;     // 4 byte
    short c;   // 2 byte
};
#pragma pack(pop)

int main(void) {
    printf("sizeof(struct B) = %zu\n", sizeof(struct B));
    return 0;
}
