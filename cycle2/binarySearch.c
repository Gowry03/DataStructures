#include<stdio.h>
void main()
{
    int low=0,high=0,mid,n,a[100],key;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("enter the elements in the array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the key:");
    scanf("%d",&key);
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
        {
            printf("Key is found at %dth index",mid);
            return;
        }
        else if(a[mid]>key)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    printf("key not found\n");
}