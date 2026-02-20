#include<stdio.h>
#include<stdlib.h>
int rear=-1,front=-1,size,dq[1000];
void enterAtEnd()
{
    int data;
    if(rear==size-1)
    {
        printf("QUEUE OVERFLOW!\n");
    }
    else
    {
        printf("Enter the data\n");
        scanf("%d",&data);
        rear++;
        dq[rear]=data;
    }
    if(rear==0)
    {
        front=0;
    }
}
int frontDequeue()
{
    int data;
    if(front==-1)
    {
        printf("QUEUE UNDERFLOW!\n");
        return -1;
    }
    else
    {
        data=dq[front];
        front++;
        if(front>rear)
        {
            rear=front=-1;
        }
        return data;
    }
}
int rearDequeue()
{
    int data;
    if(front==-1)
    {
        printf("QUEUE UNDERFLOW!\n");
        return -1;
    }
    else
    {
        data=dq[rear];
        rear=rear-1;
        if(rear<front)
        {
            rear=front=-1;
        }
        return data;
    }
}
void frontEnqueue()
{
    int data;
    if(front==0)
    {
        printf("CANNOT ADD AT FRONT\n");
    }
    else if(front==-1)
    {
        printf("Enter data\n");
        scanf("%d",&data);
        front++;
        rear++;
        dq[front]=data;
    }
    else
    {
        printf("Enter data\n");
        scanf("%d",&data);
        front--;
        dq[front]=data;
    }
}
void display()
{
    int i;
    if(rear==-1)
    {
        printf("QUEUE EMPTY\n");
    }
    else
    {
        printf("-------------------->QUEUE<-------------------------\n");
        for(i=front;i<=rear;i++)
        {
            printf("%d\n",dq[i]);
        }
        printf("-------------------->QUEUE<-------------------------\n");
    }
}
int main()
{
    int ch,d;
    printf("Enter the size of the queue\n");
    scanf("%d",&size);
    while(1)
    {
        printf("MENU\n1.ENQUEUE AT FRONT\n2.ENQUEUE AT BACK\n3.DEQUEUE AT FRONT\n4.DEQUEUE AT BACK\n5.DISPLAY\n6.EXIT\n");
        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    frontEnqueue();
                    break;
            case 2:
                    enterAtEnd();
                    break;
            case 3:
                    d=frontDequeue();
                    if(d!=-1)
                    { 
                        printf("DELETED DATA: %d\n",d);
                    }
                    break;
            case  4:
                    d=rearDequeue();
                    if(d!=-1)
                    { 
                        printf("DELETED DATA: %d\n",d);
                    }
                    break;
            case 5:
                    display();
                    break;
            case 6:
                    exit(0);
                    break;
            default:
                    printf("invalid choice!\n");
        }
    }
    return 0;
}