#include<stdio.h>
void readarray(int arr[], int n);
void rvereseArray(int arr[], int start, int end);
void printArray(int arr[], int size);

int main()
{
    int n, arr[10];
    printf("Enter the number to be reversed\n");
    scanf("%d", &n);
    readarray(arr,n);
    printArray(arr,n);
    rvereseArray(arr, 0, n-1);
    printf("Reversed array is \n");
    printArray(arr,n);
    return 0;

}

void readarray(int arr[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);

    }
}
void rvereseArray(int arr[], int start, int end)
{
     int temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void printArray(int arr[], int size)
{
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);

  printf("\n");
}


