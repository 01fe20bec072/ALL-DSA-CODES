/*KLE tech*/
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

struct candidate
{
    char name;
    int rank;
    int age;
    char add;
    struct candidate *next;
};

typedef struct candidate *NODE;

NODE getNode();
NODE insert_end(NODE head);
NODE delete_end(NODE head);
void Display(NODE head);

int main()
{
    int ch;
    NODE head=NULL;


    printf("\n Enter\n 1. T0 insert end \n 2. To delete_end\n 3. To Display\n 4. To insert front\n 5. To delete front\n 6. To exit\n ");

    scanf("%d",&ch);
    switch(ch)
    {
        case 1: head=insert_end(head);
                  break;
        case 2: head=delete_front(head);
                break;
        case 3: Display(head);
                 break;

        case 4: exit(0);
                break;
        default: printf("Invalid choice\n");
    }

}

NODE getNode()
{
    NODE newNode;
    newNode=malloc(sizeof(struct candidate));
    if(newNode==NULL)
    {
        printf("Memory not allocated\n");
        return;
    }

    printf("Enter Name, Rank, Age, Adderss\n");
    sacnf("%s\n%d\n%d\n%s\n", newNode->name, &newNode->rank, &newNode->age, newNode->add);


    newNode->next=NULL;
    return newNode;

}

NODE insert_end(NODE head)
{
    NODE newNode, cur;
    newNode=getnode();

    if(newNode==NULL)
    {
        newNode=head;
        return head;
    }

    cur=head;
    while(cur->next)
    {
        cur=cur->next;

    }

    cur->next=newNode;

    return newNode;


}

NODE delete_end(NODE head)
{
    if(head==NULL)
    {
        printf("List empty, cannot delete\n");
        return  head;

    }
    if(head->next==NULL)
    {
        printf("Deleted element %s", head->name);
        free(head);
        head=NULL;
        return head;
    }

     NODE prev=NULL;
    NODE cur=head;
    while(head->next)
    {
        prev=cur;
        cur=cur->next;

    }

    printf("Deleted element is=%d", cur->next);
    prev->next=NULL;
    free(cur);
    return head;

}

void Display(NODE head)
{
    if(head==NULL)
    {
        printf("List empty\n");
        return ;
    }

    printf("Name:\t Rank\t Age\t Addresss\n");

    NODE temp=head;
    while(temp==NULL)
    {
        printf("%s\t%d\t%d\t%s", temp->name, temp->rank, temp->age, temp->add);

        temp=temp->next;


    }
}
