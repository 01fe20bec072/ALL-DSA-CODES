#include <stdio.h>
#include<string.h>
#include <stdlib.h>

struct node

{

    char name[20];

    float per;

    char city[20];

    int rank;

    struct node *next;

}*head;



int main()

{

    int n;

    int ch;

    printf("\nEnter number of nodes:");

    scanf("%d",&n);

    List(n);

    do

    {

        printf("\n1-->insert end 2-->display 3-->search cet rank 4-->delete by rank 5-->insert before rank 6-->exit:  ");

        scanf("%d",&ch);

        switch(ch)

        {

                case 1:insert_end();

                       break;

                case 2:display();

                         break;

                case 3:search();

                         break;

                case 4:deleterank();

                         break;

                case 5:insertbefore();

                         break;

                case 6:break;

        }

    }while(ch!=6);

    return 0;

}

void List(int n)

{

    struct node *newnode,*temp;

    int i;

    struct node p;

    head=(struct node *)malloc(sizeof(struct node));

    if(head==NULL)

    {

        printf("\nUnable to allocate memory");

    }

    else

    {

        printf("\nEnter details in the order of name,percentage,city,rank:");

        printf("\nEnter details of student 1:");

        scanf("%s%f%s%d",p.name,&p.per,p.city,&p.rank);

        strcpy(head->name,p.name);

        head->per=p.per;

        strcpy(head->city,p.city);

        head->rank=p.rank;

        head->next=NULL;

        temp=head;

    }

    for(i=1;i<n;i++)

    {

        newnode=(struct node *)malloc(sizeof(struct node));

        if(newnode==NULL)

        {

            printf("\nMemory not allocated");

            break;

        }

        else

        {

            printf("\nEnter details of student %d:",i+1);

            scanf("%s%f%s%d",p.name,&p.per,p.city,&p.rank);

            strcpy(newnode->name,p.name);

            newnode->per=p.per;

            strcpy(newnode->city,p.city);

            newnode->rank=p.rank;

            newnode->next=NULL;

            temp->next=newnode;

            temp=temp->next;

        }

    }

}

void insert_end()

{

    struct node *newnode, *temp;

    struct node p;

    printf("\nEnter details of student:");

    scanf("%s%f%s%d",p.name,&p.per,p.city,&p.rank);

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)

    {

        printf("Unable to allocate memory.");

    }

    else

    {

        strcpy(newnode->name,p.name);

        newnode->per=p.per;

        strcpy(newnode->city,p.city);

        newnode->rank=p.rank;

        newnode->next = NULL;

        temp = head;

        while(temp != NULL && temp->next != NULL)

            temp = temp->next;

        temp->next = newnode;

    }

}

void display()

{

    struct node *temp;

    if(head == NULL)

    {

        printf("List is empty");

    }

    else

    {

        temp = head;
        while(temp != NULL)

        {

            printf("\nName:%s   Percentage:%f   City:%s   Rank:%d\n",temp->name,temp->per,temp->city,temp->rank);

            temp = temp->next;

        }

    }

}

void search()

{

    int key;

    struct node *temp=head;

    printf("\nEnter cet rank to search:");

    scanf("%d",&key);

    for(temp=head;temp!=NULL;temp=temp->next)

    {

        if(temp->rank==key)

        {

            printf("\nRank found");

            printf("\nName:%s   Percentage:%f   City:%s   Rank:%d\n",temp->name,temp->per,temp->city,temp->rank);

            break;

        }

    }

    if(temp==NULL)

    {

        printf("\nRank not found");

    }

}

void deleterank()

{

    int key;

    struct node *temp=head,*prev;

    printf("\nEnter cet rank to delete:");

    scanf("%d",&key);

    for(prev=NULL,temp=head;temp!=NULL;prev=temp,temp=temp->next)

    {

        if(temp->rank==key)

        {

            break;

        }

    }

    if(temp==NULL)

        printf("\nRank not found");

    else

    {

        prev->next=temp->next;

        free(temp);

    }

}

void insertbefore()

{

    int key;

    struct node *p1,*p2,*nw;

    printf("\nEnter rank before which you want to enter the data:");

    scanf("%d",&key);

    for(p1=NULL,p2=head;p2!=NULL && key!=p2->rank;p1=p2,p2=p2->next);

    if(p2==NULL)

    {

        printf("\nRank not found");

        return;

    }

    nw=(struct node *)malloc(sizeof(struct node));

    printf("\nEnter details in the order of name,percentage,city,rank:");

    scanf("%s%f%s%d",nw->name,&nw->per,nw->city,&nw->rank);

    if(p1==NULL)

        head=nw;

    else

        p1->next=nw;

    nw->next=p2;

}
