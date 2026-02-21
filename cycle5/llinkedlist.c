#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
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

    int n, num, i;
    struct Node *ptr = header;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        struct Node *temp = malloc(sizeof(struct Node));
        if (!temp) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        printf("Enter the data: ");
        scanf("%d", &num);
        temp->data = num;
        temp->link = NULL;

        ptr->link = temp;
        ptr = ptr->link;  
    }
}

void insertAtFront() 
{
    int data;
    struct Node *temp = malloc(sizeof(struct Node));
    if (!temp) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    (*temp).data = data;
    temp->link = header->link; 
    header->link = temp;       
}

void insertAtEnd() {
    int data;
    struct Node *ptr = header;

    while (ptr->link != NULL) {
        ptr = ptr->link; 
    }
    struct Node *temp = malloc(sizeof(struct Node));
    if (!temp) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->data = data;
    temp->link = NULL; 
    ptr->link = temp;  
}

void insertAtAny() 
{
    int data, key;
    struct Node *ptr = header->link;

    printf("Enter the key after which the data is to be inserted: ");
    scanf("%d", &key);

    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->link; 
    }

    if (ptr == NULL) {
        printf("Key not found\n");
        return; 
    }

    struct Node *temp = malloc(sizeof(struct Node));
    if (!temp) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->data = data;
    temp->link = ptr->link; 
    ptr->link = temp;       
}

int deleteAtFront() {
    struct Node *ptr = header->link;
    if (ptr == NULL) {
        printf("List is empty\n");
        return -1; 
    }

    int data = ptr->data;
    header->link = ptr->link; 
    free(ptr); 
    return data; 
}
int count()
{
    struct Node * ptr1=header->link;
    int count=0;
    if(ptr1==NULL)
    {
        count=0;
    }
    else
    {
        while(ptr1!=NULL)
        {
            ptr1=ptr1->link;
            count++;
        }
       
    }
     return count;
}

int deleteAtLast() {
    struct Node *ptr = header->link;
    struct Node *temp = NULL;

    if (ptr == NULL) {
        printf("List is empty\n");
        return -1;
    }

    if (ptr->link == NULL) 
    {
        int data = ptr->data;
        free(ptr); 
        header->link = NULL; 
        return data; 
    }

    while (ptr->link != NULL) {
        temp = ptr; 
        ptr = ptr->link; 
    }

    int data = ptr->data;
    free(ptr);
    temp->link = NULL;
    return data; 
}

int deleteAtAny() {
    int key;
    printf("Enter the key which is to be deleted: ");
    scanf("%d", &key);

    struct Node *ptr = header->link;
    struct Node *temp = header;

    if (ptr == NULL) {
        printf("List is empty\n");
        return -1; 
    }

    while (ptr != NULL && ptr->data != key) {
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

void display() 
{
    struct Node *ptr = header->link;

    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List contents: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link; 
    }
    printf("\n");
}

int main() 
{
    createList();
    int choice;
    int m;
    while (1) {
        printf("\nMENU\n1. Insert at beginning\n2. Insert at end\n3. Insert at specific\n4. Delete at front\n5. Delete at back\n6. Delete at specific\n7. Display\n8.Count\n9.exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertAtFront();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertAtAny();
                break;
            case 4: {
                int deletedData = deleteAtFront();
                if (deletedData != -1) {
                    printf("Deleted data: %d\n", deletedData);
                }
                break;
            }
            case 5: {
                int deletedData = deleteAtLast();
                if (deletedData != -1) {
                    printf("Deleted data: %d\n", deletedData);
                }
                break;
            }
            case 6: {
                int deletedData = deleteAtAny();
                if (deletedData != -1) {
                    printf("Deleted key: %d\n", deletedData);
                }
                break;
            }
            case 7:
                display();
                break;
            case 8:
                m=count();
                printf("count:%d ",m);
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}