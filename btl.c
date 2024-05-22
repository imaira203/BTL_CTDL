#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// tao node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// them 1 node vao cuoi danh sach
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    for (; temp->next != NULL; temp = temp->next);
    temp->next = newNode;
}

// sap xep tang dan
void DESCsortList(Node* head) {
    if (head == NULL) return;
    Node* current;
    Node* index;
    int temp;

    for (current = head; current->next != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}

void printList(Node* head) {
    for (Node* temp = head; temp != NULL; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n");
}

int isNumber(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i]) && str[i] != '-' && str[i] != '+') {
            return 0; 
        }
    }
    return 1; 
}

int nhapMang() {
    Node* head = NULL;  
    char input[10];     

    for (int i = 0 ;; i++) {
        printf("Nhap so thu %d (nhap '#' de dung): ", i+1);
        scanf("%s", input); 
        if (strcmp(input, "#") == 0) {
            break;
        }
        // kiem tra co phai so hay khong
        while (!isNumber(input)) {
            printf("Nhap lai so thu %d, chi nhap so nguyen (nhap '#' de dung): ", i+1);
            scanf("%s", input);
            if (strcmp(input, "#") == 0) {
                break; 
            }
        }
        if (strcmp(input, "#") == 0) {
            break; 
        }
        int number = atoi(input);  // chuyen chuoi thanh so nguyen
        append(&head, number);     // them so nguyen vao danh sach
    }

    printf("Danh sach da nhap:\n");
    printList(head);

    // giai phong bo nho
    Node* temp;
    for (; head != NULL; ) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int menu(){
    int choice;
    printf("1. Nhap mang so nguyen\n");
    printf("2. Them 1 phan tu vao vi tri bat ki\n");
    printf("3. So luong phan tu K, kiem tra chia het cho 3\n");
    printf("4. Kiem tra 3 so chan duong lien tiep\n");
    printf("5. So luong phan tu la so duong chan, trung binh cong\n");
    printf("6. So duong dau danh sach, so am cuoi danh sach, day so duong tang dan, day so am giam dan\n");
    printf("0. Thoat\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Chon: ");
    scanf("%d", &choice);
    return choice;
}

int main(){
    int choice;
    do {
        choice = menu();
    switch (choice)
    {
    case 0:
        printf("Thoat\n");
        break;
    case 1:
        nhapMang();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;

    default:
        printf("Vui long chon lua chon hop le\n");
        break;
    }
    } while (choice != 0);
}