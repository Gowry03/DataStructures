#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    int data;
    struct Node *Rlink;
    struct Node *Llink;
};

struct Node *header = NULL;

void enqueue(char c);
void enterString(char s[50]);
int check(char s[50]);
void enterString(char s[50]) {
    int l = strlen(s);
    for (int i = 0; i < l; i++) {
        enqueue(s[i]); 
    }
}
int check(char s[50]) {
    enterString(s);

    int flag = 0;
    struct Node *ptr1 = header->Rlink;
    struct Node *ptr2 = header;
    while (ptr2->Rlink != NULL) {
        ptr2 = ptr2->Rlink;
    }
    while (ptr1 != ptr2 && ptr1->Llink != ptr2) {
        if (ptr2->data != ptr1->data) {
            flag = 1;
            break;
        }
        ptr2 = ptr2->Llink;
        ptr1 = ptr1->Rlink;
    }

    if (flag == 0)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return flag;
}
void enqueue(char c) {
    struct Node* temp = malloc(sizeof(struct Node));
    if (!temp) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    temp->data = c;
    temp->Rlink = NULL;
    temp->Llink = NULL;

    if (header == NULL) { 
        header = malloc(sizeof(struct Node)); 
        if (!header) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        header->Rlink = temp;
        temp->Llink = header;
    } else { 
        struct Node* ptr = header;
        while (ptr->Rlink != NULL) {
            ptr = ptr->Rlink;
        }
        ptr->Rlink = temp;
        temp->Llink = ptr;
    }
}

int main() {
    printf("Enter the string: ");
    char s[50];
    scanf("%s", s);

    check(s);
    return 0;
}
