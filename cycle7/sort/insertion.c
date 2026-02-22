#include<stdio.h>

void insertion(int a[100], int n)
{
    int key, i, j;
    for(i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

int main()
{
    int a[100], size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements:\n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    insertion(a, size);

    printf("Sorted array:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}