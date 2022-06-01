#include<stdio.h>
void read(int[],int);
void bonus(int[],int);
void salary(int [],int);
void main()
{
 int a[100],n;
 printf("Enter number of employees:");
 scanf("%d",&n);
 read(a,n);
 bonus(a,n);
 salary(a,n);
}

void read(int a[],int n)
{
 for(int i=0;i<n;i++)
 {
  printf("Enter eperience in years:");
  scanf("%d",&a[i]);
 }
}

void bonus(int a[],int n)
{
float bonus;
for(int i=0;i<n;i++)
 {
  if(a[i]>=5&&a[i]<=7)
  {
   bonus=0.1*10600;
  }
  else if(a[i]>=8&&a[i]<10)
  {
   bonus=0.2*21300;
  }
  else if(a[i]>10)
  {
   bonus=32100*0.3;
  }
  else
  {
   printf("Enter proper number");
  }
 printf("bonus is:%f\n",bonus);
 }
}

void salary(int a[],int n)
{
float total_salary;
for(int i=0;i<n;i++)
 {
 if(a[i]>=5&&a[i]<=7)
 {
  total_salary=10600*0.1+10600;
 }
 else if(a[i]>=8&&a[i]<10)
 {
  total_salary=0.2*21300+21300;
 }
 else if(a[i]>10)
 {
  total_salary=32100*0.3+32100;
 }
 printf("total salary:%f\n",total_salary);
 }
}

