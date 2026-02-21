#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    float coeff;
    struct Node *link;
    int exp;
};

struct Node *headerP = NULL;
struct Node *headerQ=NULL;
struct Node *headerR=NULL;
void createList()
{
    headerP = malloc(sizeof(struct Node));
    if (!headerP) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    headerP->link = NULL; 
    headerQ= malloc(sizeof(struct Node));
    if (!headerQ) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    headerQ->link = NULL; 
    headerR = malloc(sizeof(struct Node));
    if (!headerR) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    headerR->link = NULL; 
}
void insert(struct Node * header,int exp,float coeff)
{
    struct Node* temp=malloc(sizeof(struct Node));
    if(!temp)
    {
        printf("\nmemory allocation failed\n");
        return;
    }
    struct Node *ptr = header;
    while (ptr->link != NULL) 
    {
        ptr = ptr->link; 
    }
    temp->exp=exp;
    temp->coeff=coeff;
    ptr->link=temp;
    temp->link=NULL;
}
void display(struct Node* header) 
{
    struct Node *ptr = header->link;

    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }
    while (ptr != NULL) 
    {
        printf("%.2fx^%d ", ptr->coeff,ptr->exp);
        if(ptr->link!=NULL)
        {
            printf("+");
        }
        ptr = ptr->link; 
    }
    printf("\n");
}
void add(struct Node* headerP, struct Node* headerQ)
{
    struct Node* ptr1 = headerP->link;
    struct Node* ptr2 = headerQ->link;
    struct Node* ptr3 = headerR;

    while (ptr1 != NULL && ptr2 != NULL) {
        struct Node *newNode = malloc(sizeof(struct Node));
        if (!newNode) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        if (ptr1->exp == ptr2->exp) {
            newNode->exp = ptr1->exp;
            newNode->coeff = ptr1->coeff + ptr2->coeff;
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        } else if (ptr1->exp > ptr2->exp) {
            newNode->exp = ptr1->exp;
            newNode->coeff = ptr1->coeff;
            ptr1 = ptr1->link;
        } else {
            newNode->exp = ptr2->exp;
            newNode->coeff = ptr2->coeff;
            ptr2 = ptr2->link;
        }
        newNode->link = NULL;
        ptr3->link = newNode;
        ptr3 = newNode;
    }

    while (ptr1 != NULL) {
        struct Node *newNode = malloc(sizeof(struct Node));
        if (!newNode) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        newNode->exp = ptr1->exp;
        newNode->coeff = ptr1->coeff;
        newNode->link = NULL;
        ptr3->link = newNode;
        ptr3 = newNode;
        ptr1 = ptr1->link;
    }

    while (ptr2 != NULL) {
        struct Node *newNode = malloc(sizeof(struct Node));
        if (!newNode) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        newNode->exp = ptr2->exp;
        newNode->coeff = ptr2->coeff;
        newNode->link = NULL;
        ptr3->link = newNode;
        ptr3 = newNode;
        ptr2 = ptr2->link;
    }
}

int main()
{
    createList();
    float coeffi;
    int expo;
    int m,n,i,j,k;
    printf("\nenter the number of terms in the first polynomial\n");
    scanf("%d",&m);
    printf("\nenter the number of terms in the second polynomial\n");
    scanf("%d",&n);
    printf("\nenter the terms in 1st polynomial\n");
    for(i=0;i<m;i++)
    {
        printf("\n enter the %d th coefficient\n",i+1);
        scanf("%f",&coeffi);
        printf("enter the %d th exponent\n",i+1);
        scanf("%d",&expo);
        insert(headerP,expo,coeffi);
    }
        printf("\nenter the terms in 2nd polynomial\n");
    for(j=0;j<n;j++)
    {
        printf("\n enter the %d th coefficient\n",j+1);
        scanf("%f",&coeffi);
        printf("\n enter the %d th exponent\n",j+1);
        scanf("%d",&expo);    
        insert(headerQ,expo,coeffi);  
    }
    printf("\n1st polynomial:");
    display(headerP);
        printf("\n2nd polynomial:");
    display(headerQ);
    add(headerP,headerQ);
    printf("\nSUM:");
    display(headerR);
    return 0;
    

}
