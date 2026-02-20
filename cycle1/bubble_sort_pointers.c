# include<stdlib.h> 
# include<stdio.h> 
int main() 
{ 
    int n,i,j; 
    int *p; 
    p=(int *)malloc(n*sizeof(int)); 
    printf("Enter the number of elements of the array:"); 
    scanf("%d",&n); 
    printf("Enter the elements:"); 
    for(i=0;i<n;i++) 
    { 
        scanf("%d",(p+i)); 
    } 
    for(i=0;i<n-1;i++) 
    { 
        for(j=0;j<n-i-1;j++) 
        { 
            if(*(p+j)>*(p+j+1)) 
            { 
                int temp=*(p+j); 
                *(p+j)=*(p+j+1); 
                *(p+j+1)=temp; 
            } 
        } 
    } 
    for(j=0;j<n;j++) 
    { 
        printf("%d\t",*(p+j)); 
} 
printf("\n"); 
free(p); 
return 0; 
} 