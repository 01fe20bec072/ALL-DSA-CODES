
#include<stdio.h>
#include<stdlib.h>
struct node
{
    char name[20],gender[6];
    int age;
    struct node *next;
};
typedef struct node *NODE;
NODE getNode();
NODE insert_position (NODE);
NODE delete_position (NODE);
NODE insert(NODE);
NODE Delete(NODE);
void total(NODE);
void display (NODE);
void main()
{
    int opt;
    NODE head=NULL;
    while(1)
    {
            printf("\nPress 1 to insert \nPress 2 to insert at position\nPress 3 to delete at position\nPress 4 to display\nPress 5 to delete\nPress 6 to get the count\nPress 7 to exit\n");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1: head=insert(head);
        break;
        case 2: head=insert_position(head);
        break;
        case 3: head=delete_position(head);
        break;
        case 4: display(head);
        break;
        case 5: head=Delete(head);
        break;
        case 6: total(head);
        break;
        case 7: exit(0);
        break;
        default:printf("Invalid entry!");
    }

    }
}
NODE getNode()
{
    NODE NEWNODE;
    int element;
    NEWNODE=malloc(sizeof(struct node));
    if(NEWNODE==NULL)
    {
        printf("Memory is not allocated\n");
    }
    printf("\nEnter the traveler's details\n");
    printf("\nName\tAge\tGender\n");
    scanf("%s%d%s",NEWNODE->name,&NEWNODE->age,NEWNODE->gender);
    return NEWNODE;
}
void display(NODE head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    NODE temp=head;
    while(temp!=NULL)
    {
        printf("%s\t%d\t%s\n",temp->name,temp->age,temp->gender);
        temp=temp->next;
    }
}
NODE insert(NODE head)
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
NODE Delete(NODE head)
{
    if(head==NULL)
    {
        printf("List is empty!!can't delete node\n");
        return head;
    }

    NODE cur=head;
    head=head->next;
    printf("\nDeleted travelor: %s\t%d\t%s\n",cur->name,cur->age,cur->gender);
    free(cur);

    return head;
}
NODE insert_position(NODE head)
{
    int pos,i=1;
    printf("Enter the position to insert");
    scanf("%d",&pos);

    NODE cur=head,prev=NULL;
    if (head==NULL&&pos>i)
    {
        printf("Cannot be inserted");
        return head;
    }
    else if (pos==1)
    {
    head=insert(head);
    return head;

  }
    else{
             NODE Newnode=getNode();
        while (cur!=NULL&&i<pos)
    {
        prev=cur;
        cur=cur->next;
        i++;
    }
    prev->next=Newnode;
    Newnode->next=cur;
    return head;
    }


}
NODE delete_position(NODE head)
{
    int pos;
    printf("Enter the position to delete:\n");
    scanf("%d",&pos);
    if (head==NULL&&pos>0)
    {
        printf("NO elements found. Cannot be deleted");
        return head;
    }
    else if(pos==1)
    {
        head=Delete(head);
    return head;
    }
    else
    {
        int i=1;
        NODE cur=head,prev=NULL;
        while(cur!=NULL&&i<pos)
        {
            prev=cur;
            cur=cur->next;
            i++;
        }
        prev->next=cur->next;
        printf("Deleted traveler: %s\t%d\t%s\n",cur->name,cur->age,cur->gender);
        free(cur);
        return head;
    }
}
void total(NODE head)
{
    NODE temp=head;
    int count=0;
    while (temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    printf("Total travelers : %d\n",count);
}
