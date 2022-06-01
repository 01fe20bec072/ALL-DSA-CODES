#include<stdio.h>
void readarray( int [], int);
void printarray( int [], int);
void ascending( int [], int );
void ranks(int [], int);
int main()
{
    int n, a[100];
    printf("Enter the number of students\n");
    scanf("%d",&n);
    printf("Enter the students rankings\n");
    readarray(a,n);
    printarray(a,n);
    ascending(a,n);
    ranks(a,n);
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

void ascending(int a[], int n)
{
    int i, j,x;
    for (i = 0; i < n; ++i)
        {

            for (j = i + 1; j < n; ++j)
            {

                if (a[i] > a[j])
                {

                    x =  a[i];
                    a[i] = a[j];
                    a[j] = x;

                }

            }

        }

        printf("The numbers arranged in ascending order are given below \n");
        for (i = 0; i < n; ++i)
            printf("%d\n", a[i]);

}

void ranks(int a[], int n)
{
    int l=a[0], i, b=a[0];
    for(i = 1; i < n; i++)
    {
        if(a[i]>l)
         l=a[i];
    }
    printf("The highest rank is%d\n", l);


    for(i = 1; i < n; i++)
    {
        if(a[i]<b)
         b=a[i];
    }
    printf("The lowest rank is%d\n", b);
}
