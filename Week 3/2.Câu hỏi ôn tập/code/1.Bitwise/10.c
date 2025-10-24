//Cách 1: Dùng log2(n) (thư viện <math.h>)
#include <stdio.h>
#include <math.h>

int main() {
    unsigned int n = 36; // Example: 36 = 100100b

    if (n == 0) {
        printf("Number is 0 → no MSB.\n");
        return 0;
    }

    int msb = (int)log2(n); // Position of the most significant bit (0-based)
    printf("The MSB position of %u is: %d\n", n, msb);

    return 0;
}

//Cách 2: Dùng vòng lặp dịch bit
// #include <stdio.h>

// int main() {
//     unsigned int n = 36; // Example: 100100b
//     int msb = -1;        // Initialize with -1 (no bit found yet)

//     unsigned int temp = n;
//     while (temp > 0) {
//         temp >>= 1;  // Shift right until number becomes 0
//         msb++;        // Count how many shifts done
//     }

//     if (msb >= 0)
//         printf("The MSB position of %u is: %d\n", n, msb);
//     else
//         printf("Number is 0 → no MSB.\n");

//     return 0;
// }
