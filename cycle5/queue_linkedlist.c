#include <stdio.h> 
#include <stdlib.h> 
struct Node  
{ 
    int data; 
    struct Node *link; 
}; 
struct Node *header = NULL; 
struct Node *front=NULL; 
struct Node *rear=NULL; 
 
void createList() { 
    header = malloc(sizeof(struct Node)); 
    if (!header) { 
        printf("Memory allocation failed\n"); 
        exit(1); 
    } 
    header->link = NULL;  
} 
void Enqueue()  
{ 
    int data; 
    struct Node *ptr = header; 
    front=header->link; 
    while (ptr->link != NULL)  
    { 
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
    rear=temp; 
    if(header->link==NULL) 
    { 
        header->link=temp; 
    } 
    front=header->link; 
} 
int dequeue()  
{ 
    struct Node *ptr = front; 
    if (ptr == NULL) { 
        printf("List is empty\n"); 
        return -1;  
    } 
 
    int data = ptr->data; 
    front = ptr->link;  
    free(ptr);  
    return data;  
} 
void display()  
{ 
    struct Node *ptr = front; 
 
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
    printf("\nMENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit"); 
    while(1) 
    { 
        printf("\nEnter Choice: "); 
        scanf("%d", &choice); 
        switch (choice)  
        { 
            case 1: 
                Enqueue(); 
                break; 
            case 2: 
            { 
                int deletedData = dequeue(); 
                if (deletedData != -1) { 
                    printf("Deleted data: %d\n", deletedData); 
                } 
                break; 
            } 
            case 3: 
                display(); 
                break; 
            case 4: 
                exit(0); 
            default: 
                printf("Invalid choice. Please try again.\n");   
        }         
 
    } 
    return 0; 
} 
