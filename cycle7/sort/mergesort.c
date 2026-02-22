#include<stdio.h>
void merge(int a[100],int low,int mid,int high)
{
    int i,j,k=0,b[100];
    i=low;j=mid+1;
    while(i<=mid&&j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++,k++;
        }
        else
        {
            b[k]=a[j];
            j++;k++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        i++,k++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        j++;k++;
    }
    k=0;
    for(i=low;i<=high;i++)
    {
        a[i]=b[k];
        k++;
    }
}
void ms(int a[100],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        ms(a,low,mid);
        ms(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
int main() {
    int a[100],size;
     printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements:\n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    ms(a, 0, size-1);
    for (int i = 0; i < size; i++) {
        printf("%d\n", a[i]);
    }
    
    return 0;
}