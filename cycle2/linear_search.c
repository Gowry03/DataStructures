#include<stdio.h>
void main()
{
    int n,a[100],key;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("enter the elements in the array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the key to be searched: ");
    scanf("%d",&key);
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            printf("Key found at %d th index",i);
            break;
        
        }
    }
}