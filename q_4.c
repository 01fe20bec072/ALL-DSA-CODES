#include<stdio.h>
void readarray( int [], int);
void printarray( int [], int);
void average(int [], int);
int main()
{
    int n, a[10] ;
    printf("Enter the numbers\n");
    scanf("%d",&n);
    readarray(a,n);
    printarray(a,n);
    average(a,n);
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

void average(int a[], int n)
{
    float average, sum=0.00;
    int   i ,above=0, below=0;
    for(i=0; i<n; i++)
    {
        sum=sum+a[i];
        average=sum/n;

    }
    printf("sum=%f\n", sum);
    printf("average=%f\n", average);

    for(i=0; i<n; i++)
    {
        if(a[i]<average)
        {
            below++;
        }
        else if(a[i]>average)
        {
            above++;

        }
    }

    printf("the students below average=%d\n", below);
    printf("the students above average=%d\n", above);

}
