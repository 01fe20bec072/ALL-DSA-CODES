#include<stdio.h>
#include<math.h>
int sum(int n)
{
    int i;
    int sum=0;
    for(i=0; i<=n; i++)
    {
        sum=sum+i;
    }
  return sum;
}
int main()
{
    int n,s;
    printf("Enter the number to calculate the sum\n");
    scanf("%d", &n);
    s=sum(n);
    printf("%d",s);
    return 0;
}
