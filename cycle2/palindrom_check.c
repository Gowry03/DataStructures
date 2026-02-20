#include<stdio.h>
#include<string.h>
int top=-1,size;
char s[100];
void push(char data)
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
void main()
{
    char str[100];
    int l;
    printf("Enter the string\n");
    scanf("%s",str);
    l=strlen(str);
    size=l;
    for(int i=0;i<l;i++)
    {
        push(str[i]);
    }
    int i=0;
    char x;
    while(top!=-1)
    {
        x=pop();
        if(str[i++]!=x)
        {
            printf("not palindrome\n");
            return;
        }
    }
    printf("Palindrome\n");
}