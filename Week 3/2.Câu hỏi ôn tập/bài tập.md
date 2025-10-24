Bitwise

1\. Viết 1 dòng code để bật bit thứ n của x.

x |= (1 << n);

2\. Viết 1 dòng code để tắt bit thứ n của x.

x &= ~(1 << n);

3\. Viết 1 dòng code để đảo bit thứ n của x.

x ^= (1 << n);

4\. Viết 1 dòng code để kiểm tra bit thứ n có bật không.

if (x & (1 << n))

5\. Viết 1 dòng code để hoán đổi 2 số a và b không dùng biến tạm.

Dùng XOR swap: a ^= b; b ^= a; a ^= b;

6\. Viết 1 dòng code để kiểm tra n có phải lũy thừa của 2 không.

n & (n - 1) == 0;

7\. Viết 1 dòng code để kiểm tra n là chẵn hay lẻ.

Kiểm tra bit 0: if (n & 1) => lẻ;

8\. Viết 1 dòng code để lấy bù 2 (two’s complement) của n.

Bù 2 = đảo bit (~n) + 1;

9\. Viết 1 dòng code để kiểm tra hai số a, b có bằng nhau không mà không dùng ==.

Dùng XOR: if ((a ^ b) == 0) => bằng nhau;

10\. Viết 1 dòng code để tìm vị trí MSB (bit có trọng số lớn nhất).

Tìm MSB bằng log2(n) hoặc vòng lặp dịch bit;

int msb = (n > 0) ? (int)log2(n) : -1;

11\. Viết 1 dòng code để tìm vị trí LSB (bit có trọng số nhỏ nhất).

Tìm LSB bằng công thức n & (-n);

int lsb = n & -n;

12\. Viết 1 dòng code để tắt bit 1 ở ngoài cùng bên phải của n.

Tắt bit phải nhất: x = x & (x - 1);

13\. Viết 1 dòng code để cô lập bit 1 ở ngoài cùng bên phải của n.

Cô lập bit phải nhất: x & (-x);

14\. Viết 1 dòng code để kiểm tra n có phải bội của 8 không.

Kiểm tra nếu n % 8 == 0 hoặc (n & 0x7) == 0

Memory Management Code

15\. Đoạn mã sau có vấn đề gì trong đoạn mã sau không?

void myfunction(char \*q) {

`    `memcpy(q, "hello", 5); 

}

int main(void) {

`    `char \*p;

`    `myfunction(p);

`    `return 0;

}

Con trỏ p chưa được khởi tạo

char \*p;

p chỉ là một con trỏ chưa trỏ tới bất kỳ vùng nhớ hợp lệ nào.

Khi truyền p vào myfunction(p), biến q trong myfunction cũng trỏ tới một địa chỉ ngẫu nhiên / rác trong bộ nhớ.

<a name="_hlk211537997"></a>→ memcpy(q, "hello", 5): cố gắng chép dữ liệu vào vùng nhớ không hợp lệ, chương trình sẽ bị lỗi segmentation fault (crash).

16\. Hàm hoạt động ra sao? Các biến được cấp phát ở đâu?

int a;

char \*b;

const char c[20] = "I am a string";

void func(char d, int c\_param, char \*f) {

`    `int g = 0;

`    `static int h = 2;

`    `char \*i = NULL;

`    `i = (char \*)malloc(20);

`    `if (i != NULL) {

`        `free(i);

`    `}

}

Biến a toàn cục, chưa khởi tạo => nằm ở .bss

Biến b toàn cục, chưa khởi tạo => nằm ở .bss

Mảng c[20] mảng hằng, chuỗi => nằm ở .rodata

Biến g cục bộ => nằm ở stack

Biến d,c\_param, f : đối số => nằm ở stack

Biến g, h : cục bộ => nằm ở stack

Biến i: cấp phát 20 byte động => nằm ở heap

**Cách hàm hoạt động:**

void func(char d, int c\_param, char \*f)

Khi được gọi, các biến d, c\_param, f được đẩy lên stack.

Biến g là biến cục bộ, cũng nằm trong stack.

Biến static int h = 2; sẽ chỉ được khởi tạo 1 lần duy nhất, và giữ nguyên giá trị giữa các lần gọi hàm.

Biến i là con trỏ, ban đầu NULL, sau đó được cấp phát động vùng nhớ malloc(20) → nằm trong heap.

Sau khi dùng xong, gọi free(i); để giải phóng tránh rò rỉ bộ nhớ.

17\. a và b được cấp phát và lưu trữ ở đâu?

void main(void) {

`    `char a[4] = "foo";

`    `char \*b = "bar";

}

a là mảng cục bộ (local array) được khai báo trong hàm main.

"foo" là một chuỗi ký tự gồm 3 ký tự 'f', 'o', 'o' và ký tự kết thúc chuỗi '\0' ⇒ tổng cộng 4 byte.

Do đó, a là một mảng 4 phần tử nằm trên stack

- Biến a được cấp phát và lưu trữ trên vùng nhớ stack

char \*b = "bar";

"bar" là một chuỗi hằng (string literal) — tức là nó nằm ở vùng read-only memory (.rodata).

b là con trỏ cục bộ, được cấp phát trong stack, nhưng nó trỏ đến vùng .rodata.

- Biến b cấp phát trên vùng nhớ stack, nhưng lưu trữ trong .rodata

18\.Đoạn mã sau có vấn đề gì không? Với RAM = 2000 byte?

void myfunction() {

`    `char \*q;

`    `for (int i = 0; i < 1000; i++) {

`        `q = (char \*)malloc(8);

`        `if (q != NULL) {

`            `memcpy(q, "hello", 6);

`        `}

`    `}

}

<a name="_hlk211538784"></a>Vấn đề 1: Rò rỉ bộ nhớ (memory leak)

Không có lệnh free(q) để giải phóng vùng nhớ cũ\
Sau 1000 lần lặp, chương trình đã cấp phát 1000 × 8 = 8000 byte, nhưng không giải phóng byte nào → rò rỉ bộ nhớ nghiêm trọng.

Vấn đề 2: Vượt quá dung lượng RAM (2000 byte) (Out of Memory)

Nếu RAM chỉ có 2000 byte, thì: Sau khoảng 2000 / 8 = 250 lần cấp phát, malloc() sẽ bắt đầu trả về NULL (không thể cấp phát thêm). Chương trình sẽ tiếp tục chạy, nhưng không có cơ chế xử lý khi bộ nhớ heap bị đầy. Điều này có thể dẫn tới malloc() thất bại, crash, hoặc treo chương trình tùy hệ thống.

19\. Đoạn mã sau có vấn đề gì không? Làm sao để in ra "hello"?

void myfunction(char \*q) {

`    `q = (char \*)malloc(8);

`    `if (q) {

`        `memcpy(q, "hello", 6);

`    `}

}

void main(void) {

`    `char \*p = NULL;

`    `myfunction(p);

}

Truyền tham trị:** p trong main không nhận được giá trị mới từ malloc trong myfunction.

Rò rỉ bộ nhớ: malloc(8) được gọi, nhưng không có con trỏ nào lưu lại địa chỉ được cấp phát.

Không in được "hello": Vì sau khi ra khỏi myfunction, p vẫn là NULL.

20\. Các biến sau được lưu ở đâu?

int a = 5;

int d;

char b[6] = "hello";

const int c = 4;

void myfunction(void)

{

`    `static int g = 5;

`    `const int h = 6;

`    `char i;

}


Biến a: Biến toàn cục, có khởi tạo giá trị, lưu ở** .data segment

Biến d: Biến toàn cục, chưa khởi tạo, lưu ở .bss segment

Mảng b: mảng toàn cục, được khởi tạo giá trị, lưu ở .data segment

Biến c: Biến toàn cục, hằng số, lưu ở .rodata segment

Biến g: Biến cục bộ tĩnh, có khởi tạo, lưu ở**:** .data segment.

Biến h: Biến cục bộ, hằng số, lưu ở: stack

Biến i: Biến cục bộ thông thường, lưu ở: stack

21\. Đoạn mã sau có vấn đề gì không?

void main(void) {

`    `char array[20];

`    `for (int i = 0; i < 20; i++) {

`        `array[i] = i;

`    `}

`    `int \*p = (int \*)array;

`    `p++;

`    `p++;

`    `printf("Value at p: 0x%x\n", \*p);

}

Mảng array gồm 20 byte, mỗi phần tử 1 byte.

Khi ép kiểu int \*p = (int \*)array;, con trỏ p trỏ đến địa chỉ của array[0], nhưng được hiểu là trỏ đến int (4 byte, giả sử trên hệ thống 32-bit).

=> Việc ép kiểu này không đảm bảo căn chỉnh (alignment) hợp lệ cho int.\
Nếu array không được căn chỉnh theo biên 4 byte, việc đọc/ghi kiểu int có thể gây lỗi truy cập bộ nhớ (bus error) trên một số kiến trúc (như ARM, MIPS).

Cách sửa: đọc giá trị 4 byte từ mảng char, dùng memcpy thay vì ép kiểu:

#include <stdio.h>

#include <string.h>

int main(void) {

`    `char array[20];

`    `for (int i = 0; i < 20; i++) {

`        `array[i] = i;

`    `}

`    `int value;

`    `memcpy(&value, array + 8, sizeof(int)); // đọc 4 byte bắt đầu từ array[8]

`    `printf("Value: 0x%x\n", value);

`    `return 0;

}

22\. Có vấn đề gì với hàm copy sau?

int copy(char \*scr, char \*dst, unsigned int size) {

`    `char \*s1;

`    `while (size--) {

`        `\*s1++ = \*scr++;

`        `\*dst++ = \*s1;

`    `}

`    `return 0;

}

1\. Biến s1 chưa được khởi tạo

char \*s1;

s1 chỉ được khai báo, chưa được gán địa chỉ hợp lệ.

Khi thực hiện \*s1++ = \*scr++;, chương trình ghi dữ liệu vào vùng nhớ rác, gây segmentation fault hoặc hỏng dữ liệu.
### **2.** Logic sao chép sai
\*dst++ = \*s1;

Mục tiêu là sao chép dữ liệu từ src sang dst, nhưng ở đây bạn lại gán từ s1, mà s1 chẳng có giá trị đúng nào.

Nghĩa là không hề sao chép từ scr sang dst, mà chỉ đang làm loạn vùng nhớ.

Cách sửa:

#include <stdio.h>

#include <string.h>

// Hàm copy: sao chép size byte từ src sang dst

int copy(char \*src, char \*dst, unsigned int size) {

`    `if (!src || !dst) return -1; // kiểm tra NULL

`    `while (size--) {

`        `\*dst++ = \*src++;

`    `}

`    `return 0;

}

int main(void) {

`    `char src[] = "Hello, world!";   // Chuỗi nguồn

`    `char dst[50];                   // Chuỗi đích (đủ lớn)

`    `// Gọi hàm copy

`    `int ret = copy(src, dst, strlen(src) + 1);  // +1 để sao chép cả ký tự '\0'

`    `if (ret == 0) {

`        `printf("Copy thành công!\n");

`        `printf("Nội dung dst: %s\n", dst);

`    `} else {

`        `printf("Copy thất bại!\n");

`    `}

`    `return 0;

}

23\. Đoạn mã sau có vấn đề gì không?

void func(void) {

`    `char \*p = malloc(10);

`    `strcpy(p, "Embedded");

}

1\. Lỗi tràn bộ nhớ (buffer overflow)

Chuỗi "Embedded" có 8 ký tự chữ + 1 ký tự null **('\0')** → tổng cộng 9 byte cần lưu.

malloc(10) cấp phát 10 byte — vừa đủ cho chuỗi "Embedded" (9 byte) nhưng phải luôn để dư ít nhất 1 byte nếu có rủi ro.\
→ Về lý thuyết không tràn ngay lập tức, nhưng nếu thay đổi chuỗi dài hơn thì rất dễ lỗi.

Tuy nhiên, thực tế nguy cơ lớn hơn nằm ở thiếu kiểm tra kết quả cấp phát và không giải phóng bộ nhớ

2\. Không kiểm tra malloc( ) 

malloc() có thể trả về NULL nếu hết bộ nhớ. Khi đó, strcpy(p, "Embedded") sẽ truy cập vào địa chỉ NULL → segmentation fault.

3\. Thiếu giải phóng vùng nhớ.

Cách sửa:

#include <stdlib.h>

#include <string.h>

#include <stdio.h>

void func(void) {

`    `const char \*msg = "Embedded";

`    `size\_t len = strlen(msg) + 1; // +1 để chứa ký tự '\0'

`    `char \*p = malloc(len);

`    `if (p == NULL) {

`        `perror("malloc failed");

`        `return;

`    `}

`    `strcpy(p, msg);

`    `printf("%s\n", p);

`    `free(p);

}

int main(void) {

`    `printf("Call func():\n");

`    `func();

`    `return 0;

}


24\. Đoạn mã sau có hợp lệ không?

void test(void) {

`    `char \*str = "Hello";

`    `str[0] = 'h';

}

Vấn đề chính: Ghi vào vùng nhớ hằng (read-only memory)

Dòng char \*str = "Hello";\
→ "Hello" là một chuỗi hằng (string literal), được lưu trong vùng nhớ chỉ đọc (read-only segment) của chương trình, chứ không nằm trên stack hay heap.

Khi thực hiện str[0] = 'h';, tức là đang cố ghi vào vùng nhớ chỉ đọc, điều này dẫn đến undefined behavior.\
=> Chương trình sẽ bị crash (Segmentation fault).

Cách sửa:

//1.Solution

#include <stdio.h>

void test(void) {

`    `char str[] = "Hello";   // Mảng trên stack, có thể ghi

`    `str[0] = 'h';           // Ghi đè ký tự đầu tiên

`    `printf("%s\n", str);    // In ra: "hello"

}

int main(void) {

`    `printf("Call test():\n");

`    `test();

`    `return 0;

}

25\. Các biến a, b, c, d được lưu ở đâu trong bộ nhớ?

int a = 10;

const int b = 5;

static int c = 3;

int func(void) {

`    `int d = 2;

`    `return a + b + c + d;

}

Biến a: biến toàn cục, được khởi tạo giá trị khác 0, lưu ở Data Segment.

Biến b: biến toàn cục, là hằng số lưu ở Text Segment.

Biến c: biến toàn cục, lưu ở Data Segment

Biến d: biến cụ bộ, lưu ở Stack.

26\. Đoạn mã sau có vấn đề gì?

void recursion(int x) {

`    `int a[100];

`    `recursion(x + 1);

}

Gọi đệ quy không có điều kiện dừng

Hàm recursion() tự gọi lại chính nó trong mọi lần chạy mà không có điều kiện dừng.

Kết quả: chương trình sẽ gọi vô hạn → mỗi lần gọi tạo một bản sao mới của a[100] trên stack → sớm muộn stack sẽ đầy → stack overflow.

Cách sửa: Thêm điều kiện dừng đệ quy**:**

#include <stdio.h>

void recursion(int x) {

`    `int a[100];  // Mỗi lần gọi sẽ chiếm 100 \* sizeof(int) bytes trên stack

`    `if (x >= 10) {  // Điều kiện dừng

`        `printf("Kết thúc khi x = %d\n", x);

`        `return;

`    `}

`    `printf("Đang gọi recursion(%d)\n", x);

`    `recursion(x + 1);  // Gọi tiếp với giá trị tăng dần

}

int main(void) {

`    `recursion(0);

`    `return 0;

}

27\. Đoạn mã sau có in ra đúng giá trị ban đầu không? Tại sao?

int main(void) {

`    `int a = 0x12345678;

`    `char \*p = (char \*)&a;

`    `p[0] = 0xAA;

`    `printf("a = 0x%x\n", a);

}

Giá trị mới của a: a = 0x123456aa

Ép địa chỉ của a sang kiểu char\*\
→ p **trỏ đến byte đầu tiên của biến a trong bộ nhớ**.

Vì char chỉ có 1 byte, nên p[0], p[1], p[2], p[3] tương ứng từng byte của a.

Theo Little Endian:

p[0] == byte thấp nhất của a  // vì Little Endian

p[1] == byte thứ hai

p[2] == byte thứ ba

p[3] == byte cao nhất

28\. Đoạn mã sau có vấn đề gì?

char \*getString(void) {

`    `char str[] = "hello";

`    `return str;

}

int main(void) {

`    `char \*s = getString();

`    `printf("%s\n", s);

}

### Vấn đề chính: Trả về con trỏ tới biến cục bộ
Trong hàm getString(), biến str là **mảng cục bộ**:

char str[] = "hello";

Khi hàm getString() chạy xong, stack frame của hàm bị hủy, nghĩa là vùng nhớ chứa str không còn hợp lệ**.** Tuy nhiên, lại trả về địa chỉ của vùng nhớ đó:

return str;

→ Con trỏ s trong main() trỏ đến vùng nhớ đã bị giải phóng / ghi đè.\
Khi printf("%s", s); chạy, nó truy cập vùng nhớ không còn hợp lệ → hành vi không xác định (undefined behavior)**:** Có thể in rác, có thể crash, có thể “tình cờ” in đúng "hello" (nếu stack chưa bị ghi đè ngay),

Cách sửa:
#### Cách 1: Dùng biến **static**
#include <stdlib.h>

#include <string.h>

#include <stdio.h>

char \*getString(void) {

`    `static char str[] = "hello";

`    `return str;

}

int main(void) {

`    `char \*s = getString();

`    `printf("%s\n", s);

}

static giúp str tồn tại suốt vòng đời chương trình.

Không bị thu hồi khi hàm kết thúc.

Cách 2: Dùng cấp phát động (heap)

#include <stdlib.h>

#include <string.h>

#include <stdio.h>

char \*getString(void) {

`    `char \*str = malloc(6);  // "hello" + '\0'

`    `strcpy(str, "hello");

`    `return str;

}

int main(void) {

`    `char \*s = getString();

`    `printf("%s\n", s);

`    `free(s);  

}

Vùng nhớ còn tồn tại sau khi hàm kết thúc.

Cần free() sau khi dùng.

Cách 3: Truyền buffer từ ngoài vào

#include <stdlib.h>

#include <string.h>

void getString(char \*buf) {

`    `strcpy(buf, "hello");

}

int main(void) {

`    `char s[10];

`    `getString(s);

`    `printf("%s\n", s);

}

Không cần malloc, không cần static.

Dễ kiểm soát vùng nhớ.

Storage Class Code

29\.

void counter(void) {

`    `static int count = 0;

`    `count++;

`    `printf("%d ", count);

}

int main(void) {

`    `for (int i = 0; i < 3; i++)

`        `counter();

`    `return 0;

}

1\. Kết quả in ra là gì?

2\. Nếu bỏ từ khóa static, kết quả có khác không?

3\. Biến count được lưu ở vùng nhớ nào?

void counter(void) {

`    `static int count = 0;

`    `count++;

`    `printf("%d ", count);

}

int main(void) {

`    `for (int i = 0; i < 3; i++)

`        `counter();

`    `return 0;

}

1\. 1 2 3

2\. 1 1 1

3\. 

Có static: biến tĩnh cục bộ, lưu ở Data Segment

Không có static: biến cục bộ lưu ở Stack.

30\.

int main(void) {

`    `register int x = 5;

`    `printf("%d\n", x);

`    `printf("%p\n", &x);

`    `return 0;

}

1\. Code này có biên dịch được không?

2\. Nếu không, compiler báo lỗi gì? Tại sao?

1\. Không, code này không biên dịch được. 

2\.

30\.c:6:5: error: address of register variable 'x' requested      

`    `6 |     printf("%p\n", &x);

Từ khóa register là chỉ thị** nói với compiler rằng:

“Nếu có thể, hãy lưu biến này trong thanh ghi CPU (register) thay vì trong bộ nhớ (RAM/stack).”

Mục đích: tăng tốc độ truy cập, vì thanh ghi CPU nhanh hơn bộ nhớ nhiều lần.

**Hậu quả của việc lưu trong thanh ghi:**

Biến trong thanh ghi không có địa chỉ bộ nhớ rõ ràng (nó không nằm trong stack).

Do đó, bạn không thể lấy địa chỉ của nó bằng &.

Cách sửa:

Bỏ từ khóa Register

#include <stdio.h>

int main(void) {

`    `int x = 5;                 // bỏ từ khóa register

`    `printf("%d\n", x);

`    `printf("%p\n", (void\*)&x); // ép kiểu sang void\* khi in địa chỉ

`    `return 0;

}


Data Type Code 

31\. sizeof(struct ab) và sizeof(struct ba) là bao nhiêu?

struct

{

`    `int a;

`    `char b;

} ab;

#pragma pack(push, 1)

struct

{

`    `char a;

`    `int b;

} ba;

#pragma pack(pop)

sizeof(struct ab) = 8 bytes

sizeof(struct ba) = 5 bytes

(Vì #pragma pack(1) loại bỏ padding nên các trường được sắp liên tục từng byte.)

**struct ab** 

struct {

`    `int a;   // 4 byte

`    `char b;  // 1 byte

} ab;

Trình biên dịch **căn chỉnh bộ nhớ theo kiểu lớn nhất trong struct** → ở đây là int (4 byte).

a chiếm 4 byte (offset 0 → 3), b chiếm 1 byte (offset 4), sau đó thêm 3 byte padding để kích thước tổng là bội số của 4.

Tổng cộng: 4 (int) + 1 (char) + 3 (padding) = 8 byte

=> sizeof(struct ab) = 8 bytes

**struct ba (có #pragma pack(1))**

#pragma pack(push, 1)

struct {

`    `char a;  // 1 byte

`    `int b;   // 4 byte

} ba;

#pragma pack(pop)

#pragma pack(1) bảo trình biên dịch không thêm padding, tức là các thành viên được đặt liền kề nhau từng byte. Do đó: 1 + 4 = 5 byte

=> sizeof(struct ba) = 5 bytes

32\. sizeof(mystruct) sẽ in ra gì?

typedef struct {

`    `char x;

`    `int y;

} mystruct;

Trình biên dịch **căn chỉnh dữ liệu (alignment)** để phù hợp với loại lớn nhất trong struct (int = 4 byte).\
→ Giữa x và y sẽ có **3 byte padding** để y bắt đầu ở địa chỉ chia hết cho 4

|Thành phần|Kích thước|
| :- | :- |
|x|1 byte|
|Padding|3 byte|
|y|4 byte|
|Tổng cộng|8 byte|

sizeof(mystruct) = 8

33\. sizeof(struct A) là bao nhiêu trên hệ thống 32-bit?

struct A {

`    `char a;

`    `int b;

`    `short c;

};

|Thành phần|Kích thước (byte)|Offset|
| :-: | :-: | :-: |
|a|1|0|
|(padding)|3|1-3|
|b|4|4-7|
|c|2|8-9|
|(padding)|2|10-11|

34\. Ảnh hưởng của #pragma pack(1) là gì? Kết quả sizeof(struct B) là bao nhiêu trên hệ thống 32-bit?

#pragma pack(push, 1)

struct B {

`    `char a;

`    `int b;

`    `short c;

};

#pragma pack(pop)

sizeof(struct B) = 7

Ý nghĩa của #pragme pack(1):

Dòng này ép compiler căn chỉnh các trường dữ liệu trong struct theo biên 1 byte (tức là không chèn padding giữa các trường).

Mọi thành phần sẽ được xếp liên tiếp trong bộ nhớ, không có khoảng trống để tối ưu tốc độ truy cập.

|Thành phần|Kích thước (byte)|Offset|
| :-: | :-: | :-: |
|a|1|0|
|b|4|1|
|c|2|5|

Tổng cộng: 7 byte.

35\. Tính sizeof(struct Outer) trên hệ thống 32-bit.

struct Inner {

`    `char c;

`    `int d;

};

struct Outer {

`    `int a;

`    `struct Inner in;

`    `char e[3];

};

sizeof(struct Inner) = 8

sizeof(struct Outer) = 16

1\. struct Inner

struct Inner {

`    `char c;  // 1 byte

`    `int d;   // 4 byte

};

|Thành phần|Kích thước|
| :-: | :-: |
|c|1|
|padding|3|
|d|4|
|tổng|8  byte|

2\. struct Outer

struct Outer {

`    `int a;

`    `struct Inner in;

`    `char e[3];

};

|Thành phần|Kích thước|Offset|
| :-: | :-: | :-: |
|a|4|0 - 3|
|in|8|4 – 11|
|e[3]|3|12 – 14|
|(padding)|1||
|Tổng|16 byte||
=>sizeof(struct Outer) = 16

36\. Trong đoạn mã sau, ab.b có giá trị là bao nhiêu?

union data {

`    `int a;

`    `char b;

} ab;

ab.a = 64;

ab.a = 2500; // 0x09C4

2500 ở hệ thập phân = 0x09C4 ở hệ 16.

byte0 = 0xC4

byte1 = 0x09

byte2 = 0x00

byte3 = 0x00

b dùng **byte đầu tiên** của union — tức byte0.

→ b = 0xC4.

37\. sizeof(struct Test) là bao nhiêu trên hệ thống 32-bit?

union Data {

`    `int i;

`    `char c[4];

};

struct Test {

`    `char flag;

`    `union Data data;

};

Size of struct Test: 8 byte

1\.union Data:\
Có 2 thành viên: int i (4 byte) và char c[4] (4 byte) → sizeof(union Data) = 4 (kích thước bằng thành viên lớn nhất).

2\.struct Test:\
Gồm:

char flag;     // 1 byte

union Data data; // 4 byte

Nhưng do **quy tắc căn hàng bộ nhớ (alignment), trình biên dịch thường chèn thêm padding** sau flag để data bắt đầu tại địa chỉ chia hết cho 4.

→ Thông thường:

flag : 1 byte

padding : 3 byte

data : 4 byte

Tổng = 8 byte

38\. Kết quả khác nhau như thế nào giữa little-endian và big-endian?

-) Little endian:

Bytes in memory (in increasing address order):

byte[0] = 0x78

byte[1] = 0x56

byte[2] = 0x34

byte[3] = 0x12

-) Big endian:

Sending bytes in Big-Endian order:

0x12

0x34

0x56

0x78

**Little-endian:** lưu LSB trước → đọc ngược khi truyền.

**Big-endian:** lưu MSB trước → đọc đúng thứ tự tự nhiên.

39\. sizeof(struct Flags) là bao nhiêu?

struct Flags {

`    `unsigned int a : 1;

`    `unsigned int b : 3;

`    `unsigned int c : 4;

};

Size of struct Flags: 4 bytes

unsigned int a : 1; — chiếm 1 bit

unsigned int b : 3; — chiếm 3 bit

unsigned int c : 4; — chiếm 4 bit

Tổng cộng là 8 bit = 1 byte, tuy nhiên compiler không cho phép struct có kích thước nhỏ hơn đơn vị của kiểu chứa bit field (ở đây là unsigned int, thường là 4 byte).

→ Vì vậy toàn bộ các bit field a, b, c được gói vào **một ô unsigned int (4 byte)**.

40\. 

1\. Giá trị flag, mode, value sẽ in ra bao nhiêu (giả sử hệ thống little-endian)?

2\. Tại sao giá trị thay đổi khi chạy trên big-endian?

3\. Giải thích cách compiler ánh xạ bit field vào raw.

union Data {

`    `struct {

`        `unsigned int flag  : 3;

`        `unsigned int mode  : 5;

`        `unsigned int value : 8;

`    `} info;

`    `unsigned short raw;

};

int main(void) {

`    `union Data d;

`    `d.raw = 0xABCD;

`    `printf("flag=%u, mode=%u, value=%u\n", d.info.flag, d.info.mode, d.info.value);

}

1\.

Raw value = 0xABCD =>0b 1010 1011 1100 1101

flag  = 5 => 101

mode  = 25 => 11001

value = 171 => 1010 1011

2\. Tại sao giá trị thay đổi khi chạy trên big-endian?

Raw value = 0xABCD =>0b 1010 1011 1100 1101

flag  = 5 => 101

mode  = 11 => 01011

value = 205 => 1100 1101

Trên Little-Endian: dữ liệu đọc bắt đầu từ byte thấp → bit thấp → bit cao.

Trên Big-Endian: dữ liệu đọc từ byte cao → bit cao → bit thấp.

41\.

1\. sizeof(struct Packet) là bao nhiêu trên 32-bit?

2\. Giải thích tại sao sizeof không phải luôn bằng 2?

3\. Nếu ta gán data.raw = 0xAB, giá trị của id, type, err lần lượt là gì?

struct Packet {

`    `unsigned char header;

`    `union {

`        `struct {

`            `unsigned int id   : 4;

`            `unsigned int type : 3;

`            `unsigned int err  : 1;

`        `} bits;

`        `unsigned char raw;

`    `} data;

};

1\.

struct Flags {

`    `unsigned int a : 1;

`    `unsigned int b : 3;

`    `unsigned int c : 4;

};

Tổng cộng 1+3+4 =8 bit =1 byte

Tuy nhiên unsigned int có alignment = 4 byte

=> size of struct bits = 4 byte

=> size of struct data = 8 byte

sizeof(struct Packet) = 8 bytes

sizeof(header)        = 1 bytes

sizeof(data)          = 4 bytes

2\.

Tùy theo kiến trúc hệ thống

3\.

err  = 1

type = 2

id   = 11

42\.

union Config {

`    `struct {

`        `unsigned int enable : 1;

`        `unsigned int speed  : 2;

`        `unsigned int mode   : 3;

`    `} normal;

`    `struct {

`        `unsigned int secure : 1;

`        `unsigned int key    : 7;

`    `} security;

};

1\. sizeof(union Config) là bao nhiêu?

2\. Tại sao cả hai struct đều có cùng vùng nhớ?

3\. Nếu gán security.key = 0x7F, giá trị normal.mode có thay đổi không?

1\.

Size of struct normal:   4 bytes

Size of struct security: 4 bytes

Size of union Config:    4 bytes

2\.

union = **một vùng nhớ duy nhất** chia sẻ cho tất cả member.

sizeof(union) = kích thước member lớn nhất (đã tính căn chỉnh).

Khi bạn ghi vào một member, bạn đang thực tế ghi vào vùng nhớ của toàn bộ union

3\.

Giá trị thay bằng 7

security.secure = 0

security.key    = 0x7F

normal.enable = 0

normal.speed  = 3

normal.mode   = 7

0x7F = 0111 1111

43\.

typedef union {

`    `struct {

`        `unsigned int EN   : 1;

`        `unsigned int MODE : 2;

`        `unsigned int RSV  : 1;

`        `unsigned int CLK  : 4;

`    `} bits;

`    `unsigned char reg;

} CTRL\_REG;

int main(void) {

`    `CTRL\_REG ctrl = { .reg = 0xB2 };

`    `printf("EN=%u, MODE=%u, CLK=%u\n", ctrl.bits.EN, ctrl.bits.MODE, ctrl.bits.CLK);

}

1\. In ra kết quả gì (với little-endian)?

2\. Giải thích tại sao việc truy cập ctrl.bits và ctrl.reg lại ảnh hưởng trực tiếp nhau?

3\. Nếu muốn MODE chiếm bit 4–5 thay vì 1–2, sửa khai báo thế nào?


1\.

0xB2 =1011 0010

EN=0, MODE=1, CLK=11

2\.

Bởi vì chúng nằm **trong cùng một union**.

Trong union, **mọi thành viên dùng chung cùng vùng nhớ**.

ctrl.reg là biểu diễn 8 bit thô của thanh ghi.

ctrl.bits là một “ánh xạ bitfield” lên cùng vùng nhớ đó.

Nên:

Khi gán ctrl.reg = 0xB2;, các bit trong vùng nhớ đó thay đổi.

Lúc này, ctrl.bits đọc đúng các bit tương ứng trong vùng nhớ đó.

Ngược lại, nếu ta gán ctrl.bits.MODE = 3;, giá trị trong ctrl.reg cũng thay đổi tương ứng.

3\.

typedef union {

`    `struct {

`        `unsigned int EN   : 1;  // bit0

`        `unsigned int RSV  : 3;  // bit1–3

`        `unsigned int MODE : 2;  // bit4–5

`        `unsigned int CLK  : 2;  // bit6–7

`    `} bits;

`    `unsigned char reg;

} CTRL\_REG;

44\.

1\. sizeof(union Frame) là bao nhiêu?

2\. Nếu bytes.low = 0xAA và bytes.high = 0xBB, giá trị của info.len, info.type, info.crc là gì?

3\. Giải thích tại sao giá trị có thể khác nhau giữa compiler (GCC vs ARMCC)?

union Frame {

`    `struct {

`        `unsigned short len  : 10;

`        `unsigned short type : 3;

`        `unsigned short crc  : 3;

`    `} info;

`    `struct {

`        `unsigned char low;

`        `unsigned char high;

`    `} bytes;

};

1\. sizeof(Frame) = 2 bytes

2\.

raw = 0xBBAA => 1011 1011 1010 1010

len = 938, type = 6, crc = 5

3\.
### (a) Bit order trong một byte
Mỗi compiler có thể chọn:

- **LSB first (bit thấp trước)** — bit 0 nằm ở phía phải (GCC trên ARM thường dùng kiểu này)
- **MSB first (bit cao trước)** — bit 0 nằm ở phía trái (ARMCC có thể dùng tùy cấu hình)

Khi đó, cùng một giá trị 0xBBAA nhưng các bitfield sẽ được **cắt theo hướng khác**, dẫn đến khác giá trị.
### (b) Endianness (byte order)
Endianness ảnh hưởng **thứ tự byte**, còn bitfield order ảnh hưởng **thứ tự bit trong byte**.

- **Little-endian**: byte thấp (low) ở địa chỉ nhỏ hơn
- **Big-endian**: byte cao (high) ở địa chỉ nhỏ hơn





