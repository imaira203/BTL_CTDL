#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// tao node moi
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// tang them node
void append(Node **head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// sap xep tang dan
void ASCsortList(Node **head) {
    if (*head == NULL) return;
    Node* current;
    Node* index;
    int temp;

    for (current = *head; current->next != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}

// sap xep giam dan
void DESCsortList(Node **head) {
    if (*head == NULL) return;
    Node* current;
    Node* index;
    int temp;

    for (current = *head; current->next != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data < index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}

// in danh sach
void printList(Node *head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("|%d", temp->data);
        temp = temp->next;
    }
    printf("|\n");
}

// check so nguyen
int isNumber(char* str) {
    int i = 0;
    if (str[0] == '-' || str[0] == '+') i = 1;
    for (; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Nhap danh sach
void Input(Node **head) {
    char input[10];

    for (int i = 0 ;; i++) {
        printf("Nhap so thu %d (nhap '#' de dung): ", i + 1);
        scanf("%s", input);
        if (strcmp(input, "#") == 0) {
            break;
        }

        while (!isNumber(input)) {
            printf("Nhap lai so thu %d, chi nhap so nguyen (nhap '#' de dung): ", i + 1);
            scanf("%s", input);
            if (strcmp(input, "#") == 0) {
                break;
            }
        }
        if (strcmp(input, "#") == 0) {
            break;
        }
        int number = atoi(input);  // chuyen doi chuoi thanh so
        append(head, number);      // them so vao danh sach
    }

    printf("Danh sach da nhap:\n");
    printList(*head);
}

// chen node vao vi tri dau
void InsertFirst(Node **head, int x) {
    Node* newNode = createNode(x);
    newNode->next = *head;
    *head = newNode;
}

// chen node vao vi tri K
void Insert(Node **head, int x, int k) {
    int n = sizeof(**head);
    Node* newNode = createNode(x);
    Node* temp = *head;
    if (k < 1 || k > n + 1){
        printf("Vi tri khong hop le\n");
        return;
    }
    if (k == 1) {
        InsertFirst(head, x);
        return;
    }

    for (int i = 0; temp != NULL && i < k-2; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int checkElement(Node **head, int k){
    int n = sizeof(**head);
    int count = 0;
    Node* temp = *head;
    for (int i = 0; temp != NULL && i <= n; i++){
        if (temp->data == k){
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int checkPosition(){

}

int menu() {
    int choice;
    printf("1. Nhap mang so nguyen\n");
    printf("2. Them 1 phan tu vao vi tri bat ki\n");
    printf("3. So luong phan tu K, kiem tra chia het cho 3\n");
    printf("4. Kiem tra 3 so chan duong dung canh nhau\n");
    printf("5. So luong phan tu la so duong chan, trung binh cong\n");
    printf("6. So duong dau danh sach, so am cuoi danh sach, day so duong tang dan, day so am giam dan\n");
    printf("0. Thoat\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Chon: ");
    scanf("%d", &choice);
    return choice;
}

int main() {

    Node* head = NULL;

    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 0:
                printf("Thoat\n");
                break;
            case 1:
                Input(&head);
                break;
            case 2: {
                int x, k;
                printf("Nhap so can chen: ");
                scanf("%d", &x);
                printf("Nhap vi tri: ");
                scanf("%d", &k);
                Insert(&head, x, k);
                printList(head);
                break;
            }
            case 3:{
                int k;
                printf("Nhap so can tim: ");
                scanf("%d", &k);
                int count = checkElement(&head, k);
                if (count > 0){
                printf("So luong phan tu %d la: %d\n", k, count);
                }
                else {
                    printf("Khong tim thay phan tu %d\n"), k;
                }
                if (count%3 == 0){
                    printf("So luong phan tu %d trong danh sach chia het cho 3\n");
                }
                else {
                    printf("So luong phan tu %d trong danh sach khong chia het cho 3\n");
                }
            }
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
    return 0;
}
