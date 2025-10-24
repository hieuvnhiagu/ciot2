#include <stdio.h>
#include <string.h>

// Hàm copy: sao chép size byte từ src sang dst
int copy(char *src, char *dst, unsigned int size) {
    if (!src || !dst) return -1; // kiểm tra NULL

    while (size--) {
        *dst++ = *src++;
    }
    return 0;
}

int main(void) {
    char src[] = "Hello, world!";   // Chuỗi nguồn
    char dst[50];                   // Chuỗi đích (đủ lớn)

    // Gọi hàm copy
    int ret = copy(src, dst, strlen(src) + 1);  // +1 để sao chép cả ký tự '\0'

    if (ret == 0) {
        printf("Copy thanh cong!\n");
        printf("Nội dung dst: %s\n", dst);
    } else {
        printf("Copy that bai!\n");
    }

    return 0;
}
