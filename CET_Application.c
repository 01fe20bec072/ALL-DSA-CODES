#include<stdio.h>
#include<stdlib.h>
struct candidate
{
	char name[25];
	int rank, age;
	char address[100];
	struct candidate *next;
};


/* A user-defined data type called “NODE” */
typedef struct candidate *NODE;

NODE insert_front( NODE );
NODE insert_end(NODE);
void display_list(NODE);
NODE delete_end(NODE);
NODE delete_front(NODE);
NODE getNode();
void main()
{
    int choice;
    NODE head=NULL;

    while(1)
    {
      printf("\nPress\n 1 for insert at end\n 2 for insert front\n 3 for display\n 4 for Delete end \n5 for Delete front\n6 for exit\n");
      scanf("%d",&choice);

        switch(choice)
        {
            case 1:head=insert_end(head);
                    break;
            case 2:head=insert_front(head);
                    break;
            case 3:display_list(head);
                    break;
            case 4:head=delete_end(head);
                    break;
            case 5:head=delete_front(head);
                    break;
            case 6:exit(0);
                    break;
            default:printf("Invalid choice\n");
        }
    }
}


NODE getnode()
{
	NODE newNode;
	newNode=malloc(sizeof(struct candidate));
	if(newNode==NULL)
	{
		printf("Not created\n");
		exit(0);
	}
  printf("Enter name rank age and address\n");
  scanf("%s%d%d%s",newNode->name,&newNode->rank,&newNode->age,newNode->address);
  newNode->next = NULL;
	return newNode;
}

NODE insert_end (NODE head)
{
	NODE newNode, cur;
	newNode = getnode();
    if(head==NULL)
    {
        head=newNode;
        return head;
    }
	cur = head;
	while (cur->next!= NULL)
	{
		cur = cur->next;
	}
	cur->next = newNode;
     	return head;
}
void display_list(NODE head)
{
	NODE cur;
	if(head==NULL)
	{
	   printf("Empty List\n");
	   return NULL;
	}
	printf("elements are\n");
	cur = head;
	printf("Name\tRank\tAge\tAddress\n");
	while (cur!=NULL)
	{
	   printf("%s\t%d\t%d\t%s\n",cur->name,cur->rank,cur->age,cur->address);
	   cur = cur->next;
	}
}

NODE insert_front( NODE head)
{
	NODE newNode;
	newNode = getnode();
	newNode -> next = NULL;
	if(head == NULL)
	{
	    head=newNode;
  		return head;
	}
	newNode ->next = head;
	head = newNode;
	return head;
}

NODE delete_end(NODE head)
{
NODE prev, cur;
    if(head==NULL)
    {
        printf("List Empty\n");
        return head;
    }
    if(head->next==NULL)
    {
        printf("Deleted: %s\n", head->name);
        free(head);
        head=NULL;
        return head;
    }
    prev =NULL;
    cur =head;
    while(cur ->next != NULL)
    {
        prev= cur;
        cur = cur ->next;
    }
    printf("Deleted: %s\n", cur->name);
    free(cur);
    prev->next=NULL;
    return head;
}



NODE delete_front(NODE head)
{
    NODE cur;
    if(head==NULL)
    {
        printf("List Empty\n");
        return head;
    }
    cur=head;
    head=head->next;
    printf("Deleted: %s\n", cur->name);
    free(cur);
    return head;
}
