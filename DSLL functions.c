/*DLL functions*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;

};

typedef struct node * NODE;

NODE getNode();
NODE insert_end(NODE);
NODE insert_front(NODE);
NODE delete_end(NODE);
NODE delete_front(NODE);
void Display(NODE);

int main()
{
    int ch;

    NODE head=NULL;

    while(1)
    {
        printf("\n Enter \n 1. To insert end  \n 2. To insert at front\n 3. To Display forward \n 4.To delete at end \n 5 To delete at front\n 6. To exit\n ");

    scanf("%d", &ch);
    switch(ch)
    {
        case 1: head=insert_end(head);
                 break;
        case 2: head=insert_front(head);
                break;
        case 3: Display(head);
                 break;
        case 4: head=delete_end(head);
                 break;
        case 5: head=delete_front(head);
                break;
        case 6: exit(0);
                break;
        default: printf("Invalid choice\n");


    }

  }
}

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
NODE insert_end(NODE head)
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

        return head;


    }

}

NODE insert_front(NODE head)
{
    NODE newNode;
    newNode=(NODE)malloc(sizeof(struct node));
    if(head==NULL)
    {
        head=newNode;
        return head;
    }
    else
    {
        NODE last=head->prev;
        newNode->next=head;
        head->prev=newNode;
        newNode->prev=last;
        last->next=newNode;

        return head;
    }
}

NODE delete_end(NODE head)
{
    if(head==NULL)
    {
        printf("List empty\n");
        return NULL;
    }
    if(head->next==head && head->prev==head)
    {
        printf("The element deleted is: %d", head->data);
        free(head);
        head=NULL;
        return head;
    }

    NODE last=head->prev;
    head->prev->next=head;

}


