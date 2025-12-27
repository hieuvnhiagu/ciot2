1. Viết 1 dòng code duy nhất để bật bit thứ 3 của biến x = 0b00001010

x |= (1<<3)

2. Giả sử a = 5, b = 9. Cách nào hoán đổi giá trị a và b mà không dùng biến thứ ba?

Dùng toán tử xor

a^=b;

b^=a;

a^a=b;

=>a=9;b=5;

3. Kiểm tra số n = 15 là số chẵn hay số lẻ?

Nếu n&1 ==0 => số chẵn, còn không thì là số lẻ

4. Có những phân đoạn vùng nhớ nào?

Stack, heap, .bss,.rodata, .data

5. Tại sao lại phải chia ra vùng .data và .bss?

Để phân tách thành hai vùng nhớ rõ ràng dành cho biến toàn cục được khởi tạo, và biến toàn cục không được khởi tạo. Vùng .bss không chứa dữ liệu, chỉ cần lưu kích thước giúp tiết kiệm bộ nhớ lưu trữ chương trình.

6. Tại sao vùng .bss không chiếm nhiều dung lượng trong file .bin, nhưng lại chiếm RAM khi chạy?

Vùng .bss không chiếm nhiều dung lượng trong file.bin vì chỉ lưu kích thước chứ không lưu dữ liệu, còn khi chạy nó chứa các biến được hệ thống khởi tạo bằng 0 nên chiếm RAM khi chạy

7. Giải thích về từ khóa static

Static:

Vị trí lưu trữ: vùng nhớ Data Segment/BSS

Phạm vi: cục bộ. Đối với biến ở trong hàm, chỉ hoạt động trong hàm được khai báo

Vòng đời: tồn tại trong suốt vòng đời của chương trình

Đối với hàm, chỉ hoạt động trong file được khai báo.

8. Viết lại hàm strcpy

char \*strcpy(char \*dst, const char \*src) {

char \*p = dst;

while (\*src != '\0') {

\*p = \*src;

p++;

src++;

}

\*p = '\0';

return dst;

}

9. Hàm sau làm gì? Có vấn đề gì không?

unsigned char c;

for (c = 0; c < 999; c++) {

printf("%d ", c);

}

Giá trị của kiểu dữ liệu char từ 0 đến 255 , nên khi đến 255 thì c sẽ quay lại 0 và vòng lặp vô tận,

10. Đoạn mã sau có vấn đề gì trong đoạn mã sau không?

unsigned int x;

for (x = 10; x >= 0; x--) {

printf("%u ", x);

}

Giá trị unsigned int có giá trị từ 0 đến 65000 nên khi x=0 thì sẽ quay lại 65000 gây ra lỗi vòng lặp vô hạn.

Cách sửa :x>0

11.

void myfunction(char \*q) {

memcpy(q, "hello", 5);

}

int main(void) {

char \*p;

myfunction(p);

return 0;

}

Con trỏ chưa khởi tạo, nên chương trình đang ghi giá trị vào vùng nhớ không xác định dẫn đến lỗi segmentation faults.

Cách sửa: char \*p=malloc(5);

12.

union U {

int val;

char byte[4];

};

int main(void) {

union U u;

u.val = 0x12345678;

printf("%x %x %x %x\n", u.byte[0], u.byte[1], u.byte[2], u.byte[3]);

}

Little endian: 78 56 34 12

Big endian: 12 34 56 78

13.

union Frame {

struct {

unsigned short len : 10;

unsigned short type : 3;

unsigned short crc : 3;

} info;

struct {

unsigned char low;

unsigned char high;

} bytes;

};

1. sizeof(union Frame) là bao nhiêu?

2. Nếu bytes.low = 0xAA và bytes.high = 0xBB, giá trị của info.len, info.type, info.crc là gì?

3. Giải thích tại sao giá trị có thể khác nhau giữa compiler (GCC vs ARMCC)?

1. 2 bytes

2.

Little endian (GCC)

0xbbaa = 1011 1011 1010 1010

Info.len : 1110 101 010 :938

Info.type:110 =>6

Info.crc: 101=>5

Big endian (ARMCC):

0xbbaa = 1011 1011 1010 1010

Info.len: 1011 1011 10 =>750

Info.type: 101:=>5

Info.crc:010=>2

3.

GCC xếp từ bit thấp đến bit cao, còn ARMCC xếp từ cao đến thấp

14.

4 bytes

15.

Gán month =1 luôn luôn đúng nên luôn in ra January

16.

Giá trị unsigned int có giá trị từ 0 đến 65000 nên khi x=0 thì sẽ quay lại 65000 gây ra lỗi vòng lặp vô hạn.

Cách sửa :x>0

17.

a,b cấp phát ở .bss

g: stack

h: ..data

i: heap

18.

int copy(char \*scr, char \*dst, unsigned int size) {

char \*s1;

while (size--) {

\*s1++ = \*scr++;

\*dst++ = \*s1;

}

return 0;

}

Con trỏ s1 chưa được khai báo nên s1 ++ dẫn đến vùng nhớ không hợp lệ => segmentation fault

19.

struct

{

int a;

char b;

} ab;

#pragma pack(push, 1)

struct

{

char a;

int b;

} ba;

#pragma pack(pop)

struct ab có size là 8 bytes, struct ba có size là 5 bytes vì bỏ qua alignment do dùng pragma back

20.

typedef union {

struct {

unsigned int EN : 1;

unsigned int MODE : 2;

unsigned int RSV : 1;

unsigned int CLK : 4;

} bits;

unsigned char reg;

} CTRL\_REG;

int main(void) {

CTRL\_REG ctrl = { .reg = 0xB2 };

printf("EN=%u, MODE=%u, CLK=%u\n", ctrl.bits.EN, ctrl.bits.MODE, ctrl.bits.CLK);

}

1. In ra kết quả gì (với little-endian)?

2. Giải thích tại sao việc truy cập ctrl.bits và ctrl.reg lại ảnh hưởng trực tiếp nhau?

1.

0xB2 =1011 0010

EN=0, MODE=1, CLK=11

2.

Bởi vì chúng nằm trong cùng một union. Trong union, mọi thành viên dùng chung cùng vùng nhớ.