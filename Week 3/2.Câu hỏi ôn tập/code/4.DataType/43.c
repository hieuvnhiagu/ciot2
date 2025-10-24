#include <stdio.h>
#include <stdint.h>

typedef union {
    struct {
        unsigned int EN   : 1;
        unsigned int MODE : 2;
        unsigned int RSV  : 1;
        unsigned int CLK  : 4;
    } bits;
    unsigned char reg;
} CTRL_REG;

int main(void) {
    CTRL_REG ctrl = { .reg = 0xB2 };
    printf("EN=%u, MODE=%u, CLK=%u\n", ctrl.bits.EN, ctrl.bits.MODE, ctrl.bits.CLK);
}