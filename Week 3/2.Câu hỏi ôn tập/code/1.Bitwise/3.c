#include <stdio.h>

int main(void) {
    unsigned int x = 0b00001010; // 10 ở hệ thập phân (bits: 00001010)
    int n = 1;

    printf("Before toggle: %u \n", x);
    x ^= (1 << n); // đảo bit thứ 1
    printf("After toggle:  %u \n", x);

    return 0;
}
