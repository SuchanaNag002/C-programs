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
		printf("\nempty list!");
		return;
	}	
	x=head;
	while(x!=NULL)
	{
		printf("%d ",x->info);
		x=x->link;
	}
}
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
int main()
{
    printf("Enter the first linked list:\n");
    n* h1=create();
    display(h1);
    printf("\nEnter the second linked list:\n");
    n* h2=create();
    display(h2);
    n* h=h1;
    while(h->link!=NULL)
        h=h->link;
    h->link=h2;
    printf("\nMerged linked list:\n");
    display(h1);
}