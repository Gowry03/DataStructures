#include<stdio.h>
int findmin(int i,int a[100],int n)
{
    int min=i;
    for(int j=i+1;j<n;j++)
    {
        if(a[j]<a[min])
        {
            min=j;
        }
    }
    return min;
}
void selection(int a[100],int n)
{
    int i,min;
    for(i=0;i<n-1;i++)
    {
        min=findmin(i,a,n);
        int t=a[i];
        a[i]=a[min];
        a[min]=t;
    }
}
int main()
{
    int arr[]={4,2,7,5,8,4},size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements:\n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    selection(arr,6);
    for(int i=0;i<6;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}