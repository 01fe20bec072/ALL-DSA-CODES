#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};


void disp(struct node *);
struct node* insertr(struct node *);
struct node * leftshift(struct node *);



int main()
{
    struct node *head;
    int n,i;
    head=NULL;
    printf("\nEnter n: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        head=insertr(head);
    printf("Elements before left shift\n");
    disp(head);
    head=leftshift(head);
    printf("Elements after left shift\n");
    disp(head);
    return 0;
}
void disp(struct node *head)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("\n%d",temp->data);
        temp=temp->next;
    }
}

struct node * insertr(struct node *head)
{
    struct node *nw,*temp;
    nw=(struct node *)malloc(sizeof(struct node));
    nw->next=NULL;
    if(nw==NULL)
    {
        printf("\nMemomry not allocated");
        exit(0);
    }
    printf("\nEnter data:");
    scanf("%d",&nw->data);
    if(head==NULL)
    {
        head=nw;
    }
    else
    {
        temp=head;
        while(temp->next!=temp)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }
    return(head);
}

struct node * leftshift(struct node *head)
{
   struct node *temp, *cur;
   int k, i;
   printf("Enter the value to be left shifted\n");
   scanf("%d",&k);
   for(i=0; i<k; i++)
   {
       temp=head;
       head=temp->next;
       temp->next=NULL;
       cur=head;
       while(cur->next!=NULL)
       {
           cur=cur->next;
       }
       cur->next=temp;
       disp(head);
   }
}
