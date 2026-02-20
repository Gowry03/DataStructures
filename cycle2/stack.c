#include<stdio.h>
#include<stdlib.h>
int top=-1,size,s[100];
void push(int data)
{
    if(top==size-1)
    {
        printf("STACK OVERFLOW\n");
    }
    else
    {
        s[++top]=data;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("STACK UNDERFLOW");
        return -1;
    }
    else
    {
        int data=s[top--];
        return data;
    }
}
int main()
{
    int ch,data,d;
    printf("Enter the size of the stack: ");
    scanf("%d",&size);
    printf("MENU\n1.PUSH\n2.POP\n3.EXIT");
    while(1)
    {
        printf("\nEnter the choice: ");
        scanf("%d",&ch);
        switch(ch)
    {
        case 1:
            printf("\nEnter the data: ");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            d=pop();
            if(d!=-1)
            {
                printf("\n%d is deleted\n",d);
            }
            break;
        case 3:
            exit(0);
            break;
    }
    }
    return 0;
}