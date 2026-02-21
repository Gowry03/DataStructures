#include<stdio.h>
struct poly
{
    float coeff;
    int exp;
}p[100],q[100],r[100];
void sort(struct poly p[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(p[i].exp<p[j].exp)
            {
                int t=p[i].exp;
                float t1=p[i].coeff;
                p[i].exp=p[j].exp;
                p[i].coeff=p[j].coeff;
                p[j].coeff=t1;
                p[j].exp=t;
            }
        }
    }
}
int main()
{
    int m1,n1;
    printf("Enter the number of terms in the 1st polynomial: ");
    scanf("%d",&m1);
    printf("Enter the number of terms in the 2nd polynomial: ");
    scanf("%d",&n1);
    int i,j,k;
    i=0;j=0;k=0;
    printf("Enter the terms in the 1st polynomial\n");
    for(i=0;i<m1;i++)
    {
        printf("Enter the %d th coefficient: ",i+1);
        scanf("%f",&p[i].coeff);
        printf("Enter the %d th exponent: ",i+1);
        scanf("%d",&p[i].exp);
    }
    printf("Enter the terms in the 2nd polynomial\n");
    for(i=0;i<n1;i++)
    {
        printf("Enter the %d th coefficient: ",i+1);
        scanf("%f",&q[i].coeff);
        printf("Enter the %d th exponent: ",i+1);
        scanf("%d",&q[i].exp);
    }
    i=0;
    sort(p,m1);
    sort(q,n1);
    while(i<m1&&j<n1)
    {
        if(p[i].exp>q[j].exp)
        {
            r[k]=p[i];
            i++;k++;
        }
        else if(p[i].exp<q[j].exp)
        {
            r[k]=q[j];
            j++;k++;
        }
        else 
        {
            r[k].coeff=p[i].coeff+q[j].coeff;
            r[k].exp=p[i].exp;
            i++;j++;k++;
        }
    }
    while(i<m1)
    {
        r[k]=p[i];
        i++;k++;
    }
    while(j<n1)
    {
        r[k]=q[j];
        j++;k++;
    }
    int n=m1+n1;
    printf("\npolynomial p= ");
    for(i=0;i<m1;i++)
    {
        printf("%.2fx^%d",p[i].coeff,p[i].exp);
        if(i!=m1-1)
        {
            printf("+");
        }
    }
    printf("\npolynomial q= ");
    for(i=0;i<n1;i++)
    {
        printf("%.2fx^%d",q[i].coeff,q[i].exp);
        if(i!=n1-1)
        {
            printf("+");
        }
    }
    printf("\npolynomial r= ");
    for(i=0;i<k;i++)
    {
        printf("%.2fx^%d",r[i].coeff,r[i].exp);
        if(i!=k-1)
        {
            printf("+");
        }
    }
    return 0;
}