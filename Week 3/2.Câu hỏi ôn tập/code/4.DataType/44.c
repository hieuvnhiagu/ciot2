//1.
// #include <stdio.h>

// union Frame {
//     struct {
//         unsigned short len  : 10;
//         unsigned short type : 3;
//         unsigned short crc  : 3;
//     } info;

//     struct {
//         unsigned char low;
//         unsigned char high;
//     } bytes;
// };

// int main(void) {
//     printf("sizeof(Frame) = %zu bytes\n", sizeof(union Frame));
//     return 0;
// }

//2.
#include <stdio.h>

union Frame {
    struct {
        unsigned short len  : 10;
        unsigned short type : 3;
        unsigned short crc  : 3;
    } info;

    struct {
        unsigned char low;
        unsigned char high;
    } bytes;
};

int main(void) {
    union Frame f;
    f.bytes.low  = 0xAA;
    f.bytes.high = 0xBB;

    printf("raw = 0x%04X\n", *(unsigned short*)&f);
    printf("len = %u, type = %u, crc = %u\n", f.info.len, f.info.type, f.info.crc);
    return 0;
}
