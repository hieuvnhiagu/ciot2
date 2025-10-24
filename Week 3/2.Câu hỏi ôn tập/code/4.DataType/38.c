//1.Little endian
#include <stdio.h>

union U {
    int val;
    unsigned char byte[4];
};

int main(void) {
    union U u;

    u.val = 0x12345678;

    // Print the integer value
    printf("Value of u.val = 0x%X\n", u.val);

    // Print each byte in memory
    printf("Bytes in memory (in increasing address order):\n");
    printf("byte[0] = 0x%02X\n", u.byte[0]);
    printf("byte[1] = 0x%02X\n", u.byte[1]);
    printf("byte[2] = 0x%02X\n", u.byte[2]);
    printf("byte[3] = 0x%02X\n", u.byte[3]);

    return 0;
}

// 2.Big endian

// #include <stdio.h>

// union U {
//     int val;
//     unsigned char byte[4];
// };

// int main(void) {
//     union U u;
//     int value;

//     u.val = 0x12345678;
//     value = u.val;

//     // Print the integer value
//     printf("Value of u.val = 0x%X\n", u.val);

//     // Send bytes in Big-Endian order (MSB first)
//     printf("\nSending bytes in Big-Endian order:\n");
//     printf("0x%02X\n", (value >> 24) & 0xFF);  // MSB - Byte 1 (1A)
//     printf("0x%02X\n", (value >> 16) & 0xFF);  // Byte 2 (2B)
//     printf("0x%02X\n", (value >> 8)  & 0xFF);  // Byte 3 (3C)
//     printf("0x%02X\n", value & 0xFF);          // LSB - Byte 4 (4D)

//     return 0;
// }
