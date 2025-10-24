**1.Bitwise**

Câu hỏi 1:Làm thế nào để bật (set) một bit cụ thể trong một biến?

Dùng toán tử OR (|): x |= (1 << n);

Câu hỏi 2:Làm thế nào để đảo (toggle) một bit cụ thể trong một biến?

Dùng toán tử XOR (^): x ^= (1 << n);

Câu hỏi 3: Làm thế nào để kiểm tra một bit cụ thể đã được bật hay chưa?

Dùng toán tử AND (&): if (x & (1 << n))...

Câu hỏi 4: Làm thế nào để hoán đổi hai số mà không cần biến thứ ba?

Dùng XOR swap: a ^= b; b ^= a; a ^= b;

Câu hỏi 5:Làm thế nào để kiểm tra một số có phải là lũy thừa của 2 hay không?

Số n là lũy thừa của 2 nếu n & (n - 1) == 0;

Câu hỏi 6: Làm thế nào để đếm số bit 1 trong biểu diễn nhị phân của một số?

Dùng vòng lặp hoặc \_\_builtin\_popcount(n);

Câu hỏi 7: Làm thế nào để kiểm tra một số là chẵn hay lẻ?

Kiểm tra bit 0: if (n & 1) => lẻ;

Câu hỏi 8: Làm thế nào để tìm bù 2 (2’s complement) của một số nhị phân?

Bù 2 = đảo bit (~n) + 1;

Câu hỏi 9: Làm thế nào để kiểm tra hai số có bằng nhau hay không mà không dùng toán tử so sánh?

Dùng XOR: if ((a ^ b) == 0) => bằng nhau;

Câu hỏi 10: Làm thế nào để tìm bit có trọng số lớn nhất (Most Significant Bit - MSB)

Tìm MSB bằng log2(n) hoặc vòng lặp dịch bit;

Câu hỏi 11: Làm thế nào để tìm bit có trọng số nhỏ nhất (Least Significant Bit - LSB)?

Tìm LSB bằng công thức n & (-n);

Câu hỏi 12: Làm thế nào để tắt bit 1 ở ngoài cùng bên phải?

Tắt bit phải nhất: x = x & (x - 1);

Câu hỏi 13: Làm thế nào để cô lập bit 1 ở ngoài cùng bên phải?

Cô lập bit phải nhất: x & (-x);

Câu hỏi 14: Làm thế nào để kiểm tra một số có phải là bội số của 8 hay không?

Kiểm tra nếu n % 8 == 0 hoặc (n & 0x7) == 0;

1\.1. Thêm

1\. Ý nghĩa của typedef trong các trường hợp sử dụng là gì?

typedef là một **từ khóa trong C** dùng để **đặt tên mới (bí danh)** cho kiểu dữ liệu có sẵn hoặc phức tạp.

-) Giúp việc khai báo, dùng code trở nên gọn hơn

Ví dụ:

typedef unsigned int uint;

Thay vì ghi unsigned int dài dòng thì giờ chỉ cần gõ ngắn lại uint.

2\. Có vấn đề gì khi so sánh hai giá trị số thực (if(a == b))?

Nên so sánh hiệu của chúng với một giá trị rất nhỏ (epsilon). 

Máy tính **không thể biểu diễn chính xác mọi số thập phân** trong hệ nhị phân.\
Một số đơn giản như 0.1 trong C thực ra được lưu xấp xỉ như:

0\.100000001490116119384765625

Do đó, khi cộng hoặc nhân số thực, lỗi làm tròn nhỏ sẽ tích lũy theo thời gian.

3\. Macro là gì? Các ứng dụng điển hình là gì?

Macro là đoạn mã được thay thế trước khi biên dịch. Dùng để định nghĩa hằng số, tạo hàm macro

=>Khi viết #define ..., trình biên dịch chưa chạy ngay** mà trước đó, trình tiền xử lý** sẽ tìm và thay thế tất cả chỗ dùng macro bằng đúng nội dung bạn định nghĩa.

**Macro đơn giản (constant macro)**

#define PI 3.1415926

#define MAX\_SIZE 100

Trước khi biên dịch, mọi PI trong code được **thay bằng 3.1415926**,\
và MAX\_SIZE thành 100.

**Macro có tham số (function-like macro)**

#define SQUARE(x) ((x) \* (x))

#define MAX(a,b)  ((a) > (b) ? (a) : (b))

Khi viết:

int y = SQUARE(3 + 1);

→ Trước khi biên dịch, C sẽ thay trực tiếp bằng:

int y = ((3 + 1) \* (3 + 1));

|Ứng dụng|Ví dụ|
| :- | :- |
|Định nghĩa hằng số|#define PI 3.14|
|Viết hàm ngắn gọn hơn|#define COMPARE(a, b)  ((a) > (b) ? 1 : ((a) < (b) ? -1 : 0))|
|Tránh lỗi lặp code||

4\. Sự khác biệt giữa const và #define là gì?

const: là biến thật, có kiểu dữ liệu, được cấp phát bộ nhớ.

#define: chỉ là thay thế văn bản, không kiểm tra kiểu.

Cả const và #define đều được dùng để khai báo giá trị hằng, nhưng **chúng hoạt động hoàn toàn khác nhau** trong chương trình C.

Từ khóa **const** được dùng để khai báo **một biến hằng thật sự**, nghĩa là nó **có kiểu dữ liệu cụ thể** (ví dụ: int, float, char, …), **được cấp phát bộ nhớ**, và được **kiểm tra kiểu dữ liệu** trong quá trình biên dịch.\
Khi khai báo bằng const, ta có thể giới hạn **phạm vi sử dụng (scope)** của hằng, ví dụ hằng có thể là biến cục bộ trong một hàm hoặc toàn cục trong một file. Ngoài ra, vì là biến thật nên ta có thể **truy cập địa chỉ** của nó hoặc **debug (xem giá trị)** trong quá trình chạy chương trình.

Ngược lại, **#define** là **chỉ thị tiền xử lý (preprocessor directive)**. Nó **không tạo ra biến thật**, mà chỉ **thay thế đoạn văn bản** trong mã nguồn trước khi trình biên dịch thực sự chạy. Do đó, #define **không có kiểu dữ liệu**, **không được kiểm tra lỗi kiểu**, và **không chiếm bộ nhớ**. Khi chương trình biên dịch, trình tiền xử lý sẽ tìm tất cả các từ khóa trùng với tên macro và **thay trực tiếp** bằng giá trị hoặc đoạn mã tương ứng.

Vì đặc tính này, #define thường được dùng cho **các giá trị cố định**, **địa chỉ phần cứng**, hoặc **macro ngắn gọn** trong lập trình nhúng, còn const thích hợp hơn cho **các hằng số logic** cần **an toàn kiểu dữ liệu** và **dễ bảo trì**.

🔹 **Tóm lại:**

|**Đặc điểm**|**const**|**#define**|
| :-: | :-: | :-: |
|Bản chất|Biến hằng thật sự|Lệnh tiền xử lý (macro)|
|Kiểu dữ liệu|Có kiểu cụ thể (int, float, …)|Không có kiểu|
|Bộ nhớ|Có thể được cấp phát|Không chiếm bộ nhớ|
|Kiểm tra lỗi|Có kiểm tra kiểu khi biên dịch|Không kiểm tra kiểu|
|Phạm vi (scope)|Theo khối hoặc file|Toàn cục trong file|
|Thời điểm xử lý|Khi biên dịch|Trước khi biên dịch|
|Debug|Có thể xem giá trị|Không xem được (vì bị thay thế)|

-----
💡 **Ví dụ:**

#define PI1 3.14

const float PI2 = 3.14;

int main() {

`    `printf("PI1 = %.2f\n", PI1); // Thay trực tiếp 3.14

`    `printf("PI2 = %.2f\n", PI2); // Biến hằng thật

`    `return 0;

}

Const là **biến hằng có kiểu dữ liệu**, được **kiểm tra lỗi và an toàn** khi biên dịch.\
#define chỉ là **thay thế văn bản trước khi biên dịch**, **không có kiểu**, **không kiểm tra lỗi**, nhưng **nhanh và tiện** cho macro.

5\. Hàm \_\_inline\_\_ là gì?

Là gợi ý cho trình biên dịch chèn mã hàm trực tiếp tại nơi gọi, giảm chi phí gọi hàm nhưng có thể làm tăng kích thước mã.
### **Mục đích của \_\_inline\_\_**
Thông thường, khi bạn gọi một hàm, CPU phải:

1. Lưu địa chỉ hiện tại và tham số.
1. Nhảy đến địa chỉ của hàm.
1. Thực thi hàm.
1. Quay lại vị trí gọi ban đầu.

Quy trình này tốn thời gian (đặc biệt trong các vòng lặp hoặc hàm nhỏ được gọi nhiều lần).\
Khai báo \_\_inline\_\_ giúp **giảm chi phí lời gọi hàm** bằng cách **chèn trực tiếp nội dung hàm vào mã máy tại chỗ gọi**.

\_\_inline\_\_ void toggleLED(void) {

`    `GPIOB->PTOR = (1 << 5); // Ví dụ: đảo trạng thái LED

}

Khi gọi toggleLED();, trình biên dịch có thể thay thế bằng trực tiếp dòng lệnh GPIOB->PTOR = (1 << 5); thay vì nhảy tới một hàm riêng.

## 1\. Tăng kích thước mã (Code size bloat)
Khi bạn khai báo hàm là inline, **nội dung hàm sẽ được chèn trực tiếp vào mọi nơi nó được gọi**.\
Nếu hàm được gọi nhiều lần (ví dụ trong nhiều vòng lặp hoặc nhiều file), thì **mỗi lần gọi là một bản sao** của hàm trong mã máy.

**Ví dụ:**

\_\_inline\_\_ void LED\_Toggle(void) {

`    `GPIOB->PTOR = (1 << 5);

}

Nếu bạn gọi LED\_Toggle() 1000 lần ở nhiều nơi khác nhau, thì dòng GPIOB->PTOR = (1 << 5); sẽ được **chèn 1000 lần**,\
→ chương trình to hơn, **chiếm nhiều flash/ROM hơn** (đặc biệt nghiêm trọng trong vi điều khiển như S32K144).

**Hàm thường** chỉ lưu một bản sao trong bộ nhớ → tiết kiệm hơn.
## 2\. Inline không đảm bảo nhanh hơn
Inline **chỉ là gợi ý cho trình biên dịch**, chứ không bắt buộc.\
Trình biên dịch có thể bỏ qua nếu:

- Hàm quá dài hoặc có cấu trúc phức tạp (if, switch, vòng lặp lớn...).
- Mức tối ưu hóa (-O2, -O3) đã tự động quyết định cách tốt hơn.

Vì vậy, **không nên “ép” inline mọi thứ**, vì đôi khi trình biên dịch đã tự tối ưu tốt hơn.

3\. Khó debug hơn

Khi dùng inline:

- Trình gỡ lỗi (debugger) **không thể “bước vào” (step into)** hàm như bình thường, vì nó **không tồn tại thực sự trong mã máy**.
- Stack trace (vết ngăn xếp) sẽ **không hiển thị tên hàm inline**, khiến việc tìm lỗi khó hơn.
## 4\. Phải định nghĩa trong header (.h)
Vì inline được chèn tại vị trí gọi, hàm inline **phải có sẵn định nghĩa tại thời điểm biên dịch** → thường đặt trong file header (.h).

Điều này có thể:

- Làm **file header nặng hơn**.
- Khi thay đổi hàm inline → **toàn bộ các file include nó phải biên dịch lại** → thời gian build lâu hơn.
## 5\. Không phù hợp cho hàm phức tạp hoặc có I/O
Hàm inline chỉ phù hợp cho các thao tác nhỏ, nhanh, **không có truy cập ngoại vi phức tạp hoặc gọi nhiều hàm khác**.\
Nếu inline hàm có **tác dụng phụ hoặc timing quan trọng (ví dụ thao tác GPIO, UART, delay)**, kết quả có thể khác mong đợi.

2\.Memory Management

Câu hỏi 1: Có những phân đoạn vùng nhớ nào?

1\. Stack (RAM): Biến local

2\. Heap (RAM): Dữ liệu cấp phát động (malloc, alloc, calloc)

3\. Initialize data (.data) (RAM): Biến static + global được khởi tạo giá trị khác 0

4\. Uinitialize data (.bss) (RAM): Biến static + global không được khởi tạo hoặc khởi tạo bằng 0.

5\. Text (.rodata) (ROM): Biến const toàn cục, code intructions

Câu hỏi 2: Tại sao cần chia bộ nhớ thành nhiều vùng?

Để quản lý dữ liệu hiệu quả, tách biệt dữ liệu tĩnh, động, mã lệnh, và biến tạm thời.

Câu hỏi 3: Biến toàn cục không khởi tạo nằm ở đâu?

.bss (Uninitialized Data Segment).

Câu hỏi 4: Hai biến global có cùng giá trị khởi tạo 0 và 10 — tại sao chúng không nằm trong cùng một vùng nhớ?

0 lưu ở .bss

10 lưu ở .data

·  a = 0 → Biến toàn cục có giá trị **0** → đặt trong **.bss**\
→ Vì tất cả các biến trong .bss đều được khởi tạo bằng 0 **tự động khi chương trình bắt đầu**, nên không cần lưu giá trị 0 trong file nhị phân.\
Điều này giúp **giảm kích thước file chương trình**.

·  b = 10 → Biến toàn cục có giá trị **khác 0** → đặt trong **.data**\
→ Vì giá trị khởi tạo (10) **phải được lưu sẵn** trong file nhị phân để khi nạp chương trình lên RAM, hệ thống có thể chép giá trị đó vào bộ nhớ

Câu hỏi 5: Khi chương trình gọi một hàm lồng nhau nhiều lần (đệ quy), vùng nhớ nào bị ảnh hưởng nhiều nhất?

Stack (do tạo nhiều stack frame có thể tràn stack)

Mỗi lần gọi đệ quy **→** một stack frame mới** được đẩy (push) lên Stack**.**\
Do đó, khi bạn gọi hàm đệ quy lồng nhau sâu,** vùng nhớ Stack sẽ phình to ra rất nhanh**.**

Câu hỏi 6: Tại sao biến const thường được đặt trong vùng .rodata thay vì .data?

Dữ liệu chỉ đọc, không cần ghi => giúp bảo vệ và tiết kiệm RAM.

Câu hỏi 7: Nếu bạn muốn dữ liệu tồn tại suốt vòng đời chương trình, bạn nên đặt nó ở vùng nhớ nào?

.data hoặc .bss

Câu hỏi 8: Tại sao vùng .bss không chiếm nhiều dung lượng trong file .bin, nhưng lại chiếm RAM khi chạy?

Khi trình biên dịch và linker tạo ra file thực thi (.elf, .bin, hoặc .hex):

- Vùng .data chứa giá trị khởi tạo thực tế, ví dụ 10, 5, 123, v.v.
- Còn vùng .bss chỉ cần ghi “kích thước cần cấp phát”, không cần ghi dữ liệu (vì toàn bộ đều là 0).

Do đó:

- File .bin không chứa dữ liệu 0 cho .bss → file nhỏ gọn hơn.
- Nhưng trong file vẫn có metadata (thông tin) để trình nạp biết rằng:\
  “Cần cấp phát cho .bss một vùng RAM có kích thước X byte và gán toàn bộ = 0 khi khởi động.”

.bss chỉ lưu thông tin kích thước, không chứa dữ liệu thực.

Câu hỏi 9: Điều gì xảy ra với Stack khi hàm kết thúc, nhưng biến static trong hàm đó vẫn được giữ giá trị?

Lưu trong .data không bị giải phóng khi stack pop.

Mỗi lần một hàm được gọi, trình biên dịch cấp phát vùng nhớ tạm thời trên Stack cho:

- Biến cục bộ (local variables)
- Tham số (parameters)
- Địa chỉ trả về, thanh ghi tạm, v.v.

Khi hàm kết thúc, Stack bị giải phóng (pop frame ra), toàn bộ biến cục bộ bị xóa.\
Vì vậy, biến cục bộ bình thường sẽ “biến mất” sau khi hàm kết thúc. Nhưng** biến static không nằm trên Stack, nên** nó không bị mất**.**

·  Trước khi chương trình chạy, hệ thống cấp phát sẵn vùng nhớ cho biến static trong .data hoặc .bss.

·  Khi hàm được gọi, nếu biến static chưa được khởi tạo, nó sẽ được khởi tạo đúng một lần duy nhất**.**

·  Sau đó, mỗi lần gọi hàm, biến static vẫn trỏ đến cùng một địa chỉ bộ nhớ**,** không phụ thuộc vào Stack.

Câu hỏi 10:

Lỗi Memory Leak xảy ra khi nào? Tại sao? Cách debug.

Xảy ra khi vùng nhớ được cấp phát bằng malloc/new nhưng không được free/delete. Dùng Valgrind hoặc AddressSanitizer (ASan)

Câu hỏi 11:

Lỗi Stack Overflow xảy ra khi nào? Tại sao? Cách debug.

Xảy ra khi chương trình sử dụng quá nhiều bộ nhớ stack, thường do đệ quy vô hạn hoặc khai báo mảng lớn trong hàm. Debug bằng gdb (backtrace).

Câu hỏi 12:

Lỗi Segmentation Fault xảy ra khi nào? Tại sao? Cách debug.

Khi truy cập vùng nhớ không hợp lệ (null, out of range). Dùng gdb để xem backtrace.

Câu hỏi 13:

Lỗi Stack Smashing là gì? Cách compiler phát hiện bằng cơ chế Canary.

Khi tràn vùng stack ghi đè biến return. Compiler bật bảo vệ -fstack-protector.

Câu hỏi 14:

Lỗi Heap Corruption là gì? Cách phát hiện bằng AddressSanitizer.

Khi ghi đè vùng nhớ cấp phát động. ASan hiển thị block lỗi.

Câu hỏi 15:

Lỗi Dangling Pointer là gì? Tại sao nguy hiểm? Cách khắc phục.

Con trỏ trỏ đến vùng nhớ đã bị giải phóng. Đặt con trỏ về NULL sau khi free.

Câu hỏi 16:

Khi nào nên dùng AddressSanitizer thay vì Valgrind để debug lỗi bộ nhớ?

Khi cần hiệu năng cao hơn, tích hợp vào build (Valgrind chậm hơn).

Câu hỏi 17: Lỗi Wild Pointer là gì?

Con trỏ không được gán địa chỉ hợp lệ. Cần khởi tạo = NULL.

**3.Storage Class**

1\. Các lớp lưu trữ (storage classes) là gì?

auto/static/extern/register

2\. Từ khóa auto dùng để làm gì? Khi nào thì dùng?

Trong ngôn ngữ C, từ khóa auto dùng để **khai báo biến cục bộ (local variable)** — tức là biến **nằm trong một khối lệnh (block)** như trong hàm, và **tự động được cấp phát và giải phóng bộ nhớ khi ra khỏi khối lệnh**.

3\. Từ khóa static dùng để làm gì? Khi nào thì dùng?

Từ khóa static trong C dùng để **duy trì giá trị của biến hoặc hàm trong suốt thời gian chạy chương trình**, đồng thời **giới hạn phạm vi truy cập** của nó.

Tùy theo vị trí khai báo, static có **2 trường hợp khác nhau**:

- Dùng **trong hàm** → giữ giá trị biến giữa các lần gọi hàm.
- Dùng **ngoài hàm (toàn cục)** → giới hạn phạm vi biến/hàm trong file hiện tại.

Khi nào nên dùng static

|<p>Mục đích</p><p></p>|Cách dùng|<p>Lợi ích</p><p></p>|
| :-: | :-: | :-: |
|Giữ giá trị giữa các lần gọi hàm|Dùng static trong hàm||

|Không cần biến toàn cục|
| :- |

||||
| :- | :- | :- |

| |
| :- |

||||
| :- | :- | :- |
|Giấu biến/hàm trong file|Dùng static ngoài hàm|Tránh trùng tên, tăng tính an toàn|
|Tối ưu RAM (trong nhúng)|||

|Dùng static cho biến cục bộ lớn nhưng cần giữ giá trị|
| :- |

||||
| :- | :- | :- |

||
| :- |

|||Không chiếm Stack|
| :- | :- | :- |

4\. Từ khóa extern dùng để làm gì? Khi nào thì dùng?

extern (external) là từ khóa dùng để khai báo biến hoặc hàm được định nghĩa ở nơi khác** (thường là ở một file .c khác).\
Nói cách khác, extern không tạo ra biến mới**, mà** chỉ thông báo cho trình biên dịch biết rằng biến đó tồn tại ở nơi khác**.**

Khi nào nên dùng extern

|<p>Tình huống</p><p></p>|Dùng extern để|
| :- | :- |
|Có nhiều file .c trong dự án|Chia sẻ biến toàn cục giữa các file|
|Muốn truy cập biến cấu hình chung|Khai báo biến trong file .h, định nghĩa trong .c|
|Muốn dùng hàm viết ở file khác|Khai báo hàm bằng extern (hoặc đơn giản include .h)|

5\. Từ khóa register dùng để làm gì? Khi nào thì dùng?

Biến khai báo với register được sử dụng cho các biến truy cập thường xuyên**,** ví dụ như biến đếm trong vòng lặp (for, while). Vì thanh ghi nằm ngay trong CPU, nên việc đọc/ghi dữ liệu nhanh hơn nhiều so với việc truy cập vào bộ nhớ chính (RAM).

Dùng register khi:

Biến được truy cập nhiều lần trong thời gian ngắn (như trong vòng lặp hoặc các phép tính liên tục).

Biến không cần địa chỉ của nó (vì biến trong thanh ghi không có địa chỉ cố định trong RAM).

a. Phạm vi (Scope):

- **auto**:
  - **Phạm vi** của biến cục bộ (auto) chỉ trong hàm hoặc khối mã mà nó được khai báo. Phạm vi này không thay đổi bởi vì auto chỉ ảnh hưởng đến kiểu dữ liệu của biến.
  - Nếu không có từ khóa nào khác (như static), biến mặc định có phạm vi là **local scope**.
- **static**:
  - Biến static có phạm vi là local (nếu khai báo trong hàm), nhưng vòng đời của nó kéo dài suốt chương trình, vì vậy giá trị của nó sẽ được duy trì giữa các lần gọi hàm.
- **extern**:
  - Biến hoặc hàm khai báo với extern có phạm vi toàn cục, tức là có thể truy cập ở bất kỳ nơi nào trong chương trình.
- **register**:
  - Biến register có phạm vi như một biến cục bộ, nhưng nó được khuyến khích lưu trữ trong thanh ghi CPU, giúp truy cập nhanh hơn. Tuy nhiên, với các trình biên dịch hiện đại, điều này không còn quá quan trọng nữa.

b. Vòng đời (LifeTime):

- **auto**: Biến auto có vòng đời tồn tại từ khi hàm được gọi cho đến khi hàm kết thúc. Bộ nhớ của nó được cấp phát trên stack.
- **static**: Biến static có vòng đời suốt chương trình, ngay cả khi hàm hoặc khối mã mà nó được khai báo kết thúc, giá trị của nó vẫn được lưu lại.
- **extern**: Biến extern có vòng đời suốt chương trình, vì nó tham chiếu đến biến được khai báo ở ngoài hàm hoặc ở file khác.
- **register**: Biến register có vòng đời như một biến cục bộ thông thường, nhưng có thể được truy cập nhanh hơn vì nó được lưu trữ trong các thanh ghi CPU (nếu có).

**c. Vị trí lưu trữ (Storage):**

- **auto**: Biến auto được lưu trữ trong **stack**. Khi biến được khai báo, bộ nhớ cho nó được cấp phát trên stack và sẽ bị giải phóng khi hàm kết thúc.
- **static**: Biến static được lưu trữ trong **data segment** (một phần bộ nhớ tĩnh), vì vậy giá trị của nó tồn tại suốt chương trình, ngay cả khi hàm kết thúc.
- **extern**: Biến extern không có bộ nhớ riêng, mà sẽ tham chiếu đến một biến toàn cục đã được khai báo ở ngoài. Bộ nhớ cho biến này sẽ được cấp phát trong data segment.
- **register**: Biến register được lưu trữ trong **registers** (thanh ghi CPU), nếu có, nhằm tăng tốc độ truy cập. Tuy nhiên, nếu không thể lưu trữ trong thanh ghi, nó sẽ bị chuyển thành một biến thông thường lưu trên stack.


6\. Từ khóa volatile dùng để làm gì? Khi nào thì dùng?

Ngăn compiler tối ưu hóa, thường dùng với thanh ghi phần cứng;
### **Từ khóa volatile trong C:**
**1. Công dụng**:

Từ khóa volatile trong C được sử dụng để báo cho trình biên dịch rằng giá trị của một biến có thể thay đổi bất kỳ lúc nào mà không có sự can thiệp của mã chương trình. Điều này ngăn trình biên dịch thực hiện tối ưu hóa cho phép chương trình không thực hiện việc truy cập lại bộ nhớ khi giá trị của biến thay đổi ngoài sự kiểm soát của mã chương trình.

**Ví dụ**:

volatile int flag;

while (!flag) {

`    `// Thực hiện công việc khi flag chưa được đặt

}

Trong ví dụ này, flag có thể thay đổi do một tín hiệu phần cứng (ví dụ, ngắt) hoặc một luồng khác trong lập trình đa luồng. Nếu không có từ khóa volatile, trình biên dịch có thể tối ưu hóa vòng lặp và giả định rằng flag không thay đổi, dẫn đến vòng lặp vô hạn hoặc không chính xác.

**2. Khi nào dùng volatile**:

Làm việc với phần cứng**:** Khi bạn tương tác với các thanh ghi phần cứng hoặc bộ điều khiển thiết bị, giá trị của các thanh ghi này có thể thay đổi mà không có sự can thiệp của mã chương trình, ví dụ, khi có ngắt.

Lập trình đa luồng: Khi một luồng có thể thay đổi giá trị của một biến mà các luồng khác cũng truy cập. Nếu không có volatile, trình biên dịch có thể tối ưu hóa không đúng cách và dẫn đến kết quả không chính xác.

Làm việc với bộ đệm và bộ nhớ chia sẻ**:** Biến có thể thay đổi bất kỳ lúc nào (ví dụ, bộ đệm phần cứng, dữ liệu từ các thiết bị ngoại vi).
### **1. Phạm vi (Scope):**
**volatile không thay đổi phạm vi của biến**. Biến vẫn có phạm vi như bình thường, có thể là phạm vi toàn cục hoặc cục bộ. Phạm vi này vẫn theo quy tắc thông thường của C:

- Biến cục bộ có phạm vi trong hàm hoặc khối mã.
- Biến toàn cục có phạm vi toàn chương trình.
### **2. Vòng đời (LifeTime):**
**Vòng đời của biến volatile không thay đổi**. Biến volatile có vòng đời như bất kỳ biến thông thường nào:

- Biến cục bộ tồn tại trong suốt thời gian thực thi hàm mà nó được khai báo.
- Biến toàn cục tồn tại suốt chương trình.
- Biến tĩnh (static) có vòng đời suốt chương trình.

Từ khóa volatile chỉ ảnh hưởng đến cách mà trình biên dịch xử lý các phép toán liên quan đến biến, không ảnh hưởng đến vòng đời của biến.
### **3. Vị trí lưu trữ (Storage):**
**Vị trí lưu trữ của biến volatile** không thay đổi. Biến có thể được lưu trữ trong **stack**, **heap**, hoặc **data segment**, tùy thuộc vào cách mà bạn khai báo biến:

Biến toàn cục: Lưu trữ trong **data segment**.

Biến cục bộ: Lưu trữ trong **stack**.

Biến tĩnh (static): Lưu trữ trong **data segment**, nhưng có vòng đời suốt chương trình.

Từ khóa volatile chỉ yêu cầu trình biên dịch không tối ưu hóa việc truy cập hoặc thay đổi giá trị của biến này, và không ảnh hưởng đến vị trí lưu trữ thực tế của biến trong bộ nhớ.
### **Tóm lại:**
- **volatile** dùng để ngăn trình biên dịch tối ưu hóa biến, đảm bảo rằng mỗi lần truy cập vào biến sẽ được thực hiện và giá trị không bị lưu trữ lại.
- **Khi nào dùng**: Dùng khi làm việc với phần cứng, các tín hiệu ngắt, trong lập trình đa luồng, hoặc khi biến có thể thay đổi ngoài chương trình chính (ví dụ, bộ đệm phần cứng).
- **Phạm vi (Scope)**, **vòng đời (LifeTime)**, và **vị trí lưu trữ (Storage)** của biến không bị ảnh hưởng bởi volatile, chỉ có cách trình biên dịch xử lý biến này khi tối ưu hóa mới khác đi

4,Data Types

1\. Khác nhau giữa struct và array?

Array chứa các phần tử cùng kiểu; struct chứa các biến khác kiểu.

2\. Kích thước struct được tính như thế nào?

Tổng kích thước các thành viên + padding (theo alignment).

3\. Căn chỉnh bộ nhớ trong struct hoạt động như thế nào?

4\. Padding là gì trong struct? Làm sao tránh padding?

1\. Là byte trống được chèn để dữ liệu căn hàng theo bộ nhớ (alignment).

2\. Dùng #pragma pack(1) hoặc \_\_attribute\_\_((packed))

5\. Có thể gán trực tiếp giữa 2 struct cùng kiểu không?

Có thể (copy toàn bộ nội dung byte theo byte).

6\. Struct có thể so sánh bằng toán tử == không?

Không trong C (chỉ có thể so sánh từng trường hoặc dùng memcmp()).

7\. Struct có thể dùng làm tham số hàm không?

Có, nhưng thường truyền bằng con trỏ để tiết kiệm bộ nhớ.

8\. #pragma pack(1) có ý nghĩa gì?

Ý nghĩa của #pragma pack(1) trong C:

#pragma pack(1) là một chỉ thị của trình biên dịch C/C++ được sử dụng để điều chỉnh **cách bộ biên dịch sắp xếp bộ nhớ** (memory alignment) cho các kiểu dữ liệu, đặc biệt là khi làm việc với các cấu trúc (struct) và kiểu dữ liệu liên quan.

**#pragma pack(1)** yêu cầu trình biên dịch sắp xếp bộ nhớ với độ căn chỉnh 1 byte. Điều này có nghĩa là các thành phần của một cấu trúc (hoặc lớp) sẽ được sắp xếp liên tiếp mà không có khoảng trống bổ sung giữa chúng.

Mặc định, trình biên dịch sẽ tự động căn chỉnh các thành phần trong cấu trúc vào các địa chỉ bộ nhớ mà có thể tối ưu hóa hiệu suất truy cập, nhưng điều này có thể tạo ra một số khoảng trống (padding) giữa các thành phần. Khi bạn sử dụng #pragma pack(1), bạn đang yêu cầu trình biên dịch bỏ qua các padding này và căn chỉnh các thành phần của cấu trúc với độ chính xác 1 byte.

9\. Khi truyền struct vào hàm, có thể bị padding sai khi giao tiếp giữa vi điều khiển khác nhau không?

Có. Cần \_\_attribute\_\_((packed)) hoặc cấu hình #pragma pack.

10\. Union là gì?

Kiểu dữ liệu đặc biệt cho phép nhiều thành viên chia sẻ cùng một vùng nhớ.

11\. Kích thước của union là bao nhiêu?

Bằng kích thước của thành viên lớn nhất.

12\. Union dùng khi nào?

Khi cần tiết kiệm bộ nhớ, ví dụ dữ liệu có thể ở nhiều dạng khác nhau nhưng chỉ dùng một tại một thời điểm.

13\. Nếu ghi vào một thành viên union rồi đọc thành viên khác thì sao?

Không xác định (undefined behavior).

14\. Có thể khởi tạo nhiều thành viên của union cùng lúc không?

Không, chỉ một thành viên tại một thời điểm.

15\. Union có thể chứa struct không?

Có, và ngược lại (struct có thể chứa union).

16\. Union thường dùng trong embedded để làm gì?

Dùng để map bit/byte của thanh ghi hoặc giao tiếp protocol.

17\. Enum là gì?

Kiểu dữ liệu được đặt tên cho các hằng số nguyên.

18\. Mặc định giá trị đầu tiên của enum là gì?

0

19\. Enum có thể gán giá trị cụ thể cho phần tử không?

Có

20\. Giá trị của phần tử tiếp theo nếu không chỉ định?

Tự động tăng 1 từ giá trị trước

21\. Tại sao nên dùng enum thay vì #define?

Giúp dễ debug, có phạm vi rõ ràng, được trình biên dịch kiểm tra.

22\. Enum có thể âm không?

Có, vì enum lưu dưới dạng int signed.

