#include<stdio.h>
#include<stdlib.h>
struct node
{
    float coeff;
    int expx;
    int expy;
    struct node *link;
};
struct node * headerp=NULL;
struct node *headerq=NULL;
struct node *headerr=NULL;
void create()
{
    headerp=(struct node *)malloc(sizeof(struct node));
    if(!headerp)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    headerp->link=NULL;
    headerq=(struct node *)malloc(sizeof(struct node));
    if(!headerq)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    headerq->link=NULL;
    headerr=(struct node *)malloc(sizeof(struct node));
    if(!headerr)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    headerr->link=NULL;
}
void insert(struct node *header,int expx,int expy,float coeff)
{
    struct node *temp=malloc(sizeof(struct node));
    if(!temp)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    temp->expx=expx;
    temp->expy=expy;
    temp->coeff=coeff;
    temp->link=NULL;
    struct node * ptr=header;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
}
void enter(struct node * header,int n)
{
    float coeff;
    int expx,expy;
    for(int i=0;i<n;i++)
    {
        printf("enter the %d th coeff: ",i+1);
        scanf("%f",&coeff);
        printf("Enter the the %dth X exponent: ",i+1);
        scanf("%d",&expx);
        printf("Enter the the %dth Y exponent: ",i+1);
        scanf("%d",&expy);
        insert(header,expx,expy,coeff);
    }
}
void add(struct node * header1,struct node * header2,struct node *header3)
{
    struct node *ptr1=header1->link;
    struct node *ptr2=header2->link;
    while(ptr1!=NULL&&ptr2!=NULL)
    {
        if(ptr1->expx>ptr2->expx||((ptr1->expx==ptr2->expx)&&(ptr1->expy>ptr2->expy)))
        {
            insert(header3,ptr1->expx,ptr1->expy,ptr1->coeff);
            ptr1=ptr1->link;
        }
        else if(ptr1->expx<ptr2->expx||((ptr1->expx==ptr2->expx)&&(ptr1->expy<ptr2->expy)))
        {
            insert(header3,ptr2->expx,ptr2->expy,ptr2->coeff);
            ptr2=ptr2->link;
        }
        else
        {
            insert(header3,ptr2->expx,ptr2->expy,(ptr2->coeff+ptr1->coeff));
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
    }
    while(ptr1!=NULL)
    {
        insert(header3,ptr1->expx,ptr1->expy,ptr1->coeff);
        ptr1=ptr1->link;
    }
    while(ptr2!=NULL)
    {
        insert(header3,ptr2->expx,ptr2->expy,ptr2->coeff);
        ptr2=ptr2->link;
    }
}
void sort(struct node * header)
{
    int expx,expy;
    float coeff;
    struct node *ptr1,*ptr2;
    for(ptr1=header->link;ptr1!=NULL;ptr1=ptr1->link)
    {
        for(ptr2=ptr1;ptr2!=NULL;ptr2=ptr2->link)
        {
            if(ptr1->expx<ptr2->expx||((ptr1->expx==ptr2->expx)&&(ptr1->expy<ptr2->expy)))
            {
                expx=ptr1->expx;
                ptr1->expx=ptr2->expx;
                ptr2->expx=expx;
                expy=ptr1->expy;
                ptr1->expy=ptr2->expy;
                ptr2->expy=expy;
                coeff=ptr1->coeff;
                ptr1->coeff=ptr2->coeff;
                ptr2->coeff=coeff;
            }
        }
    }
}
void display(struct node * header)
{
    struct node *ptr=header->link;
    while(ptr!=NULL)
    {
        printf("%.2f X^%d Y^%d ",ptr->coeff,ptr->expx,ptr->expy);
        if(ptr->link!=NULL)
        {
            printf("+ ");
        }
        ptr=ptr->link;
    }
    printf("\n");
}
int main()
{
    create();
    int m,n;
    printf("enter the 1st polynomial range: ");
    scanf("%d",&m);
    printf("enter the 2nd polynomial range: ");
    scanf("%d",&n);
    printf("Enter the elements in the 1st polynomial\n");
    enter(headerp,m);
    printf("Enter the elements in the 2nd polynomial\n");
    enter(headerq,n);
    sort(headerp);
    sort(headerq);
    printf("P: ");
    display(headerp);
    printf("Q: ");
    display(headerq);
    add(headerp,headerq,headerr);
    sort(headerr);
    printf("SUM: ");
    display(headerr);
}