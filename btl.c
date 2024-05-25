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
        printf("Loi phan bo bo nho\n");
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
    printf("-------------------------------------------------------------------------------------------------\n");
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
    Node* newNode = createNode(x);
    if (k < 1) {
        printf("-------------------------------------------------------------------------------------------------\n");
        printf("Vi tri khong hop le\n");
        return;
    }
    if (k == 1) {
        InsertFirst(head, x);
        printf("-------------------------------------------------------------------------------------------------\n");
        printf("Danh sach sau khi chen: \n");
        printList(*head);
        return;
    }
    Node* temp = *head;
    for (int i = 1; i < k - 1; i++) {
        if (temp == NULL) {
            printf("-------------------------------------------------------------------------------------------------\n");
            printf("Vi tri khong hop le\n");
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("-------------------------------------------------------------------------------------------------\n");
        printf("Vi tri khong hop le\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Danh sach sau khi chen: \n");
    printList(*head);
}

// Kiem tra phan tu trong danh sach
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

// Kiem tra 3 so duong canh nhau
void checkPosition(Node *head) {
    Node* temp = head;
    int found = 0;
    for (int i = 1; temp != NULL && temp->next != NULL && temp->next->next != NULL; i++) {
        if (temp->data > 0 && temp->data % 2 == 0 && 
            temp->next->data > 0 && temp->next->data % 2 == 0 &&
            temp->next->next->data > 0 && temp->next->next->data % 2 == 0) {
            printf("-------------------------------------------------------------------------------------------------\n");
            printf("Tim thay 3 so chan duong lien tiep |%d|%d|%d| o cac vi tri: %d, %d, %d\n", temp->data, temp->next->data ,temp->next->next->data , i, i+1, i+2);
            found = 1;
        }
        temp = temp->next;
    }
    if (found == 0){
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Khong tim thay 3 so chan duong lien tiep\n");
    }
}

// Kiem tra so luong so duong chan
void checkCount(Node *head){
    Node* temp = head;
    int count = 0;
    int SUM = 0;
    double AVG = 0;
    while (temp != NULL){
        if (temp->data%2 == 0 && temp->data > 0){
            count++;
            SUM += temp->data;
        }
        temp = temp->next;
    }
    if (count > 0){
    AVG = (double)SUM/count;
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("So luong so chan duong trong danh sach la: %d\n", count);
    printf("Trung binh cong cac so chan duong trong danh sach la: %.2f\n", AVG);
    }
    else {
        printf("-------------------------------------------------------------------------------------------------\n");
        printf("Khong co so chan duong trong danh sach\n");
    }
}

// Kiem tra so duong dau danh sach
void FirstPosiNum(Node *head){
    Node* temp = head;
    int found = 0;
    while (temp != NULL){
        if (temp->data > 0){
            printf("-------------------------------------------------------------------------------------------------\n");
            printf("So duong dau danh sach la: %d\n", temp->data);
            found = 1;
            return;
        }
        temp = temp->next;
    }
    if (found == 0){
        printf("-------------------------------------------------------------------------------------------------\n");
        printf("Danh sach khong co so duong\n");
    }
}

// Kiem tra so am cuoi danh sach
void LastNegaNum(Node *head){
    Node* temp = head;
    int found = 0;
    int savedNum;
    while (temp != NULL){
        if (temp->data < 0){
            savedNum = temp->data;
            found = 1;
        }
        temp = temp->next;
    }
    if (found == 1){
        printf("So am cuoi danh sach la: %d\n", savedNum);
    }
    else {
        printf("Danh sach khong co so am\n");
    }
}

// Sap xep so duong tang dan
void ASCPosiList(Node *head){
    Node* temp = head;
    Node* positiveList = NULL;

    while (temp != NULL){
        if (temp->data > 0){
            append(&positiveList, temp->data);
        }
        temp = temp->next;
    }

    if (positiveList == NULL) {
        printf("Day khong co so duong\n");
        return;
    }

    ASCsortList(&positiveList);
    printf("Day so duong tang dan: \n");
    printList(positiveList);
}

// Sap xep so am giam dan
void DESCNegaList(Node *head){
    Node* temp = head;
    Node* negativeList = NULL;

    while (temp != NULL){
        if (temp->data < 0){
            append(&negativeList, temp->data);
        }
        temp = temp->next;
    }

    if (negativeList == NULL) {
        printf("Day khong co so am\n");
        return;
    }

    DESCsortList(&negativeList);
    printf("Day so am giam dan: \n");
    printList(negativeList);
}

// Tong hop ham function 6
void MergeFunc(Node *head){
    FirstPosiNum(head);
    LastNegaNum(head);
    ASCPosiList(head);
    DESCNegaList(head);
}

int menu() {
    int choice;
    printf("-------------------------------------------------------------------------------------------------\n");
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
                break;
            }
            case 3:{
                int k;
                printf("Nhap so can tim: ");
                scanf("%d", &k);
                int count = checkElement(&head, k);
                if (count > 0){
                printf("-------------------------------------------------------------------------------------------------\n");
                printf("So luong phan tu %d la: %d\n", k, count);
                    if (count%3 == 0){
                        printf("So luong phan tu %d trong danh sach chia het cho 3\n");
                    }
                    else {
                        printf("So luong phan tu %d trong danh sach khong chia het cho 3\n");
                    }
                }
                else {
                    printf("-------------------------------------------------------------------------------------------------\n");
                    printf("Khong tim thay phan tu %d\n"), k;
                }
            }
                break;
            case 4:
                checkPosition(head);
                break;
            case 5:
                checkCount(head);
                break;
            case 6:
                MergeFunc(head);
                break;
            default:
                printf("Vui long chon lua chon hop le\n");
                break;
        }
    } while (choice != 0);
    return 0;
}
