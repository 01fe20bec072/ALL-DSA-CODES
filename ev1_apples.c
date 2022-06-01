#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
typedef struct node * APPLE;
APPLE getnode(int d);
APPLE insert(APPLE head, int data);
void apple(APPLE head);
void main()
{
    APPLE head = NULL;
    int n, a;
    printf("Enter the number of apple in the market\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a);
        head = insert(head,a);
    }
    apple(head);
}

APPLE getnode(int d)
{
    APPLE n =malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;
    return n;
}

APPLE insert(APPLE head, int data)
{
   APPLE temp = getnode(data);
    if(head==NULL)
        return temp;
    APPLE cur = head;
    while(cur->next != NULL)
        cur = cur->next;
    cur->next = temp;
    return head;
}

void apple(APPLE head)
{
    APPLE cur = head;
    int sum = 0;
    while(cur!=NULL)
    {
        if(cur->next==NULL)
        {
            if(cur->data%2==0||cur->data%5==0)
            {
                printf("%d ", cur->data);
                sum =sum+cur->data;
            }
            break;
        }
        if((cur->data%2==0||cur->data%5==0) && cur->next->data%3==0)
        {
            printf("%d ", cur->data);
            sum =sum+cur->data;
        }
        cur = cur->next;
    }
    printf("\n%d", sum);
}
