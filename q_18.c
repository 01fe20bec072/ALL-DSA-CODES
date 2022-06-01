#include<stdio.h>
void read(int *a,int n);
void sum(int m[],int n);
void display(int *a,int n);
int main()
{
    int n;
    printf("Enter the odd no of elements in array\n");
    scanf("%d",&n);

    int m[10];

    read(&m,n);
    display(&m,n);
    sum(m,n);
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

void sum(int m[],int n)
{int i,j;
    for(j=0;j<n-1;j++)
   { int sum=0;
       for(i=j+1;i<n;i++)
        {sum=sum + m[i];}
    printf("The sum of the array is=%d\n",sum);
    }

}
