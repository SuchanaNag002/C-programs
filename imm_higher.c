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
    printf("Enter the linked list:\n");
    n* head=create();
    display(head);
    n *h=head;
    n *p=h->link;
    n *y=h;
    while(p!=NULL)
    {
        if(!((h->info)>p->info))
        {
 
            y->link=p;
            free(h);
            h=p;
            p=p->link;
            if(p==NULL)break;
        }
        else {y=h;}
        p=p->link;
        h=h->link;
    } 
    printf("\n");
    display(head);
}