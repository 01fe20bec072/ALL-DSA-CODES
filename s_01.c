#include <stdio.h>
#include <stdlib.h>
struct book_details
{
    char book_name[50];
    char author[20];
    int price,ISBN;
};
typedef struct book_details BD;
void read(BD [],int);
void print(BD [],int);
void sort_ISBN(BD x[],int);
void search(BD [],int);

void main()
{BD x[10];
int n;
printf("enter no of books\n");
scanf("%d",&n);
read(x,n);
print(x,n);
sort_ISBN(x,n);
search(x,n);

}
void read(BD x[10],int n)
{int i;
printf("Enter book details\n\n");
for(i=0;i<n;i++)
{printf("Enter book name:");
scanf("%s",x[i].book_name);
printf("enter author name:");
scanf("%s",x[i].author);
printf("Enter price:");
scanf("%d",&x[i].price);
printf("Enter ISBN:");
scanf("%d",&x[i].ISBN);
}
}
void print(BD x[10],int n)
{int i;
printf("\n Book details\n");
for(i=0;i<n;i++)
{printf("Book name:\t");
printf("%s\n",x[i].book_name);
printf("Author:\t");
printf("%s\n",x[i].author);
printf("price:\t");
printf("%d\n",x[i].price);
printf("ISBN:\t");
printf("%d\n",x[i].ISBN);
}
}
void sort_ISBN(BD x[10],int n)
{int i,j;
BD swap;
for(i=0;i<n-1;i++)
{for(j=0;j<n-i-1;j++)
{if (x[j].ISBN>x[j+1].ISBN)
{swap=x[j];
x[j]=x[j+1];
x[j+1]=swap;}
}
}
}
void search(BD x[10],int n)
{

     int i,key,flag=0;
     printf("Enter ISBN\t");
     scanf("%d",&key);
     for(i=0;i<n;i++)
     {if (x[i].ISBN==key)
     {
         flag=1;
         break;
     }
}
    if (flag==1)
    {  printf("Book name:\t");
    printf("%s\n",x[i].book_name);
    printf("Author:\t");
    printf("%s\n",x[i].author);
    printf("price:\t");
    printf("%d\n",x[i].price);
    printf("ISBN:\t");
    printf("%d\n",x[i].ISBN);
}
else
    printf("not found");

}
