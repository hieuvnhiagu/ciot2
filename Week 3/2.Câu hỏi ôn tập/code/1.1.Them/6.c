#include <stdio.h>

int main(void) {
    unsigned int x;
    for (x = 10; x >= 0; x--) {
        printf("%u ", x);
    }
    printf("\n");
    return 0;
}
