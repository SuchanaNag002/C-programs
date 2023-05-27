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
	n *first=head;
	n *h1=NULL,*h2=NULL;
    while(first!=NULL)
    {
        if(((first->info)%2)==0)
        {
			n* even=(n*)malloc(sizeof(n));
            even->info=first->info;
            even->link=NULL;
			if(h1==NULL)
				h1=even;
			else
			{
				even->link=h1;
				h1=even;
			}
        }
		else
		{
			n* odd=(n*)malloc(sizeof(n));
			odd->info=first->info;
            odd->link=NULL;
			if(h2==NULL)
				h2=odd;
			else
			{
				odd->link=h2;
				h2=odd;
			}
		}
		first=first->link;
    }
	printf("Even linked list\n");
	display(h1);
	printf("\nOdd linked list\n");
	display(h2);
}