#include<stdio.h>
#include<stdlib.h>

struct book
{
    int ISBN;
    char name[100];
    char auth[50];
};
typedef struct book ab;


void read(ab b[100],int n);
void display(ab b[100],int n);
void search(ab b[100],int n);
void sort(ab b[100],int n);
int main()
{
    ab b[100];
    int n;
    printf("enter the no of books:");
    scanf("%d",&n);
    read(b,n);
    display(b,n);
    search(b,n);
    sort(b,n);
    display(b,n);
    return 0;
}

void read(ab b[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("enter the ISBN:");
        scanf("%d",&b[i].ISBN);
        printf("enter the book name:");
        scanf("%s",b[i].name);
        printf("enter author name:");
        scanf("%s",b[i].auth);
    }
}

void display(ab b[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
    printf("\n ISBN:%d",b[i].ISBN);
    printf("\n book name:%s",b[i].name);
    printf("\n author name:%s",b[i].auth);
    printf("\n");
    }
}


void search(ab b[100],int n)
{
    int i,s,k=0;
    printf("enter the ISBN to search:");
    scanf("%d",&s);
    for(i=0;i<n;i++)
    {
        if(s==b[i].ISBN)
        {
            k=1;
            printf("\nKey found\n");
            printf("\n ISBN:%d",b[i].ISBN);
            printf("\n book name:%s",b[i].name);
            printf("\n author name:%s",b[i].auth);
            printf("\n");
            break;
        }
    }
    if(k==0)
        printf("\nKey not found");
}

void sort(ab b[100],int n)
{
int i,j;
ab swap;
for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(b[j].ISBN > b[j+1].ISBN)
      {
        swap= b[j];
        b[j]= b[j+1];
        b[j+1]=swap;
      }
    }
  }
  printf("After sorting \n");
}
