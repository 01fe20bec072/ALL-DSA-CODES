#include<stdio.h>
void readarray( int [], int);
void printarray( int [], int);
void count_frequency(int [], int);
int main()
{
    int n, a[10];
    printf("Enter the numbers to be counted\n");
    scanf("%d",&n);
    readarray(a,n);
    printarray(a,n);
    count_frequency(a,n);
    return 0;
}

void readarray( int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);

    }
}
void printarray( int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\n", a[i]);

    }
}

void count_frequency(int a[], int n)
{
   int i;
   int negative=0 , positive;
   for(i=0; i<n; i++)
   {
       if(a[i]<0)
        negative++;
       else if(a[i]>0)
       positive++;
       else
        printf("Not available\n");
   }
     printf("The positive number frequency is=%d\n", positive);
     printf("The negative number frequency is=%d\n", negative);
}

