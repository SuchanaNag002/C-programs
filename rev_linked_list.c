#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
typedef struct node n;
void display(n *head)
{
	n *x;
	if(head==NULL)
	{
		printf("\nEmpty list!");
		return;
	}	
	x=head;
	while(x!=NULL)
	{
		printf("%d ",x->info);
		x=x->link;
	}
}
int main()
{
    n *head=NULL, *ptr, *current;
	int ans;
	while(1)
	{
		ptr = (n*)malloc(sizeof(n));
		printf("\nenter the info : ");
		scanf("%d",&ptr->info);
		ptr->link=NULL;
		if(head==NULL)
		{
			head = ptr;
			current = ptr;
		}
		else
		{
			current->link = ptr;
			current=ptr;
		}
		printf("\nwant to continue (1/0)? : ");
		scanf("%d",&ans);
		if(ans==0)
			break;
	}
    printf("The linked list is:\n");
    display(head);
    n* dummy=NULL;
    while(head!=NULL)
    {
        n* next=head->link;
        head->link=dummy;
        dummy=head;
        head=next;
    }
    printf("\nThe reverse linked list is:\n");
    display(dummy);
}