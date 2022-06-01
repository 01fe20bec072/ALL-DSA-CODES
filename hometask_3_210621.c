#include<stdio.h>
#include<stdlib.h>
struct node
{
    char name[30],from[30],to[30];
    int id;
    float weight;
    struct node *next;
};
typedef struct node *NODE;
NODE getNode();
NODE insert(NODE);
NODE Delete(NODE);
void search(NODE);
NODE delete_specific(NODE);
void display (NODE);
void main()
{
    int opt;
    NODE head=NULL;
    while(1)
    {
            printf("\nPress 1 to insert details\nPress 2 to delete details\nPress 3 to display details\nPress 4 to search details\nPress 5 to delete a specific detail\nPress 6 to exit\n");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1: head=insert(head);
        break;
        case 2: head=Delete(head);
        break;
        case 3: display(head);
        break;
        case 4: search(head);
        break;
        case 5: head=delete_specific(head);
        break;
        case 6: exit(0);
        break;
        default:printf("Invalid entry!");
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
    printf("Enter the passenger details\n");
    printf("\nluggage id\tname\tsource\tdestination\tlug.weight\n");
    scanf("%d%s%s%s%f",&NEWNODE->id,NEWNODE->name,NEWNODE->from,NEWNODE->to,&NEWNODE->weight);
    NEWNODE->next=NEWNODE;
    return NEWNODE;
}
NODE insert(NODE head)
{
    NODE newnode,cur;
    newnode=getNode();
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    cur=head;
    while(cur->next!=head)
    {
        cur=cur->next;
    }
    newnode->next=head;
    cur->next=newnode;
    head=newnode;
    return head;
}
NODE Delete(NODE head)
{
    NODE prev,cur,temp;
    if(head==NULL)
    {
        printf("\nEmpty list\n");
        return head;

    }
    if(head->next==head)
    {
        printf("Deleted passenger details: %d\t%s\t%s\t%s\t%f\n",head->id,head->name,head->from,head->to,head->weight);
        free(head);
        head=NULL;
        return head;
    }
    cur=head;
    while(cur->next!=head)
    {
        cur=cur->next;
    }
    temp=head;
    head=head->next;
    cur->next=head;
        printf("Deleted passenger details: %d\t%s\t%s\t%s\t%f\n",temp->id,temp->name,temp->from,temp->to,temp->weight);
    free(temp);
    return head;
}
NODE delete_specific(NODE head)
{
    int key;
    printf("Enter the luggage id to delete:\n");
    scanf("%d",&key);
    if (head==NULL)
    {
        printf("NO elements found. Cannot be deleted");
        return head;
    }
    else if(head->id==key)
    {
        head=Delete(head);
    return head;
    }
    else
    {
        NODE cur=head,prev=NULL;
        while(cur->next!=head&&cur->id!=key)
        {
            prev=cur;
            cur=cur->next;
        }
        prev->next=cur->next;
        printf("Deleted passenger details: %d\t%s\t%s\t%s\t%f\n",cur->id,cur->name,cur->from,cur->to,cur->weight);
        free(cur);
        return head;
    }
}
void search(NODE head)
{
    NODE cur=head;
    int pid,flag=0;
    printf("Enter the luggage id to be searched:\n");
    scanf("%d",&pid);
    while(cur->next!=head)
    {
        if(cur->id==pid)
        {
            flag=1;
            printf("Passenger details found:\n%d\t%s\t%s\t%s\t%f\n",cur->id,cur->name,cur->from,cur->to,cur->weight);
        }
        cur=cur->next;
    }
     if(cur->id==pid)
        {
            flag=1;
            printf("Passenger details found:\n%d\t%s\t%s\t%s\t%f\n",cur->id,cur->name,cur->from,cur->to,cur->weight);
        }
        if(flag==0)
        {
            printf("No records found!\n");
        }
}
void display(NODE head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    NODE temp=head;
    while(temp->next!=head)
    {
        printf("%d\t%s\t%s\t%s\t%0.2f kg\n",temp->id,temp->name,temp->from,temp->to,temp->weight);
        temp=temp->next;
    }
   printf("%d\t%s\t%s\t%s\t%0.2f kg\n",temp->id,temp->name,temp->from,temp->to,temp->weight);

}
