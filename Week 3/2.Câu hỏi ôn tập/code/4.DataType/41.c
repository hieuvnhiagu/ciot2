// #include <stdio.h>

// struct Packet {
//     unsigned char header;   // 1 byte
//     union {
//         struct {
//             unsigned int id   : 4;
//             unsigned int type : 3;
//             unsigned int err  : 1;
//         } bits;
//         unsigned char raw;  // 1 byte
//     } data;
// };

// int main(void) {
//     printf("sizeof(struct Packet) = %zu bytes\n", sizeof(struct Packet));
//     printf("sizeof(header)        = %zu bytes\n", sizeof(((struct Packet*)0)->header));
//     printf("sizeof(data)          = %zu bytes\n", sizeof(((struct Packet*)0)->data));
//     return 0;
// }

//Tính giá trị
#include <stdio.h>

struct Packet {
    unsigned char header;
    union {
        struct {
            unsigned int id   : 4;  // 4 bit thấp (bit 0–3)
            unsigned int type : 3;  // 3 bit kế (bit 4–6)
            unsigned int err  : 1;  // 1 bit cao nhất (bit 7)
        } bits;
        unsigned char raw;
    } data;
};

int main(void) {
    struct Packet p;

    p.data.raw = 0xAB;  // 0xAB = 0b10101011

    printf("Raw = 0x%02X\n", p.data.raw);
    printf("Binary: 1 0101011 (bit7..0)\n");
    printf("err  = %u\n", p.data.bits.err);
    printf("type = %u\n", p.data.bits.type);
    printf("id   = %u\n", p.data.bits.id);

    return 0;
}
