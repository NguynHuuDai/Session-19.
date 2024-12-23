#include <stdio.h>
#include <string.h>

struct Sinhvien {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

void printSinhvien(struct Sinhvien use) {
    printf("ID: %d\n", use.id);
    printf("Name: %s\n", use.name);
    printf("Age: %d\n", use.age);
    printf("Phone Number: %s\n\n", use.phoneNumber);
}

void deleteSinhvien(int id, struct Sinhvien newuse[], int *currentLength) {
    int i;
    for (i = 0; i < *currentLength; i++) {
        if (newuse[i].id == id) {
            for (int j = i; j < *currentLength - 1; j++) {
                newuse[j] = newuse[j + 1];
            }
            (*currentLength)--;
            printf("Sinh vien co ID %d da duoc xoa\n", id);
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID %d\n", id);
}

void printSinhviens(struct Sinhvien newuse[], int currentLength) {
    if (currentLength == 0) {
        printf("Danh sach sinh vien hien tai rong\n");
        return;
    }
    for (int i = 0; i < currentLength; i++) {
        printf("Sinh vien %d:\n", i + 1);
        printSinhvien(newuse[i]);
    }
}

int main() {
    struct Sinhvien newuse[5] = {
        {1, "Nguyen Huu Do", 20, "0123456789"},
        {2, "Tran Trung Chien", 21, "0123456790"},
        {3, "Le Ba Duy", 22, "0123456801"},
        {4, "Pham Thanh Tung", 23, "0123456812"},
        {5, "Hoang Viet Anh", 24, "0123456823"}
    };
    
    int currentLength = 5;
    int xoasv;
    
    printf("Danh sach sinh vien ban dau:\n");
    printSinhviens(newuse, currentLength);
    
    printf("Nhap ID sinh vien can xoa: ");
    if (scanf("%d", &xoasv) != 1) {
        printf("Loi: Nhap khong hop le.\n");
        return 1;
    }
    
    if (xoasv < 1 || xoasv > 5) {
        printf("ID sinh vien khong hop le\n");
        return 1;
    }
    
    deleteSinhvien(xoasv, newuse, &currentLength);
    
    printf("\nDanh sach sinh vien sau khi xoa:\n");
    printSinhviens(newuse, currentLength);
    
    return 0;
}

