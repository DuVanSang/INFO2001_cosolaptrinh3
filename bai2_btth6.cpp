#include <stdio.h>
#include <stdlib.h>

// H�m nhap mang
void nhapMang(int *arr, int size) {
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", (arr + i));
    }
}

// H�m in mang
void inMang(int *arr, int size) {
    printf("Cac phan tu cua mang la:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

// H�m giai ph�ng bo nho
void giaiPhongBoNho(int *arr) {
    free(arr);
}

int main() {
    int size;
    printf("Nhap kich thuoc cua mang: ");
    scanf("%d", &size);

    // Cap ph�t bo nho cho mang bang malloc hoac calloc
    int *arr;

    // Su dung malloc
    // arr = (int *)malloc(size * sizeof(int));

    // Su dung calloc
    arr = (int *)calloc(size, sizeof(int));

    // Kiem tra xem bo nho d� duoc cap ph�t th�nh c�ng hay kh�ng
    if (arr == NULL) {
        printf("Khong du bo nho cho mang.\n");
        return 1; // Ket th�c chuong tr�nh voi m� lai 1
    }

    // Gui c�c chuc nang
    nhapMang(arr, size);
    inMang(arr, size);

    // Thuc hien c�c thao t�c kh�c tr�n mang neu can

    // Giai ph�ng bo nho
    giaiPhongBoNho(arr);

    return 0;
}
