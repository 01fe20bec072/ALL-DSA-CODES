#include<stdio.h>
#include<math.h>
int sum(int n)
{
    int vsum;
    sum= n*(n+1)/2;
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

