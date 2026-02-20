#include<stdlib.h>
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements in the array:");
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    int *ptr=arr;
    int min=arr[0];
    for(int i=1;i<n;i++)
    {
        if(*(ptr+i)<min)min=*(ptr+i);
    }
    printf("smallest number is: %d",min);
}
