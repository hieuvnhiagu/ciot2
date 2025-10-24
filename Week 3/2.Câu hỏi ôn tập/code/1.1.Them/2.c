#include <stdio.h>

void strcpy(char *des, const char *src) {
    while (*src) {
        *des++ = *src++;
    }
    *des = '\0';
}


int main(void) {
    char source[] = "Hello, world!";
    char destination[50];

    strcpy(destination, source);

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}
