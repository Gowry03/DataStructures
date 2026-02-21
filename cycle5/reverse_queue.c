#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct  node * link;
};
struct node * header1=NULL;
struct node * header2=NULL;
void create()
{
    header1=malloc(sizeof(struct node));
    header2=malloc(sizeof(struct node));
    if(!header1)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    if(!header2)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    header1->link=NULL;
    header2->link=NULL;
}
void push(int x)
{
    struct node * top=header1->link;
    struct node * temp=malloc(sizeof(struct node));
    if(!temp)
    {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data=x;
    temp->link=top;
    top=temp;
    header1->link=top;
}
int pop()
{
    int x;
    struct node *top=header1->link;
    if(top==NULL)
    {
        printf("stack empty\n");
        return -1;
    }
    x=top->data;
    header1->link=top->link;
    top->link=NULL;
    free(top);
    return x;
}
void enqueue(int x)
{
    struct node * front=header2->link;
    struct node *rear=header2;
    while(rear->link!=NULL)
    {
        rear=rear->link;
    }
    struct node * temp=malloc(sizeof(struct node));
    if(!temp)
    {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data=x;
    temp->link=NULL;
    rear->link=temp;
    rear=rear->link;
}
int dequeue()
{
    int x;
    struct node *front =header2->link;
    struct node *rear=header2;
    while(rear->link!=NULL)
    {
        rear=rear->link;
    }
    if(front==NULL)
    {
        printf("QUEUE UNDERFLOW!");
        return -1;
    }
    x=front->data;
    header2->link=front->link;
    front->link=NULL;
    free(front);
    if(rear->link==front)
    {
        front=NULL;
    }
    return x;
}
void display()
{
    struct node *ptr =header2->link;
    printf("QUEUE: ");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
}
int main()
{
    int ch,data;
    create();
    printf("MENU\n1.ENTER ELEMENT\n2.EXIT\n");
    int  n=1;
    int range=0;
    while(n==1)
    {
        printf("Enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("Enter the data: ");
                    scanf("%d",&data);
                    enqueue(data);
                    range++;
                    break;
            case 2:
                    n=0;
                    break;
        }
    }
    int x;
    n=range;
    printf("INITIAL\n");
    display();
    printf("\n");
    while(n>0)
    {
        x=dequeue();
        if(x!=-1)
        {
            push(x);
        }
        n--;
    }
    n=range;
    while(n>0)
    {
        x=pop();
        if(x!=-1)
        {
            enqueue(x);
        }
        n--;
    }
    printf("REVERSED\n");
    display();
}
