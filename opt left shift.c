#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;

};

typedef struct node * NODE;
NODE getNode()
{
    NODE newNode;
    newNode=(NODE)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("List empty\n");
        exit(0);
    }

    printf("Enter the data\n");
    scanf("%d", &newNode->data);

    newNode->next=newNode;
     newNode->prev=newNode;

     return newNode;

}

NODE insertend(NODE head)
{
    NODE newNode;
    newNode=getNode();
    if(newNode==NULL)
    {
        head=newNode;
        return head;
    }

    else
    {
        NODE last=head->prev;
        last->next=newNode;
        newNode->prev=last;
        newNode->next=head;
        head->prev=newNode;
    }
    return head;


}
NODE leftshift(NODE head)
{
    int k, i;
    NODE temp;
   printf("Enter the value to be left shifted\n");
   scanf("%d",&k);
   for(i=0; i<k; i++)
   {
       head=head->next;
       temp=head;
       while(head->next!=head)
       {
           temp=temp->next;
       }
       temp->next=head->prev;
       temp->next->next=head;
   }
   return head;
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

int main()
{
    struct node *head;
    int n,i;
    head=NULL;
    printf("\nEnter n: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        head=insertend(head);
    printf("Elements before left shift\n");
    disp(head);
    head=leftshift(head);
    printf("Elements after left shift\n");
    disp(head);
    return 0;
}
