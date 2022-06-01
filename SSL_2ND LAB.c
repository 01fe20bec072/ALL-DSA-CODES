#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node* NODE;

NODE insert_front(NODE);
NODE delete_front(NODE);
void Display(NODE);
NODE getNode();
void main()
{
    int selection;
    NODE h=NULL;

    while(1)
    {
      printf("Enter 1. To insert front\n Enter 2. To delete front\n Enter 3. To Display\n Enter 4. To exit\n ");
      scanf("%d",&selection);

        switch(selection)
        {
            case 1:h=insert_front(h);
                    break;
            case 2:h=delete_front(h);
                    break;
            case 3:Display(h);
                    break;
            case 4:exit(0);
                    break;
            default:printf("Invalid selection\n");
        }
    }
}

NODE getNode()
{
    NODE new_node;
    int ele;
    new_node=malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        printf("Memory is not allocated\n");
    }
    printf("Enter the data part\n");
    scanf("%d",&ele);

    new_node->data=ele;
    new_node->next=NULL;

    return new_node;
}
NODE insert_front(NODE h)
{
    NODE new_node=getNode();
    if(h==NULL)
    {
        h=new_node;
        return h;
    }
    else
    {
        new_node->next=h;
        h=new_node;
        return h;
    }
}
NODE delete_front(NODE h)
{
    if (h==NULL)
    {
        printf("List is empty cannot delete node\n");
        return h;
    }
    NODE current=h;
    h=h->next;
    printf("Node Deleted %d\n", current->data);
    free(current);
    return h;
}
void Display(NODE h)
{
    if(h==NULL)
    {
        printf("List is empty\n");
        return;
    }
    NODE temp=h;
    while(temp!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }
}
