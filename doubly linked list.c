#include<stdio.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node * insert_end(struct node* head)
{
    struct node *newn, *temp;
    newn=(struct node*)malloc(size(struct node));
    if(newn==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter the data\n");
    scanf("%d",&newn->data);
    if(head==NULL)
    {
        head=newn;
    }
    temp=head;
    while(head->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newn;
    newn->prev=temp;
    newn->next=NULL;
    return (head);
}
struct node * insert_beg(struct node* head)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));

}
