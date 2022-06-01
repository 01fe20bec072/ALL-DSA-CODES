#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int STACK[MAX],TOP=-1;
/* display stack element*/
void display();

/* push (insert) item into stack*/
void PUSH(int );

/* pop (remove) item from stack*/
int POP();

void main()
{

    int ITEM=0,x;
    int choice=0;


    while(1)
    {

        printf("Enter Choice (1: display, 2: insert (PUSH), 3: remove(POP)), 4: Exit..:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                display();
            break;
            case 2:
                printf("Enter Item to be insert :");
                scanf("%d",&ITEM);
                PUSH(ITEM);
                break;
            case 3:x=POP();
                if(x!=-1)
                {
                    printf("Deleted element is %d\n",x);
                }
                break;
            case 4:
                exit(0);
            break;
            default :
                printf("\ninvalid choice");
                break;
        }

    }// end of while(1)

}

/*  function    : display(),
    to display stack elements.
*/
void display()
{
    int i=0;
    if(TOP==-1)
    {
        printf("Stack is Empty .\n");
    }

    for(i=TOP;i >=0;i--)
    {
        printf("\n%d",STACK[i]);
    }
    printf("\n\n");
}

/*  function    : PUSH(),
    to push an item into stack.
*/
void PUSH(int item)
{
    if(TOP==MAX-1)
    {
        printf("\nSTACK is FULL can't ADD ITEM\n");

    }
    else{
    TOP++;
    STACK[TOP]=item;
    }
}

/*  function    : POP(),
    to pop an item from stack.
*/
int POP()
{
    int deleted;
    if(TOP==-1)
    {
        printf("STACK is EMPTY.\n");
        return -1;
    }
    else
    {
        deleted=STACK[TOP];
        TOP--;
        return deleted;
    }
}
