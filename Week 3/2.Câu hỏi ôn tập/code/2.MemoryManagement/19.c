//Problem
 
// void myfunction(char *q) {
//     q = (char *)malloc(8);
//     if (q) {
//         memcpy(q, "hello", 6);
//     }
// }

// void main(void) {
//     char *p = NULL;
//     myfunction(p);
// }

//Solution 1: Trả về con trỏ
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// char* myfunction(void) {
//     char *q = (char *)malloc(8);
//     if (q) {
//         memcpy(q, "hello", 6);
//     }
//     return q; // trả về vùng nhớ đã cấp phát
// }

// int main(void) {
//     char *p = myfunction();  // nhận lại con trỏ
//     if (p) {
//         printf("%s\n", p);   // In ra: hello
//         free(p);             // Giải phóng bộ nhớ
//     }
//     return 0;
// }
//Solution 2: Truyền địa chỉ con trỏ (char )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myfunction(char **q) {
    *q = (char *)malloc(8);
    if (*q) {
        memcpy(*q, "hello", 6);
    }
}

int main(void) {
    char *p = NULL;
    myfunction(&p);          // truyền địa chỉ của p
    if (p) {
        printf("%s\n", p);   // In ra: hello
        free(p);
    }
    return 0;
}

