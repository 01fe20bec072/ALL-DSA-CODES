#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node* NODE;

NODE getnode();
NODE insertend(NODE head);
NODE insertbeg(NODE head);
NODE deleteend(NODE head);
NODE deletebeg(NODE head);
void display(NODE head);

int main()
{
    int choice;
    NODE head= NULL;

    while(1)
    {
        printf(" Enter your choice\n 1. insert at end of the list\n 2. To insert at begining of  the list\n 3. To delete at the end of the list\n 4. To delete from begining of the list\n  5. To display the complete list\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 : head= insertend(head);
                     break;
            case 2 : head= insertbeg(head);
                     break;
            case 3 : head= deleteend(head);
                     break;
            case 4 : head= deletebeg(head);
                     break;
            case 5 : display(head);
                     break;

            default: printf("Invalid choice\n");

        }
    }
}
NODE getnode()
{
    NODE newnode;
    int e;
    newnode = (NODE)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("List is empty\n");

    }

    printf("Enter the data part\n");
    scanf("%d", &e);
    newnode->data = e;
    newnode->next=NULL;

    return newnode;

}
NODE insertend(NODE head)
{
    NODE newnode=getnode();
    if(head==NULL)
    {
        head=newnode;
        return newnode;
    }
    else
    {
       NODE temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next=newnode;
        return head;
    }
}

NODE insertbeg(NODE head)
{
    NODE newnode=getnode();
    if(head==NULL)
    {
        head=newnode;
        return newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }

    return head;
}
NODE deleteend(NODE head)
{
    if(head==NULL)
    {
        printf("List empty\n");
        return head;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return head;
    }
    NODE cur=head;
    NODE prev=NULL;
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=NULL;
    printf("The deleted data is=%d",cur->data);
    free(cur);
    return head;
}
NODE deletebeg(NODE head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    NODE temp=head;
    head=head->next;
    printf("The deleted data is=%d", temp->data);
    free(temp);
    return head;
}
void display(NODE head)
{
     if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    NODE temp=head;
    while(temp!=NULL)
    {
        printf("%d--->", temp->data);
        temp=temp->next;

    }

}
