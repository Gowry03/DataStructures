#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
char s[100];
int top=-1;
int isp(char x)
{
    if(x=='+'||x=='-')
    return 2;
    else if(x=='*'||x=='/')
    return 4;
    else if(x=='^')
    return 5;
    else if(x=='(')
    return 0;
    else
    return 0;
}
int icp(char x)
{
    if(x=='+'||x=='-')
    return 1;
    else if(x=='*'||x=='/')
    return 3;
    else if(x=='^')
    return 6;
    else if(x=='(')
    return 7;
    else
    return 6;
}
void push(char s[100],char x)
{
    s[++top]=x;
}
int pop(char s[100])
{
    char item;
    if(top==-1)
    return '\0';
    else
    {
        item=s[top--];
        return item;
    }
}
int main()
{
    char exp[100],rev[100],pre[100],item,x;
    printf("Enter the Expression\n");
    scanf("%s",exp);
    int n=strlen(exp);
    int i;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[n-i-1]=='(')
        {
            rev[i]=')';
        }
        else if(exp[n-i-1]==')')
        {
            rev[i]='(';
        }
        else
        rev[i]=exp[n-i-1];
    }
    rev[i]='\0';
    strcat(rev,")");
    push(s,'(');
    i=0;int k=0;
    while(rev[i]!='\0')
    {
        item=rev[i];
        x=pop(s);
        if(isalnum(item))
        {
            pre[k++]=item;
            push(s,x);
        }
        else if(item==')')
        {
            while(x!='(')
            {
                pre[k++]=x;
                x=pop(s);
            }
        }
        else if(isp(x)>=icp(item))
        {
            while(isp(x)>=icp(item))
            {
                pre[k++]=x;
                x=pop(s);
            }
            push(s,x);
            push(s,item);
        }
        else if(isp(x)<icp(item))
        {
            push(s,x);
            push(s,item);
        }
        i++;
    }
    pre[k]='\0';
    char ans[100];
    int j,l=strlen(pre);
    for(j=0;pre[j]!='\0';j++)
    {
        ans[j]=pre[l-j-1];
    }
    ans[j]='\0';
    printf("prefix: %s",ans);
    return 0;
}