#include<stdio.h>
#include<stdlib.h>

int front = -1, rear = -1, cq[100], size;

void insert(int data)
{
    if((rear + 1) % size == front)
    {
        printf("CIRCULAR QUEUE IS FULL\n");
        return;
    }

    if(front == -1) 
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % size;
    }

    cq[rear] = data;
}

int delete()
{
    int data;

    if(front == -1)
    {
        printf("CIRCULAR QUEUE UNDERFLOW\n");
        return -1;
    }

    data = cq[front];

    if(front == rear) 
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }

    return data;
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("\nQueue:\n");

    for(i = front; i != rear; i = (i + 1) % size)
    {
        printf("%d\t", cq[i]);
    }

    printf("%d\n", cq[i]);
}

int main()
{
    int ch, data, d;

    printf("Enter the size of the queue:\n");
    scanf("%d", &size);

    printf("MENU\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");

    while(1)
    {
        printf("\nEnter the choice:\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter the element:\n");
                scanf("%d", &data);
                insert(data);
                break;

            case 2:
                d = delete();
                if(d != -1)
                {
                    printf("%d is deleted\n", d);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
        }
    }

    return 0;
}