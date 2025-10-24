#include <stdio.h>

int main(void) {
    unsigned int x = 0b00000101;  // x = 5
    int n = 3;

    x |= (1 << n);  // Bật bit thứ 3 (tính từ bit 0)
    printf("x = %u", x); // In kết quả (nếu trình biên dịch hỗ trợ %b)
    
    return 0;
}
