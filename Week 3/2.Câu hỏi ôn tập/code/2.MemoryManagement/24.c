//Problem
// #include <stdio.h>
// void test(void) {
//     char *str = "Hello";;   
//     str[0] = 'h';           
//     printf("%s\n", str);    
// }
// int main(void) {
//     printf("Call test():\n");
//     test();
//     return 0;
// }

//1.Solution
#include <stdio.h>
void test(void) {
    char str[] = "Hello";   // Mảng trên stack, có thể ghi
    str[0] = 'h';           // Ghi đè ký tự đầu tiên
    printf("%s\n", str);    // In ra: "hello"
}

int main(void) {
    printf("Call test():\n");
    test();
    return 0;
}
