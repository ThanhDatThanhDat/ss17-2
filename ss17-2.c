#include <stdio.h>
#include <string.h>
#include <ctype.h>

// nguyen mau 
void menu();
void nhapChuoi(char **str);
void inChuoi(char *str);
int demChuaChuCai(char *str);
int demChuaChuSo(char *str);
int demKyTuDacBiet(char *str);

int main() {
    int choice;
    char chuoi[1000]; 
    char *ptrChuoi = chuoi; 

    do {
        menu();
        printf("\nLua chon cua ban la: ");
        scanf("%d", &choice);
        getchar();  

        switch(choice) {
            case 1:
                nhapChuoi(&ptrChuoi);  
                break;
            case 2:
                inChuoi(ptrChuoi);  
                break;
            case 3:
                printf("So luong chu cai trong chuoi: %d\n", demChuaChuCai(ptrChuoi));  
                break;
            case 4:
                printf("So luong chu so trong chuoi: %d\n", demChuaChuSo(ptrChuoi));  
                break;
            case 5:
                printf("So luong ky tu dac biet trong chuoi: %d\n", demKyTuDacBiet(ptrChuoi));  
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("\nLua chon cua ban khong hop le. Vui long chon lai!\n");
        }
    } while (choice != 6);

    return 0;
}

// logic 
void menu() {
    printf("\n                    MENU             \n");
    printf("\n 1. Nhap vao chuoi ki tu.\n");
    printf("\n 2. In ra chuoi.\n");
    printf("\n 3. Dem so luong chu cai va in ra.\n");
    printf("\n 4. Dem so luong chu so va in ra.\n");
    printf("\n 5. Dem so luong ki tu dac biet trong chuoi va in ra.\n");
    printf("\n 6. Thoat.\n");
}

void nhapChuoi(char **str) {
    printf("Nhap vao chuoi: ");
    fgets(*str, 1000, stdin);
    (*str)[strcspn(*str, "\n")] = '\0';
}

void inChuoi(char *str) {
    printf("Chuoi da nhap: %s\n", str);
}

int demChuaChuCai(char *str) {
    int dem = 0;
    while (*str) {
        if (isalpha(*str)) {
            dem++;
        }
        str++;
    }
    return dem;
}

int demChuaChuSo(char *str) {
    int dem = 0;
    while (*str) {
        if (isdigit(*str)) {
            dem++;
        }
        str++;
    }
    return dem;
}

int demKyTuDacBiet(char *str) {
    int dem = 0;
    while (*str) {
        if (!isalnum(*str) && !isspace(*str)) {
            dem++;
        }
        str++;
    }
    return dem;
}
