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
struct Node *createList()
{
    struct Node *header = malloc(sizeof(struct Node));
    if (!header) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    header->link = NULL; 
    return header;
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
        printf("%.1fx^%d ", ptr->coeff,ptr->exp);
        if(ptr->link!=NULL)
        {
            printf("+");
        }
        ptr = ptr->link; 
    }
    printf("\n");
}
void multiplication(struct Node*header1,struct Node* header2)
{
    int exp;
    float coeff;
    headerR=createList();
    struct Node* ptr1=header1->link;
    struct Node* ptr2=NULL;
    struct Node* ptr3=NULL;
    while(ptr1!=NULL)
    {
        ptr2=header2->link;
        while(ptr2!=NULL)
        {
            exp=ptr1->exp+ptr2->exp;
            coeff=ptr1->coeff*ptr2->coeff;
            ptr3=headerR;
            int termExist=0;
            while(ptr3->link!=NULL)
            {
                ptr3=ptr3->link;
                if(ptr3->exp==exp)
                {
                    ptr3->coeff+=coeff;
                    termExist=1;
                    break;
                }
            }
            if(!termExist)
            {
                insert(headerR,exp,coeff);
            }
            ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
    }
}
int main()
{
     headerP=createList();
    headerQ=createList();
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
    printf("1st polynomial:");
    display(headerP);
    printf("\n");
    
    printf("2st polynomial:");
    display(headerQ);
    multiplication(headerP,headerQ);
    printf("\nProduct:");
    display(headerR);
    return 0;
}