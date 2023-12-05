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

// H�m t�m kiem phan tu trong mang
int timKiem(int *arr, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == key) {
            return i; // Tra ve chu so cua phan tu neu t�m thay
        }
    }
    return -1; // Tra ve -1 neu kh�ng t�m thay
}

int main() {
    int size;
    printf("Nhap kich thuoc cua mang: ");
    scanf("%d", &size);

    // Cap ph�t bo nho cho mang
    int *arr = (int *)malloc(size * sizeof(int));

    // Gui c�c chuc nang
    nhapMang(arr, size);
    inMang(arr, size);

    int key;
    printf("Nhap phan tu can tim kiem: ");
    scanf("%d", &key);

    int ketQua = timKiem(arr, size, key);
    if (ketQua != -1) {
        printf("Tim thay phan tu %d tai vi tri %d trong mang.\n", key, ketQua);
    } else {
        printf("Khong tim thay phan tu %d trong mang.\n", key);
    }

    // Giai ph�ng bo nho d� cap ph�t cho mang
    free(arr);

    return 0;
}
