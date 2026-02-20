#include<stdio.h>
#include<stdlib.h>
int queue[1000];
int front=-1;
int rear=-1;
int size;
void enqueue()
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
        queue[rear]=data;
    }
    if(rear==0)
    {
        front=0;
    }
}
int dequeue()
{
    int data;
    if(front==-1)
    {
        printf("QUEUE UNDERFLOW!\n");
        return -1;
    }
    else
    {
        data=queue[front];
        front++;
        if(front>rear)
        {
            rear=front=-1;
        }
        return data;
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
            printf("%d\n",queue[i]);
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
        printf("MENU\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    enqueue();
                    break;
            case 2:
                    d=dequeue();
                    if(d!=-1)
                    {
                        printf("DELETED DATA: %d\n",d);
                    }
                    break;
            case 3:
                    display();
                    break;
            case 4:
                    exit(0);
                    break;
            default:
                    printf("invalid choice!\n");
        }
    }
    return 0;
}