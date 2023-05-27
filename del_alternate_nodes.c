#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
typedef struct node n;
n* create()
{
    n *head=NULL, *ptr, *current, *x;
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
    return head;
}
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
    printf("Enter the linked list:\n");
    n* h1=create();
    display(h1);
    if (h1 == NULL)
        return 0;
    n *prev = h1;
    n *node = h1->link;
    while (prev != NULL && node != NULL)
    {
        prev->link = node->link;
        free(node);
        prev = prev->link;
        if (prev != NULL)
            node = prev->link;
    }
    printf("\nLinked list after alternate node deletion is:\n");
    display(h1);
}