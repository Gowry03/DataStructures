
#include<stdio.h> 
#include<stdlib.h> 
struct Node 
{ 
    int data; 
    struct Node* link; 
}; 
struct Node* header=NULL; 
struct Node* top; 
void createList() { 
    header = malloc(sizeof(struct Node)); 
    if (!header) { 
        printf("Memory allocation failed\n"); 
        exit(1); 
    } 
    header->link = NULL;  
} 
 
void push()  
{ 
    int data; 
    struct Node *temp = malloc(sizeof(struct Node)); 
    if (!temp) { 
        printf("Memory allocation failed\n"); 
        return; 
    } 
 
    printf("\nEnter number to be inserted: "); 
    scanf("%d", &data); 
    temp->data = data; 
    temp->link = header->link;  
    header->link = temp; 
    top=header->link;        
} 
int pop() { 
    struct Node *ptr = header->link; 
    if (header->link == NULL) { 
        printf("stack is empty\n"); 
        return -1;  
    } 
 
    int data = ptr->data; 
    header->link = ptr->link; 
    top=header->link;  
    free(ptr);  
    return data;  
} 
void display()  
{ 
    struct Node *ptr = header->link; 
    top=header->link;; 
    if (top == NULL) { 
        printf("stack is empty\n"); 
        return; 
    } 
 
    printf("stack contents: "); 
    while (ptr != NULL) { 
        printf("%d ", ptr->data); 
        ptr = ptr->link;  
    } 
    printf("\n"); 
} 
 
void main() 
{ 
    createList(); 
       printf("\nMENU\n1.push\n2.pop\n3.display\n4.exit\n"); 
     while(1) 
     { 
        int ch; 
    printf("enter the choice: "); 
        scanf("%d",&ch); 
        switch(ch) 
    { 
       case 1: 
        push(); 
        break; 
       case 2: { 
                int deletedData = pop(); 
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
        break; 
 
    } 
 
     } 
} 

 
 