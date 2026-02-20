#include<stdio.h>

int main()
{
    int choice;
    char ans;

    do
    {
        printf("Displaying the menu:\n");
        printf("Enter:\n1:Copying the string\n2:Concatenating the string\n3:Comparing two strings\n4:Finding the length of the string");
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        if(choice==1)
        {
            char str1[20],str2[20];
            char *s1,*s2;

            printf("Enter the string:");
            scanf("%19s",str1);

            s1=str1;
            s2=str2;

            while(*s1!='\0')
            {
                *s2=*s1;
                s2++;
                s1++;
            }
            *s2='\0';

            printf("Printing the copied string:");
            printf("%s\n",str2);
        }
        else if(choice==2)
        {
            char str1[20],str2[20];
            char *s1,*s2;

            printf("Enter the string 1:");
            scanf("%19s",str1);
            printf("Enter the string 2:");
            scanf("%19s",str2);

            s1=str1;
            while(*s1!='\0')
            {
                s1++;
            }

            s2=str2;
            while(*s2!='\0')
            {
                *s1=*s2;
                s1++;
                s2++;
            }
            *s1='\0';

            printf("Printing the concatenated string:");
            printf("%s\n",str1);
        }
        else if(choice==3)
        {
            char str1[20],str2[20];
            char *s1,*s2;
            int comp=0;

            printf("Enter the first string:");
            scanf("%19s",str1);
            printf("Enter the second string:");
            scanf("%19s",str2);

            s1=str1;
            s2=str2;

            while(*s1!='\0' && *s2!='\0')
            {
                if(*s1!=*s2)
                {
                    comp=*s1-*s2;
                    break;
                }
                s1++;
                s2++;
            }

            if(comp==0)
            {
                comp=*s1-*s2;
            }

            if(comp==0)
            {
                printf("The two strings are equal\n");
            }
            else if(comp<0)
            {
                printf("The two strings are not equal and s2 is greater than s1\n");
            }
            else
            {
                printf("The two strings are not equal and s1 is greater than s2\n");
            }
        }
        else if(choice==4)
        {
            char str[20];
            char *s;
            int len=0;

            printf("Enter the string:");
            scanf("%19s",str);

            s=str;
            while(*s!='\0')
            {
                len++;
                s++;
            }

            printf("The length of the string is %d\n",len);
        }
        else
        {
            printf("Invalid choice!\n");
        }

        printf("Do you want to continue?");
        scanf(" %c",&ans);

    } while(ans=='y');

    return 0;
}