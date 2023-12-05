#include <stdio.h>
#include <stdlib.h>

// Ðinh nghia cau trúc Book
struct Book {
    char ten[50];
    char tacGia[50];
    float gia;
};

// Hàm nhap thông tin mot cuon sách
void nhapThongTinSach(struct Book *sach) {
    printf("Nhap ten sach: ");
    scanf("%s", sach->ten);

    printf("Nhap tac gia: ");
    scanf("%s", sach->tacGia);

    printf("Nhap gia sach: ");
    scanf("%f", &sach->gia);
}

// Hàm hien thi thông tin mot cuon sách
void hienThiThongTinSach(struct Book *sach) {
    printf("Thong tin sach:\n");
    printf("Ten sach: %s\n", sach->ten);
    printf("Tac gia: %s\n", sach->tacGia);
    printf("Gia: %.2f\n", sach->gia);
}

int main() {
    int soLuongSach;

    // Nhap so luong sách
    printf("Nhap so luong sach: ");
    scanf("%d", &soLuongSach);

    // Cap phát dung mang sách
    struct Book *dsSach = (struct Book *)malloc(soLuongSach * sizeof(struct Book));

    // Kiem tra xem bo nho dã duoc cap phát thành công hay không
    if (dsSach == NULL) {
        printf("Khong du bo nho cho mang.\n");
        return 1; // Ket thúc chuong trình voi mã lai 1
    }

    // Nhap thông tin cho tung cuon sách
    for (int i = 0; i < soLuongSach; i++) {
        printf("\nNhap thong tin cho cuon sach thu %d:\n", i + 1);
        nhapThongTinSach(&dsSach[i]);
    }

    // Hien thi thông tin cho tung cuon sách
    for (int i = 0; i < soLuongSach; i++) {
        printf("\nThong tin cho cuon sach thu %d:\n", i + 1);
        hienThiThongTinSach(&dsSach[i]);
    }

    // Giai phóng bo nho
    free(dsSach);

    return 0;
}
