#include<stdio.h>
void read(int *a,int n);
void check(int m[],int n);
void display(int *a,int n);
int main()
{
    int n;
    printf("Enter the odd no of elements in array\n");
    scanf("%d",&n);

    int m[10];

    read(&m,n);
    display(&m,n);
    check(m,n);
}
void read(int *a,int n )
{int i;
   for(i=0;i<n;i++)
    {printf("Enter the element\n");
    scanf("%d",&(*a));
    a++;
}}

void display(int *a,int n )
{int i;
   for(i=0;i<n;i++)
    {printf("%d\n",*a);

    a++;
}}

void check(int m[],int n)
{int x,i;
int sum=0;
int sum2=0;
    x=(n-1/2)+1;
    for(i=0;i<x;i++)
    {
        sum=sum+m[i];
    }
    for(i=n;i>x;i--)
    {
        sum2=sum2+m[i];
    }
    if(sum2==sum)
        printf("The array is in equilibrium\n");
}
