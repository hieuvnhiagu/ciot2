#include <stdio.h>

int main(void) {
    unsigned char c; //(0->255)
    for (c = 0; c < 999; c++) {
        printf("%d ", c);
    }
    return 0;
}
