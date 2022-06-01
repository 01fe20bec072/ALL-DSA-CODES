#include <stdio.h>
#include <stdlib.h>

void read(int a[],int n)
{
    int i;
    printf("\nEnter number of days after deadline for %d students:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void calc(int a[],int n)
{
    int i;
    int pen;
    int max=a[0]*2;
    float av;
    int min=a[0]*2;
    int sum=0;
    for(i=0;i<n;i++)
    {
        pen=2*a[i];
        sum=sum+pen;
        if(pen>max)
            max=pen;
        if(pen<min)
            max=pen;
    }
    av=sum/n;
    printf("\nAverage penalty:%f\n   Maximum penalty:%d\n   Minimum penalty:%d\n  Total penalty:%d\n",av,max,min,sum);
}

int main()
{
    int n;
    int a[100];
    printf("\nEnter number of students late n:");
    scanf("%d",&n);
    read(a,n);
    calc(a,n);
    return 0;
}
