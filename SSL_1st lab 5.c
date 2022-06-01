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
NODE insert_specific_pos(NODE);
NODE delete_specific_pos(NODE);
void Display(NODE);
NODE getNode();
void main()
{
    int selection;
    NODE h=NULL;

    while(1)
    {
      printf("\nenter the choice  \n 1 to insert at specific position\n 2 to delete at specific position\n 3 to insert at front\n 4 to delete at front\n 5 to display\n 6 to exit\n");
      scanf("%d",&selection);

        switch(selection)
        {
            case 1:h=insert_specific_pos(h);
                    break;
            case 2:h=delete_specific_pos(h);
                    break;
            case 3:h=insert_front(h);
                    break;
            case 4: h=delete_front(h);
                    break;
            case 5:Display(h);
                    break;
            case 6: exit(0);
                    break;
            default:printf("Invalid selection\n");
        }
    }
}

NODE getNode()
{
    NODE NEWNODE;
    int ele;
    NEWNODE=malloc(sizeof(struct node));
    if(NEWNODE==NULL)
    {
        printf("Memory is not allocated\n");
    }
    printf("Enter the data part\n");
    scanf("%d",&ele);

    NEWNODE->data=ele;
    NEWNODE->next=NULL;

    return NEWNODE;
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
NODE insert_specific_pos(NODE h)
{
    int pos;
    printf("Enter the position\n");
    scanf("%d",&pos);
    if(h==NULL && pos>1)
    {
        printf("Cannot add element at position %d", pos);
        return h;
    }
    else if(pos==1)
    {
        h=insert_front(h);
        return h;
    }
    else
    {
        int i=1;
        NODE Newnode=getNode();
        NODE cur=h, prev=NULL;

        while(cur!=NULL && i<pos)
        {
            prev=cur;
            cur=cur->next;
            i++;
        }
        if(pos>1)
        {
            printf("Cannot add element at position %d", pos);
            return h;
        }
        else
        {
            prev->next=Newnode;
            Newnode->next=cur;
            return h;
        }

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
    printf("Node is Deleted %d\n", current->data);
    free(current);
    return h;
}
NODE delete_specific_pos(NODE h)
{
    int pos;
    printf("Enter the position of the node to be deleted\n");
    scanf("%d",&pos);
    if(h==NULL && pos>0)
    {
        printf("List is empty, cannot delete");
        return h;
    }
    else if(pos==1)
    {
        h=delete_front(h);
        return h;
    }
    else
    {
        int i=1;
        NODE cur=h, prev=NULL;
        while(cur!=NULL && i<pos)
        {
            prev=cur;
            cur=cur->next;
            i++;
        }
        prev->next=cur->next;
        printf("Element deleted is %d", cur->data);
        free(cur);
        return h;
    }
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
