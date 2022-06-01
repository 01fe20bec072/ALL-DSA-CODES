#include<stdio.h>
void prime(int a[],int n);
void display(int k);
void read(int a[],int n);
void main()
{ int a[10];
    int n;
    printf("Enter the no of elements\n");
    scanf("%d",&n);
     read(a,n);
     printf("Prime no among the elements\n");
    prime(a,n);

}
void read(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void prime(int a[],int n)
{
    int i,j,count;
    for(i=0;i<n;i++)
    {count=0;
    for(j=1;j<=a[i];j++)
    {
        if(a[i]%j==0)
            count++;}
        if(count<3)
            display(a[i]);}
        }

void display(int k)
{
    printf("%d\n",k);
}
