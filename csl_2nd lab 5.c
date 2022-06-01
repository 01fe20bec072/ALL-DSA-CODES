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
NODE insert_end(NODE);
NODE delete_end(NODE);
void Display(NODE);
NODE getNode();
void main()
{
    int selection;
    NODE h=NULL;

    while(1)
    {
      printf("\nSelect\n 1 for insert at front\n 2 for delete at front\n 3 for insert at end\n 4 for delete at end\n 5 for display\n 6 for exit\n");
      scanf("%d",&selection);

        switch(selection)
        {
            case 1:h=insert_front(h);
                    break;
            case 2:h=delete_front(h);
                    break;
            case 3:h=insert_end(h);
                    break;
            case 4: h=delete_end(h);
                    break;
            case 5:Display(h);
                    break;
            case 6: exit(0);
                    break;
            default:printf("Invalid selection\n");
        }
    }
}
NODE getnode()
{
    NODE newNode;
    newNode=malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Not created\n");
        exit(0);
    }
    printf("Enter the data part\n");
    scanf("%d", &newNode->data);
    newNode->next=newNode;
    return newNode;
}
NODE insert_front(NODE h)
{
    NODE newNode, cur;
    newNode=getnode();
    if(h==NULL)
    {
        h=newNode;
        return h;
    }
    cur=h;
    while(cur->next!=h)
    {
        cur=cur->next;
    }
    newNode->next=h;
    cur->next=newNode;
    h=newNode;
    return h;
}
NODE delete_front(NODE h)
{
    NODE cur, prev, temp;
    if(h==NULL)
    {
        printf("List Empty\n");
        return h;
    }
    if(h->next==h)
    {
        printf("Deleted= %d\n", h->data);
        free(h);
        h=NULL;
        return h;
    }
    cur=h;
    while(cur->next!=h)
    {
        cur=cur->next;
    }
    temp=h;
    h=h->next;
    cur->next=h;
    printf("Deleted; %d\n", cur->data);
    free(temp);
    return h;
}
NODE insert_end(NODE h)
{
    NODE newNode, cur;
    newNode=getnode();
    if(h==NULL)
    {
        h=newNode;
        return h;
    }
    cur=h;
    while(cur->next!=h)
    {
        cur=cur->next;
    }
    cur->next=newNode;
    newNode->next=h;
    return h;
}
NODE delete_end(NODE h)
{
    NODE prev,cur;
    if(h==NULL)
    {
        printf("List is empty\n");
        return h;
    }
    if((h->next==h))
    {
        printf("Deleted: %d\n", h->data);
        free(h);
        h=NULL;
        return h;
    }
    prev=NULL;
    cur=h;
    while(cur->next!=h)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=h;
    printf("Deleted: %d\n", cur->data);
    free(cur);
    return h;
}
void Display(NODE h)
{
    NODE cur;
    if(h==NULL)
    {
        printf("Empty List\n");
        return NULL;
    }
    printf("Elements are\n");
    cur=h;
    while(cur->next!=h)
    {
        printf("%d\t", cur->data);
        cur=cur->next;
    }
    printf("%d\t", cur->data);
}
