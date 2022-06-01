#include<stdio.h>
void read(int *a,int *b,int n);
void ex(int *a,int *b,int n);
void display(int *a,int *b,int n);

void  main()
{
    int m[10];
    int n[10];
    int p;
    printf("Enter the no of elements\n");
    scanf("%d",&p);
    read(&m,&n,p);
    display(&m,&n,p);
    ex(&m,&n,p);
    display(&m,&n,p);

}
void read(int *a,int *b,int p )
{int i;
   for(i=0;i<p;i++)
    {printf("Enter the element of m array\n");
    scanf("%d",&(*a));
    a++;
}
for(i=0;i<p;i++)
    {printf("Enter the element of n array\n");
    scanf("%d",&(*b));
    b++;
}}
void display(int *a,int *b,int p )
{int i;
   for(i=0;i<p;i++)
    {printf("The exchanged set =%d\t",*a);

    a++;
}
  for(i=0;i<p;i++)
    {printf("The exchanged set =%d\t",*b);

    b++;
}
}

void ex(int *a,int *b,int p)
{int i,temp;
    for(i=0;i<p;i++)
    {temp=*a;
     *a=*b;
     *b=temp;
     a++;
     b++;
    }
}
