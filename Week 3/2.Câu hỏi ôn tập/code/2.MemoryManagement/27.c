#include <stdio.h>

int main(void) {
    int a = 0x12345678;
    char *p = (char *)&a;
    p[0] = 0xAA;
    printf("a = 0x%x\n", a);
}