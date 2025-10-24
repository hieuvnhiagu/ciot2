//Problem
// void myfunction(char *q) {
//     memcpy(q, "hello", 5); 
// }

// int main(void) {
//     char *p;
//     myfunction(p);
//     return 0;
// }

//1.Solution 1:Dùng mảng tĩnh
// #include <stdio.h>
// #include <string.h>

// void myfunction(char *q) {
//     memcpy(q, "hello", 6); // 6 bytes để gồm cả '\0'
// }

// int main(void) {
//     char p[10];            // cấp sẵn bộ nhớ
//     myfunction(p);
//     printf("%s\n", p);     
//     return 0;
// }
//2.Solution 2: Dùng cấp phát động (malloc)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myfunction(char *q) {
    memcpy(q, "hello", 6);
}

int main(void) {
    char *p = malloc(6);   // cấp phát động cho 6 byte
    myfunction(p);
    printf("%s\n", p);
    free(p);               // giải phóng bộ nhớ
    return 0;
}
