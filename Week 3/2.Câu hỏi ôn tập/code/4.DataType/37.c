#include <stdio.h>

union Data {
    int i;
    char c[4];
};

struct Test {
    char flag;
    union Data data;
};

int main(void) {
    printf("Size of union Data: %zu byte\n", sizeof(union Data));
    printf(" - sizeof(int)  = %zu\n", sizeof(int));
    printf(" - sizeof(char[4]) = %zu\n", sizeof(char[4]));

    printf("\n Size of struct Test: %zu byte\n", sizeof(struct Test));
    printf(" - sizeof(flag) = %zu\n", sizeof(((struct Test*)0)->flag));
    printf(" - sizeof(data) = %zu\n", sizeof(((struct Test*)0)->data));

    return 0;
}
