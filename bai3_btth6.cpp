#include <stdio.h>
#include <stdlib.h>

// �inh nghia cau tr�c Book
struct Book {
    char ten[50];
    char tacGia[50];
    float gia;
};

// H�m nhap th�ng tin mot cuon s�ch
void nhapThongTinSach(struct Book *sach) {
    printf("Nhap ten sach: ");
    scanf("%s", sach->ten);

    printf("Nhap tac gia: ");
    scanf("%s", sach->tacGia);

    printf("Nhap gia sach: ");
    scanf("%f", &sach->gia);
}

// H�m hien thi th�ng tin mot cuon s�ch
void hienThiThongTinSach(struct Book *sach) {
    printf("Thong tin sach:\n");
    printf("Ten sach: %s\n", sach->ten);
    printf("Tac gia: %s\n", sach->tacGia);
    printf("Gia: %.2f\n", sach->gia);
}

int main() {
    int soLuongSach;

    // Nhap so luong s�ch
    printf("Nhap so luong sach: ");
    scanf("%d", &soLuongSach);

    // Cap ph�t dung mang s�ch
    struct Book *dsSach = (struct Book *)malloc(soLuongSach * sizeof(struct Book));

    // Kiem tra xem bo nho d� duoc cap ph�t th�nh c�ng hay kh�ng
    if (dsSach == NULL) {
        printf("Khong du bo nho cho mang.\n");
        return 1; // Ket th�c chuong tr�nh voi m� lai 1
    }

    // Nhap th�ng tin cho tung cuon s�ch
    for (int i = 0; i < soLuongSach; i++) {
        printf("\nNhap thong tin cho cuon sach thu %d:\n", i + 1);
        nhapThongTinSach(&dsSach[i]);
    }

    // Hien thi th�ng tin cho tung cuon s�ch
    for (int i = 0; i < soLuongSach; i++) {
        printf("\nThong tin cho cuon sach thu %d:\n", i + 1);
        hienThiThongTinSach(&dsSach[i]);
    }

    // Giai ph�ng bo nho
    free(dsSach);

    return 0;
}
