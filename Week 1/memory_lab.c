#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void stackOverflow(int count) {
    int array[100000]; 
    printf("Recursion depth: %d\n", count);
    stackOverflow(count + 1);
}

void memoryLeak() {
    int* ptr = (int*)malloc(sizeof(int) * 100000000000);  // Cấp phát 400MB
    if (ptr == NULL) {
        printf("Khong du bo nho!\n");
        return;
    }

    // Không có free(ptr); => Memory leak

    printf("Da cap phat bo nho xong, nhung khong giai phong (memory leak)\n");
}

void outofMemory() {
    int count = 0;

    while (1) {
        // Cấp phát 1KB (1024 byte)
        void *ptr = malloc(1024*1024*1024);

        // Kiểm tra nếu malloc thất bại thì hết bộ nhớ
        if (ptr == NULL) {
            printf("\nOut of Memory sau %d lan cap phat \n", count);
            break;
        }

        // Không free(ptr); gây memory leak
        count++;

        // In log mỗi 1000 vòng
        if (count % 1000 == 0) {
            printf("Đã cấp phát %d KB ...\n", count);
        }
    }
}

int main(int argc, char *argv[]) {

    if (argc!=2) {
        printf("Nhap sai cu phap");
        return 1;
    }

    if (strcmp(argv[1],"stack_overflow")==0) {
        stackOverflow(1);
    }

    else if (strcmp(argv[1],"memory_leak")==0) {
        memoryLeak();
    }

    else if (strcmp(argv[1],"out_of_memory")==0) {
        outofMemory();
    }

    else {
        printf("Nhap sai cu phap");
        return 1;
    }
    return 0;
}