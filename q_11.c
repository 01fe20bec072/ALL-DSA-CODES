#include<stdio.h>
void read(int *a,int n);

void display(int m[],int n);
int main()
{
    int n;
    printf("Enter the no of elements in array\n");
    scanf("%d",&n);

    int m[10];

    read(&m,n);
    display(m,n);

}
void read(int *a,int n )
{int i;
   for(i=0;i<n;i++)
    {printf("Enter the element\n");
    scanf("%d",&(*a));
    a++;
}}

void display(int m[],int n)
{int i;
float r;
   for(i=0;i<n;i++)
   {
       if(m[i]<=100)
       {
           r=1.5*m[i];
       }
       else if(m[i]>100 && m[i]<=250)
       {
          r=m[i]*2.3;
       }
       else if(m[i]>250 && m[i]<600)
       {
           r=m[i]*4;
       }
       else{r=5.5*m[i];}
       printf("Bill for i flat is %f\n",r);
   }
   }
