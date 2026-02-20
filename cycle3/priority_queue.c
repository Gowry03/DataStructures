#include<stdio.h>
#include<stdlib.h>
int p,max,n,pq[100][100],front[100],rear[100];
void insert()
{
    printf("Enter the priority: ");
    scanf("%d",&p);
    if(p>=max)
    {
        printf("OUT OF PRIOROTY\n");
    }
    else
    {
    if(rear[p]==n-1)
    {
        printf("Can't enter to the %d th priority\n",p);
    }
    else
    {
        printf("Enter the data: ");
        int data;
        scanf("%d",&data);
        rear[p]++;
        pq[p][rear[p]]=data;
    }
    if(rear[p]==0)
    {
        front[p]=0;
    }
    }
}
int delete()
{
    int item;
    p=0;int flag=0;
    while(p<max)
    {
        if(front[p]!=-1)
        {
            flag=1;
            break;
        }
        p++;
    }
    if(flag==0)
    {
        printf("pq is empty\n");
        return -1;
    }
    else
    {
        p=0;
        while(p<max)
        {
            if(front[p]==-1)
            {
                p++;
            }
            else
            {
                item=pq[p][front[p]];
                front[p]++;
                if(front[p]>rear[p])
                {
                    front[p]=rear[p]=-1;
                }
                return item;
            }
        }
    }
}
void display()
{
    p=0;
    while(p<max)
    {
        if(front[p]!=-1)
        {
            break;
        }
        else
        {
            p++;
        }
    }
    if(p==max)
    {
        printf("pq empty\n");
    }
    for(int i=p;i<max;i++)
    {
        if(front[i]==-1)
        {
            continue;
        }
        for(int j=front[i];j<=rear[i];j++)
        {
            printf("%d\t",pq[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    printf("Enter the max priority: ");
    scanf("%d",&max);
    printf("Enter the size: ");
    scanf("%d",&n);
    for(int i=0;i<max;i++)
    {
        front[i]=-1;
        rear[i]=-1;
    }
    int ch,d;
    printf("\nMENU\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
    while(1)
    {
        printf("Enter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                d=delete();
                if(d!=-1)
                {
                    printf("%d is deleted\n",d);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
        }
    }
    return 0;
}