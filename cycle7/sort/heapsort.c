#include<stdio.h>
int i,size,a[50];
void heapify(int a[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&a[left]>a[largest])
    {
        largest=left;
    }
    if(right<n&&a[right]>a[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        int temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;
        heapify(a,n,largest);
    }
}
void heapsort(int a[],int n)
{
    for(i=(n/2)-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for(i=n-1;i>=0;i--)
    {
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }
}
int main()
{
    printf("Enter the size of the array:");
    scanf("%d",&size);
      printf("Enter the element:");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Printing the array\n");
    for(i=0;i<size;i++)
    {
        printf("%d\t",a[i]);
    }
    heapsort(a,size);
    printf("\nThe sorted array is\n");
    for(i=0;i<size;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}