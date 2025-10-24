#include <stdio.h>
#include <string.h>

int main(void) {
    char array[20];
    for (int i = 0; i < 20; i++) {
        array[i] = i;
    }

    int value;
    memcpy(&value, array + 8, sizeof(int)); // đọc 4 byte bắt đầu từ array[8]
    printf("Value: 0x%x\n", value);
    return 0;
}
