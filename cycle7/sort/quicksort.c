#include<stdio.h>
void quicksort(int a[100],int low,int high)
{
    int i,j,pivot;
    if(low<high)
    {
        i=low+1;j=high;pivot=low;
        while(i<=j)
        {
            while(a[i]<=a[pivot])
            {
                i++;
            }
            while(a[j]>a[pivot])
            {
                j--;
            }
            if(i<j)
            {
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
        int t1=a[low];
        a[low]=a[j];
        a[j]=t1;
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}
int main()
{
    int arr[]={4,2,7,5,8,3},size;
     printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements:\n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    quicksort(arr,0,5);
    for(int i=0;i<6;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}