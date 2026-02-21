#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    int number;
    char name[100];
    float mark;
    struct Node *link;
};

struct Node *header = NULL;

void createList() {
    header = malloc(sizeof(struct Node));
    if (!header) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    header->link = NULL;
}

void insertAtFront() {
    char name[100];
    int num;
    float mark;
    
    printf("Enter number: ");
    scanf("%d", &num);
    getchar();  // Clear the buffer
    
    printf("Enter name: ");
    scanf(" %[^\n]", name);
    
    printf("Enter the mark: ");
    scanf("%f", &mark);
    
    struct Node *temp = malloc(sizeof(struct Node));
    if (!temp) {
        printf("Memory allocation failed\n");
        return;
    }
    
    temp->mark = mark;
    temp->number = num;
    strcpy(temp->name, name);
    temp->link = header->link;
    header->link = temp;
}

int deleteAtAny() {
    int key;
    printf("Enter the number to be deleted: ");
    scanf("%d", &key);
    
    struct Node *ptr = header->link;
    struct Node *temp = header;
    
    if (ptr == NULL) {
        printf("List is empty\n");
        return -1;
    }
    
    while (ptr != NULL && ptr->number != key) {
        temp = ptr;
        ptr = ptr->link;
    }
    
    if (ptr == NULL) {
        printf("Key not found\n");
        return -1;
    }
    
    temp->link = ptr->link;
    free(ptr);
    return key;
}

void searchNum() {
    int n;
    printf("Enter the number to be searched: ");
    scanf("%d", &n);
    
    struct Node* ptr = header->link;
    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }
    
    while (ptr != NULL && ptr->number != n) {
        ptr = ptr->link;
    }
    
    if (ptr == NULL) {
        printf("Number not found\n");
    } else {
        printf("Found: %d %s %.2f\n", ptr->number, ptr->name, ptr->mark);
    }
}

void searchName() {
    char str[100];
    printf("Enter the name to be searched: ");
    getchar(); // Clear the buffer
    scanf(" %[^\n]", str);
    
    struct Node* ptr = header->link;
    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }
    
    while (ptr != NULL && strcmp(ptr->name, str) != 0) {
        ptr = ptr->link;
    }
    
    if (ptr == NULL) {
        printf("Name not found\n");
    } else {
        printf("Found: %d %s %.2f\n", ptr->number, ptr->name, ptr->mark);
    }
}

void sort(struct Node *header) {
    if (header->link == NULL || header->link->link == NULL) {
        printf("List has one or no elements. No sorting needed.\n");
        return;
    }
    
    struct Node *ptr1, *ptr2;
    float tempMark;
    int tempNum;
    char tempName[100];
    
    for (ptr1 = header->link; ptr1 != NULL; ptr1 = ptr1->link) {
        for (ptr2 = ptr1->link; ptr2 != NULL; ptr2 = ptr2->link) {
            if (ptr1->number > ptr2->number) {
                // Swap number, mark, and name
                tempMark = ptr1->mark;
                tempNum = ptr1->number;
                strcpy(tempName, ptr1->name);
                
                ptr1->mark = ptr2->mark;
                ptr1->number = ptr2->number;
                strcpy(ptr1->name, ptr2->name);
                
                ptr2->mark = tempMark;
                ptr2->number = tempNum;
                strcpy(ptr2->name, tempName);
            }
        }
    }
}

void display() {
    struct Node *ptr = header->link;
    
    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("List contents:\n");
    while (ptr != NULL) {
        printf("%d %s %.2f\n", ptr->number, ptr->name, ptr->mark);
        ptr = ptr->link;
    }
}



int main() {
    createList();
    int choice;
     printf("\nMENU\n1. Insert at beginning\n2. Search by number\n3. Search by name\n4. Delete\n5. Sort\n6. Display\n7. Exit\n");
    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insertAtFront();
                break;
            case 2:
                searchNum();
                break;
            case 3:
                searchName();
                break;
            case 4: {
                int deletedData = deleteAtAny();
                if (deletedData != -1) {
                    printf("Deleted data: %d\n", deletedData);
                }
                break;
            }
            case 5:
                sort(header);
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
