#include<stdio.h>
#include<stdlib.h>
typedef struct movie
{
char movie_title[40];
char producer[20];
char director[20];
char pr_house[30];
int release_year;
}M;
M m[5];
void read(M m[5],int n);
void sort(M m[5],int n);
void director(M m[5],int n);
void producer(M m[5],int n);
void display(M m[5],int n);
main()
{
int n;
M m[5];
printf("Enter number of movies\n");
scanf("%d",&n);
read(m,n);
printf("Details of directors\n");
director(m,n);
printf("Details of producers\n");
producer(m,n);
printf("Release years in the ascending order\n");
sort(m,n);
display(m,n);

}
void read(M m[5],int n)
{
int i;
for(i=0;i<n;i++)
{
printf("Enter the movie title\n");
scanf("%s",m[i].movie_title);
printf("Enter the director of the movie\n");
scanf("%s",m[i].director);
printf("Enter the name of producer\n");
scanf("%s",m[i].producer);
printf("Enter the production house\n");
scanf("%s",m[i].pr_house);
printf("Enter the released year\n");
scanf("%d",&m[i].release_year);
}}
void display(M m[5],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Movie:%s\n",m[i].movie_title);
         printf("producer:%s\n",m[i].producer);
         printf("production house:%s\n",m[i].pr_house);
                 printf("Director:%s\n",m[i].director);
                     printf("Released year:%d\n",m[i].release_year);


    }
}
void director(M m[5],int n)
{int i;
for(i=0;i<n;i++)
{
printf("Entered movie directors:%s\n",m[i].director);
}
}
void producer(M m[5],int n)
{
int i;
for(i=0;i<n;i++)
{
printf("producers:%s\n",m[i].producer);
}}
void sort(M m[5],int n)
{
    int i,j;
    M swap;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(m[j].release_year>m[j+1].release_year)
            {
                swap=m[j];
                m[j]=m[j+1];
                m[j+1]=m[j];
            }
        }

    }

display(m,n);
}
