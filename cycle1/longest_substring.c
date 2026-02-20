#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    printf("Enter the String\n");
    scanf("%s",str);

    int i=0,j=0,itr=0,flag=0;
    int l=strlen(str);
    char temp[100]={0},sub[100]={0};

    for(i=0;i<l;i++)
    {
        char c=str[i];
        flag=0;

        for(j=0;temp[j]!='\0';j++)
        {
            if(temp[j]==c)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            if(strlen(temp)>strlen(sub))
            {
                strcpy(sub,temp);
            }
            itr++;
            i = itr - 1; 
            temp[0]='\0';
        }
        else
        {
            int len=strlen(temp);
            temp[len]=c;
            temp[len+1]='\0';
        }

        if(strlen(temp)>strlen(sub))
        {
            strcpy(sub,temp);
        }
    }

    printf("The longest Substring:%s",sub);

    return 0;
}