#include <stdio.h>

// Cấu trúc thông thường (mặc định có căn chỉnh bộ nhớ)
struct {
    int a;   // 4 byte
    char b;  // 1 byte
} ab;

// Cấu trúc có #pragma pack(1) 
#pragma pack(push, 1)
struct {
    char a;  // 1 byte
    int b;   // 4 byte
} ba;
#pragma pack(pop)

int main(void) {
    printf("sizeof(struct ab) = %zu\n", sizeof(ab));
    printf("sizeof(struct ba) = %zu\n", sizeof(ba));
    return 0;
}
