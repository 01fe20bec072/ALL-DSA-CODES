#include <stdio.h>
#include <stdlib.h>
struct movie_details
{
    char name[50];
    char producer[20];
    int year;
    char director;
    char ph;

};
typedef struct movie_details MD;
void read(MD [],int);
void print(MD [],int);
void year_sort(MD x[],int);
//void search(MD [],int);

void main()
{MD x[10];
int n;
printf("enter no of movies\n");
scanf("%d",&n);
read(x,n);
print(x,n);
year_sort(x,n);
//search(x,n);

}
void read(MD x[10],int n)
{int i;
printf("Enter movie details\n\n");
for(i=0;i<n;i++)
{printf("Enter movie name:");
scanf("%s",x[i].name);
printf("enter producer name:");
scanf("%s",x[i].producer);
printf("Enter year:");
scanf("%d",&x[i].year);
printf("Enter director name:");
scanf("%s",x[i].director);
printf("enter production house:");
scanf("%s",x[i].ph);

}
}
void print(MD x[10],int n)
{int i;
printf("\n Book details\n");
for(i=0;i<n;i++)
{printf("movie name:\t");
printf("%s\n",&x[i].name);
printf("producer:\t");
printf("%s\n",&x[i].producer);
printf("year:\t");
printf("%d\n",x[i].year);
printf("director name:\t");
printf("%s\n",x[i].director);
printf("production house:\t");
printf("%s\n",x[i].ph);

}
}
void year_sort(MD x[10],int n)
{int i,j;
MD swap;
for(i=0;i<n-1;i++)
{for(j=0;j<n-i-1;j++)
{if (x[j].year>x[j+1].year)
{swap=x[j];
x[j]=x[j+1];
x[j+1]=swap;}
}
}
}
/*void search(BD x[10],int n)
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
*/
