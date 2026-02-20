#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n1,n2,n;
    printf("Enter the range of 1st array\n");
    scanf("%d",&n1);
    printf("Enter the range of second array\n");
    scanf("%d",&n2);
    n=n1+n2;
    int *p1=(int *)malloc(n1*sizeof(int));
    int *p2=(int *)malloc(n2*sizeof(int));
    int *p=(int *)malloc(n*sizeof(int));
    printf("Enter the elements in the 1st array\n");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",p1+i);
    }
    printf("Enter the elements in the 2nd array\n");
    for(int i=0;i<n2;i++)
    {
        scanf("%d",p2+i);
    }
    int i=0,j=0,k=0;
    while(i<n1&&j<n2)
    {
        if(*(p1+i)<*(p2+j))
        {
            *(p+k)=*(p1+i);
             i++;
        }
        else if(*(p1+i)>*(p2+j))
        {
            *(p+k)=*(p2+j);
            j++;
        }
        else
        {
            *(p+k)=*(p2+j);
            k++;
            *(p+k)=*(p1+i);
            i++;j++; 
        }
        k++;
    }
    while(i<n1)
    {
        *(p+k)=*(p1+i);
        i++;k++;
    }
    while(j<n2)
    {
        *(p+k)=*(p2+j);
        k++,j++;
    }
    printf("THE elements in the 2nd array\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",*(p+i));
    }
    return 0;
}