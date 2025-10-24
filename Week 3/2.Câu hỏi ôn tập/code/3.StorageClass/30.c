//Problem
// #include <stdio.h>

// int main(void) {
//     register int x = 5;
//     printf("%d\n", x);
//     printf("%p\n", &x);
//     return 0;
// }

//1.Solution: Bỏ từ khóa Register

#include <stdio.h>

int main(void) {
    int x = 5;                 // bỏ từ khóa register
    printf("%d\n", x);
    printf("%p\n", (void*)&x); // ép kiểu sang void* khi in địa chỉ
    return 0;
}
