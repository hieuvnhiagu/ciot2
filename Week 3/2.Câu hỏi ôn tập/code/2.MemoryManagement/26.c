#include <stdio.h>

void recursion(int x) {
    int a[100];  // Mỗi lần gọi sẽ chiếm 100 * sizeof(int) bytes trên stack

    if (x >= 10) {  // Điều kiện dừng
        printf("Stop when x = %d\n", x);
        return;
    }

    printf("Call recursion(%d)\n", x);
    recursion(x + 1);  // Gọi tiếp với giá trị tăng dần
}

int main(void) {
    recursion(0);
    return 0;
}
