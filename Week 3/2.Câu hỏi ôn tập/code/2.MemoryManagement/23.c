#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void func(void) {
    const char *msg = "Embedded";
    size_t len = strlen(msg) + 1; // +1 để chứa ký tự '\0'

    char *p = malloc(len);
    if (p == NULL) {
        perror("malloc failed");
        return;
    }

    strcpy(p, msg);
    printf("%s\n", p);

    free(p);
}

int main(void) {
    printf("Call func():\n");
    func();
    return 0;
}
