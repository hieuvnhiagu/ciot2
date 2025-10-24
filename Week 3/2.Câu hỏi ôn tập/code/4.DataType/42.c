// #include <stdio.h>

// union Config {
//     struct {
//         unsigned int enable : 1;
//         unsigned int speed  : 2;
//         unsigned int mode   : 3;
//     } normal;

//     struct {
//         unsigned int secure : 1;
//         unsigned int key    : 7;
//     } security;
// };

// int main(void) {
//     printf("Size of struct normal:   %zu bytes\n", sizeof(((union Config *)0)->normal));
//     printf("Size of struct security: %zu bytes\n", sizeof(((union Config *)0)->security));
//     printf("Size of union Config:    %zu bytes\n", sizeof(union Config));
//     return 0;
// }

//3.
#include <stdio.h>
#include <stdint.h>

union Config {
    struct {
        unsigned int enable : 1;
        unsigned int speed  : 2;
        unsigned int mode   : 3;
    } normal;

    struct {
        unsigned int secure : 1;
        unsigned int key    : 7;
    } security;

    unsigned int raw; // dùng để in giá trị bit thô
};

void print_bits(unsigned int val) {
    for (int i = 7; i >= 0; i--) {
        printf("%u", (val >> i) & 1);
    }
}

int main(void) {
    union Config cfg = {0};

    // Gán vào security
    cfg.security.key = 0x7F;   // 0b1111111
    cfg.security.secure = 0;   // đảm bảo bit0 = 0

    printf("Raw bits: ");
    print_bits(cfg.raw);
    printf("\n");

    printf("security.secure = %u\n", cfg.security.secure);
    printf("security.key    = 0x%02X\n", cfg.security.key);

    printf("normal.enable = %u\n", cfg.normal.enable);
    printf("normal.speed  = %u\n", cfg.normal.speed);
    printf("normal.mode   = %u\n", cfg.normal.mode);

    return 0;
}
