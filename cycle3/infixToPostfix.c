#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

char stack[100];
int temp[100];
int top = -1;

void push(char stack[100], char x)
{
    stack[++top] = x;
}

char pop(char stack[100])   
{
    if(top == -1)
    {
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}

int isp(char x)
{
    if(x=='+' || x=='-')
        return 2;
    else if(x=='*' || x=='/')
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
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 3;
    else if(x=='^')
        return 6;
    else if(x=='(')
        return 7;
    else
        return 0;
}

int evaluate(char post[100])
{
    int i = 0;
    char item;
    int res;
    int tops = -1;

    while(post[i] != '\0')
    {
        item = post[i];

        if(isdigit(item))
        {
            temp[++tops] = item - '0';
        }
        else
        {
            int x = temp[tops--];
            int y = temp[tops--];

            switch(item)
            {
                case '+':
                    res = y + x;
                    break;
                case '-':
                    res = y - x;
                    break;
                case '*':
                    res = y * x;
                    break;
                case '/':
                    res = y / x;
                    break;
                case '^':
                    res = (int)pow(y, x);
                    break;
            }

            temp[++tops] = res;
        }
        i++;
    }

    return temp[tops];
}

int main()
{
    char exp[100], post[100];
    char item, x;
    int i = 0, k = 0;

    printf("Enter the Infix Expression:\n");
    scanf("%s", exp);

    push(stack, '(');
    strcat(exp, ")");

    while(exp[i] != '\0')
    {
        item = exp[i];
        x = pop(stack);

        if(isalnum(item))
        {
            post[k++] = item;
            push(stack, x);
        }
        else if(item == ')')
        {
            while(x != '(')
            {
                post[k++] = x;
                x = pop(stack);
            }
        }
        else if(isp(x) < icp(item))
        {
            push(stack, x);
            push(stack, item);
        }
        else
        {
            while(isp(x) >= icp(item))
            {
                post[k++] = x;
                x = pop(stack);
            }
            push(stack, x);
            push(stack, item);
        }

        i++;
    }

    post[k] = '\0';

    printf("\nPostfix Expression: %s\n", post);

    int y = evaluate(post);

    printf("\nResult: %d\n", y);

    return 0;
}