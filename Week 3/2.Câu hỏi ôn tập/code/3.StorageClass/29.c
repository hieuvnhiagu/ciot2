#include <stdio.h>

void counter(void) {
    // static int count = 0;  
    int count = 0;
    count++;               
    printf("%d ", count);  
}

int main(void) {
    for (int i = 0; i < 3; i++) {
        counter();
    }
    printf("\n");
    return 0;
}
