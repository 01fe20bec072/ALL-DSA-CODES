#include<stdio.h>

#include<stdlib.h>

#include<string.h>

struct node

{

    char v_num[20];

    char type[5];

    int charge;

    struct node *next;

};

typedef struct node* NODE;



NODE insert_end(NODE);

void DisplayHMV(NODE);

NODE getNode();

NODE Delete_front(NODE);

void CountLMV(NODE);

void CountHMV(NODE);



void main()

{

    int n,i;

    NODE head=NULL;

    scanf("%d",&n);

    for(i=0;i<n;i++)

    {

        head=insert_end(head);

    }

    DisplayHMV(head);

    CountLMV(head);

    CountHMV(head);

}

NODE getNode()

{

    NODE NEWNODE;



    NEWNODE=malloc(sizeof(struct node));

    if(NEWNODE==NULL)

    {

        printf("Memory is not allocated\n");

    }

    scanf("%s",NEWNODE->v_num);

    scanf("%s",NEWNODE->type);

    if(strcmp(NEWNODE->type,"LMV")==0)

        NEWNODE->charge=50;

    else

    NEWNODE->charge=100;

    NEWNODE->next=NULL;

    return NEWNODE;

}





NODE Delete_front(NODE head)

{

    if(head==NULL)

    {

        printf("NO Vehicles \n");

        return head;

    }



    NODE cur=head;

    head=head->next;

    printf("\nToll charge has been paid by %s\n",cur->v_num);

    free(cur);

    return head;

}



NODE insert_end(NODE head)

{

    NODE Newnode=getNode();

    if(head==NULL)

    {

        head=Newnode;

        return head;

    }

    else

    {

        NODE temp=head;

        while(temp->next!=NULL)

        {

            temp=temp->next;

        }

        temp->next=Newnode;

        return head;

    }

}



void DisplayHMV(NODE head)

{

    int flag=0;

    if(head==NULL)

    {

        printf("Queue is empty\n");

        return;

    }

    NODE temp=head;

    while(temp!=NULL)

    {

        if(strcmp(temp->type,"HMV")==0)

        {

            flag=1;

            printf("%s\t%s\t%d\n",temp->v_num,temp->type,temp->charge);

        }

        temp=temp->next;

    }

    if(flag==0)

    {

        printf("NO HMV vehicles present in the queue\n");

    }

}



void CountLMV(NODE head)

{    int LMV_amt;

    int count=0;

    if(head==NULL)

    {

        printf("Queue is empty\n");

        return;

    }

    NODE temp=head;

    while(temp!=NULL)

    {

        if(strcmp(temp->type,"LMV")==0)

        {

            count++;

        }

        temp=temp->next;

    }



    if(count==0)

    {

        printf("NO LMV vehicles present in the queue\n");

    }

    else
    {


        printf("Total LMV vehicles present %d\n",count);

    }


    LMV_amt = count * 50;
    printf("The total LMV vechiles amount = %d\n", LMV_amt);

}


void CountHMV(NODE head)

{    int HMV_amt;

    int count=0;

    if(head==NULL)

    {

        printf("Queue is empty\n");

        return;

    }

    NODE temp=head;

    while(temp!=NULL)

    {

        if(strcmp(temp->type,"HMV")==0)

        {

            count++;

        }

        temp=temp->next;

    }



    if(count==0)

    {

        printf("NO HMV vehicles present in the queue\n");

    }

    else
    {


        printf("Total HMV vehicles present %d\n",count);

    }


    HMV_amt = count * 100;
    printf("The total HMV vechiles amount = %d\n", HMV_amt);

}
