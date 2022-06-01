#include<stdio.h>
#include<strings.h>

 struct student
{
    int r;
    char name[20];
    float per;

};
void read( struct student*b,int n);
void display( struct student*b,int n);
 struct student a[10];
void main()
{int n;
struct student *b=&a;
    printf("Enter the no of students\n");
    scanf("%d",&n);
    read(&a,n);
    display(&a,n);
}
void read(struct student*b,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d %s %f",&b->r,&b->name,&b->per);
        b++;

    }
}
void display( struct student*b,int n)
{int i;
    for(i=0;i<n;i++)
    {
        printf("%d\n %s\n %f\n",b->r,b->name,b->per);
        b++;

    }

}

