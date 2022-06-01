#include<stdio.h>
#include<stdlib.h>

struct mango
{
    int ripe;
    struct mango *prev;
    struct mango *next;
};
typedef struct mango *NODE;

//function prototypes.
NODE getnewnode();
NODE insert_end_cdll(NODE head);
void display_cdll_firsttolast(NODE head);
void falling_mangoes(NODE head);

int main()
{
    int n, i;
    NODE head=NULL;
    //printf("Enter number of mangoes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        head = insert_end_cdll(head);
    falling_mangoes(head);
    return 0;
}

NODE getnewnode()
{
    NODE newn = (NODE) malloc (sizeof(struct mango));
    if(newn==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    //printf("Enter mango ripe level\n");
    scanf("%d",&newn->ripe);
    newn->prev=newn;
    newn->next=newn;
    return newn;
}

NODE insert_end_cdll(NODE head)
{
    NODE cur=NULL;
    NODE newn = getnewnode();
    if(head==NULL)
        head = newn;
    else
    {
        cur = head->prev;

        cur->next = newn;
        newn->prev = cur;

        newn->next = head;
        head->prev = newn;
    }
    return head;
}

void display_cdll_firsttolast(NODE head)
{
    NODE cur=head;
    if(head==NULL)
        printf("Circular DLL of mangoes is empty.\n");
    else
    {
        do
        {
            printf("%d ", cur->ripe);
            cur = cur->next;
        }while(cur != head);
    }
}

NODE delete_front_cdll(NODE head)
{
    NODE del=NULL, cur=NULL;
    if(head==NULL)
        printf("Circular DLL of grades is empty\n");
    else if(head->next == head)
    {
        //printf("\nMango falls %d\n", head->ripe);
        free(head);
        head=NULL;
    }
    else
    {
        cur = head->prev;
        del = head;
        head = head->next;

        head->prev = cur;
        cur->next = head;
        //printf("\nMango falls %d\n", del->ripe);
        free(del);
    }
    return head;
}

void falling_mangoes(NODE head)
{
    NODE tail=NULL;
    int count=0;
    if(head==NULL)
    {
        printf("Mangoes list is empty\n");
    }
    else
    {

        tail = head->prev;
        while(head != tail)
        {
            if(head ->ripe > head -> next->ripe)
            {
                head=delete_front_cdll(head);
                count++;
            }
            else
            {
                head = head->next;
            }
        }
        if(head->ripe > head->next->ripe)
        {
                head=delete_front_cdll(head);
                count++;
        }
        else
        {
            head = head->next;
        }
    }
    printf("Remaining mangoes\n");
    display_cdll_firsttolast(head);
    printf("\n");
    printf("Total Mangoes fall %d\n",count);
}
NODE getNode()
{
    NODE newNode;
    newNode=(NODE)malloc(sizeof(struct mango));
    if(newNode==NULL)
    {
        printf("Memory not created\n");
    }
    else
    {
        prinf("Enter the data \n");
        scanf("%d",&newNode->ripe);
        newNode->prev=head;
        newNode->next=head;

        return newNode;

    }
}

