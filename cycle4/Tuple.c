#include<stdio.h>
struct term
{
    int value;
    int row;
    int col;
};
void convertTuple(struct term t[],int ma[100][100],int m,int n)
{
    int i,j,k=1;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(ma[i][j]!=0)
            {
                t[k].value=ma[i][j];
                t[k].row=i;
                t[k].col=j;
                k++;
            }
        }
    }
    t[0].row=m;t[0].col=n;t[0].value=k-1;
}
void printTuple(struct term t[])
{
    printf("\nrow\tcolumn\tvalue\n");
    for(int i=0;i<=t[0].value;i++)
    {
        printf("%d\t%d\t%d\n",t[i].row,t[i].col,t[i].value);
    }
}
void transpose(struct term t1[],struct term t2[])
{
    int n,i,j,k=1;
    n=t1[0].value;
    t2[0].value=n;
    t2[0].col=t1[0].row;
    t2[0].row=t1[0].col;
    if(n>0)
    {
        for(i=0;i<t1[0].col;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(t1[j].col==i)
                {
                    t2[k].col=t1[j].row;
                    t2[k].row=t1[j].col;
                    t2[k].value=t1[j].value;
                    k++;
                }
            }
        }
    }
}
void sum(struct term a[],struct term b[],struct term c[])
{
    int i=1,j=1,k=1;
    if(a[0].row==b[0].row&&a[0].col==a[0].col)
    {
        while(i<=a[0].value&&j<=b[0].value)
        {
            if(a[i].row<b[j].row||((a[i].row==b[j].row)&&(a[i].col<b[j].col)))
            {
                c[k]=a[i];
                i++;k++;
            }
            else if(a[i].row>b[j].row||((a[i].row==b[j].row)&&(a[i].col>b[j].col)))
            {
                c[k]=b[j];
                j++;k++;
            }
            else
            {
                if((a[i].value+b[j].value)!=0)
                {
                    c[k]=a[i];
                    c[k].value=a[i].value+b[j].value;
                    k++;
                }
                i++;j++;
            }
        }
        while(i<=a[0].value)
        {
            c[k]=a[i];
            i++;k++;
        }
        while(j<=b[0].value)
        {
            c[k]=b[j];
            j++;k++;
        }
        c[0].value=k-1;
        c[0].row=a[0].row;
        c[0].row=a[0].col;
    } 
}
void main()
{
    int i,j,m1,n1,m2,n2,mat1[100][100],mat2[100][100];
    struct term a[100],b[100],c[100],t[100];
    printf("Enter the row of 1st matrix\n");
    scanf("%d",&m1);
    printf("Enter the columnof 1st matrix\n");
    scanf("%d",&n1);
    printf("Enter the row of 2nd matrix\n");
    scanf("%d",&m2);
    printf("Enter the row of2nd matrix\n");
    scanf("%d",&n2);
    printf("Enter the 1st matrix\n");
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
            printf("Enter the %d th row and %d th column element\n",i,j);
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("Enter the 2nd matrix\n");
    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
            printf("Enter the %d th row and %d th column element\n",i,j);
            scanf("%d",&mat2[i][j]);
        }
    }
    convertTuple(a,mat1,m1,n1);
    printf("Matrix1\n");
    printTuple(a);
    convertTuple(b,mat2,m2,n2);
    printf("Matrix2\n");
    printTuple(b);
    printf("Transpose of Matrix1:\n");
    transpose(a,t);
    printTuple(t);
    sum(a,b,c);
    printf("Sum:\n");
    printTuple(c);
}