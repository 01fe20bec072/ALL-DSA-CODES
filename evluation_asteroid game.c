#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node* NODE;

NODE PUSH(NODE);
void Display(NODE);
NODE getNode();
NODE POP(NODE);

void main()
{
    int choice;
    NODE head=NULL;

    while(1)
    {
      printf("\nPress\n 1 for PUSH\n 2 for POP \n 3 for display\n 4 for exit\n");
      scanf("%d",&choice);

        switch(choice)
        {

            case 1:head=PUSH(head);
                    break;
            case 2: head= POP(head);
                    break;
            case 3:Display(head);
                    break;
            case 4:exit(0);
                    break;
            default:printf("Invalid choice\n");
        }
    }
}

NODE getNode()
{
    NODE NEWNODE;
    NEWNODE=malloc(sizeof(struct node));
    if(NEWNODE==NULL)
    {
        printf("Memory is not allocated\n");
    }
    printf("Enter the data part\n");
    scanf("%d",&NEWNODE->data);
    NEWNODE->next=NULL;
    return NEWNODE;
}


NODE POP(NODE head)
{
    if(head==NULL)
    {
        printf("Stack is empty!!can't delete \n");
        return head;
    }

    NODE cur=head;
    head=head->next;
    printf("\nDeleted %d\n",cur->data);
    free(cur);
    return head;
}

NODE PUSH(NODE head)
{
    NODE Newnode=getNode();
    if(head==NULL)
    {
        head=Newnode;
        return head;
    }
    else
    {
        Newnode->next=head;
        head=Newnode;
        return head;
    }
}
void Display(NODE head)
{
    if(head==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    NODE temp=head;
    printf("Displaying elements from top to bottom\n");
    while(temp!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }
}
