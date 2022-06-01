#include<stdio.h>
void readarray( int [], int);
void printarray( int [], int);
void display_index(int [], int);
int main()
{
    int n, a[10] , c;
    printf("Enter the numbers \n");
    scanf("%d",&n);
    readarray(a,n);
    printarray(a,n);
    display_index(a,n);

    return 0;
}

void readarray( int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);

    }
}
void printarray( int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\n", a[i]);

    }
}

void display_index(int a[], int n)
{
    int i,j, key;
    int flag=0;
    printf("Enter the key to be searched\n");
    scanf("%d",&key);
    for(i=0; i<n; i++)
    {
        if(key==a[i])
          {printf("Key found\n");
          j=i;
          flag=1;



    }}
    if(flag==0)
    {
       printf("Key not found\n");
    }
else
    printf("The index at which the key is present is=%d\n",j);

}

