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
n* SortedMerge(n* h1, n* h2)
{
    if (h1 == NULL)
	    return(h2);
    if (h2==NULL)
	    return(h1);
	n *x,*res=h1,*temp;
    if(h1->info>h2->info)
	{
		x=h1;
		h1=h2;
		h2=x;
	}
	while(h1!=NULL && h2!=NULL)
	{
		temp=NULL;
		while(h1!=NULL && h1->info<=h2->info)
		{
			temp=h1;
			h1=h1->link;
		}
		temp->link=h2;
		x=h1;
		h1=h2;
		h2=x;
	}
	return res;
}
int main()
{
    printf("Enter the first linked list:\n");
    n* h1=create();
    display(h1);
    printf("\nEnter the second linked list:\n");
    n* h2=create();
    display(h2);
    printf("\nLinked list in sorted order is:\n");
    n* first=SortedMerge(h1,h2);
    display(first);
}