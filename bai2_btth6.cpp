#include <stdio.h>
#include <stdlib.h>

// Hàm nhap mang
void nhapMang(int *arr, int size) {
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", (arr + i));
    }
}

// Hàm in mang
void inMang(int *arr, int size) {
    printf("Cac phan tu cua mang la:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

// Hàm giai phóng bo nho
void giaiPhongBoNho(int *arr) {
    free(arr);
}

int main() {
    int size;
    printf("Nhap kich thuoc cua mang: ");
    scanf("%d", &size);

    // Cap phát bo nho cho mang bang malloc hoac calloc
    int *arr;

    // Su dung malloc
    // arr = (int *)malloc(size * sizeof(int));

    // Su dung calloc
    arr = (int *)calloc(size, sizeof(int));

    // Kiem tra xem bo nho dã duoc cap phát thành công hay không
    if (arr == NULL) {
        printf("Khong du bo nho cho mang.\n");
        return 1; // Ket thúc chuong trình voi mã lai 1
    }

    // Gui các chuc nang
    nhapMang(arr, size);
    inMang(arr, size);

    // Thuc hien các thao tác khác trên mang neu can

    // Giai phóng bo nho
    giaiPhongBoNho(arr);

    return 0;
}
