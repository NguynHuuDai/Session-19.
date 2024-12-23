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

void sapXepSinhvien(struct Sinhvien newuse[], int n) {
    struct Sinhvien temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(newuse[i].name, newuse[j].name) > 0) {
                temp = newuse[i];
                newuse[i] = newuse[j];
                newuse[j] = temp;
            }
        }
    }
}

void printSinhviens(struct Sinhvien newuse[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Sinh vien %d:\n", i + 1);
        printSinhvien(newuse[i]);
    }
}

int main() {
    struct Sinhvien newuse[5] = {
        {1, "Nguyen Anh Minh", 20, "0123456789"},
        {2, "Tran Bao Ngoc", 21, "0123456790"},
        {3, "Le Cao Thành", 22, "0123456801"},
        {4, "Pham Viet Dung", 23, "0123456812"},
        {5, "Hoang Anh Minh", 24, "0123456823"}
    };
    
    int n = 5;  
    
    printf("Danh sach sinh vien ban dau:\n");
    printSinhviens(newuse, n);
    
    sapXepSinhvien(newuse, n);
    
    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    printSinhviens(newuse, n);
    
    return 0;
}

