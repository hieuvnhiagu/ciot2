//Problem
// #include <stdio.h>

// char *getString(void) {
//     char str[] = "hello";
//     return str;
// }
// int main(void) {
//     char *s = getString();
//     printf("%s\n", s);
// }

//Solution 1:Dùng biến static
// #include <stdlib.h>
// #include <string.h>
// #include <stdio.h>
// char *getString(void) {
//     static char str[] = "hello";
//     return str;
// }
// int main(void) {
//     char *s = getString();
//     printf("%s\n", s);
// }

//Solution 2: dùng cấp phát động (heap)
// #include <stdlib.h>
// #include <string.h>
// #include <stdio.h>

// char *getString(void) {
//     char *str = malloc(6);  // "hello" + '\0'
//     strcpy(str, "hello");
//     return str;
// }

// int main(void) {
//     char *s = getString();
//     printf("%s\n", s);
//     free(s);  
// }

//Solution 3: Truyền buffer từ ngoài vào
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void getString(char *buf) {
    strcpy(buf, "hello");
}

int main(void) {
    char s[10];
    getString(s);
    printf("%s\n", s);
}
