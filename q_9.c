#include<stdio.h>
void read(int a[],int n);
void search(int a[],int n);
void o(int a[],int n);

void main()
{ int a[15];
    int n;
    printf("Enter the no of students\n");
    scanf("%d",&n);
    read(a,n);
    search(a,n);
    o(a,n);

}

void read(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter the number of marks\n");
        scanf("%d",&a[i]);

    }
}

void search(int a[],int n)
{
    int odd=0,even=0,i;
    for(i=0;i<n;i++)
    {
     if(a[i]%2==0)
     {
         even++;
     }
     else
        odd++;
    }
    printf("The number of students who scored even is %d\n",even);
    printf("The number of students who scored odd is %d\n",odd);
}
void o(int a[],int n)
{int i,count=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==10)
        {count++;

}    }
if(count==0)
{
    printf("Students did not score out of out\n");
}
else
    printf("Number of students who scored out of out are %d\n",count);
}
