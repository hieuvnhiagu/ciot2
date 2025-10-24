//Little endian
// #include <stdio.h>

// union Data {
//     struct {
//         unsigned int flag  : 3;  // 3 bits (LSBs)
//         unsigned int mode  : 5;  // next 5 bits
//         unsigned int value : 8;  // next 8 bits
//     } info;
//     unsigned short raw;
// };

// int main(void) {
//     union Data d;

//     d.raw = 0xABCD;  // raw = 0b1010_1011_1100_1101

//     printf("Raw value = 0x%04X\n", d.raw);
//     printf("flag  = %u\n", d.info.flag);
//     printf("mode  = %u\n", d.info.mode);
//     printf("value = %u\n", d.info.value);

//     return 0;
// }

//Big endian
#include <stdio.h>

union Data {
    struct {
        unsigned int flag  : 3;  // 3 bits (MSB side in Big-Endian)
        unsigned int mode  : 5;  // next 5 bits
        unsigned int value : 8;  // last 8 bits
    } info;
    unsigned short raw;
};

int main(void) {
    union Data d;

    d.raw = 0xABCD;  // raw = 0b10101011_11001101

    printf("Raw = 0x%04X\n", d.raw);

    // Decode as Big-Endian manually using bit operations
    unsigned short raw = d.raw;

    // On Big-Endian, the MSB (0xAB) is stored first, so shift from the opposite side
    unsigned int flag  = (raw >> 13) & 0x7;   // top 3 bits
    unsigned int mode  = (raw >> 8) & 0x1F;   // next 5 bits
    unsigned int value = raw & 0xFF;          // last 8 bits

    printf("flag  = %u\n", flag);
    printf("mode  = %u\n", mode);
    printf("value = %u\n", value);

    return 0;
}
