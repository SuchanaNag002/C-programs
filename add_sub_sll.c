#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info,expo;
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
		printf("%dexpo(%d) ",x->info,x->expo);
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
		printf("\nenter the coefficient : ");
		scanf("%d",&ptr->info);
        printf("\nenter the exponent : ");
		scanf("%d",&ptr->expo);
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
n* add(n* h1,n* h2)
{
    n* head=NULL,*ptr,*current;
    while(h1!=NULL && h2!=NULL)
    {
        ptr = (n*)malloc(sizeof(n));
        ptr->link=NULL;
        if(h1->expo==h2->expo)
        {
            ptr->info=h1->info+h2->info;
            ptr->expo=h1->expo;
            if(head==NULL)
            {
                head=ptr;
                current=ptr;
            }
            else
            {
                current->link=ptr;
                current=ptr;
            }
            h1=h1->link;
            h2=h2->link;
        }
        else if(h1->expo>h2->expo)
        {
            ptr->info=h1->info;
            ptr->expo=h1->expo;
            if(head==NULL)
            {
                head=ptr;
                current=ptr;
            }
            else
            {
                current->link=ptr;
                current=ptr;
            }
            h1=h1->link;
        }
        else
        {
            ptr->info=h2->info;
            ptr->expo=h2->expo;
            if(head==NULL)
            {
                head=ptr;
                current=ptr;
            }
            else
            {
                current->link=ptr;
                current=ptr;
            }
            h2=h2->link;
        }
    }
    return head;
}
n* sub(n* h1,n* h2)
{
    n* head=NULL,*ptr,*current;
    while(h1!=NULL && h2!=NULL)
    {
        ptr = (n*)malloc(sizeof(n));
        ptr->link=NULL;
        if(h1->expo==h2->expo)
        {
            ptr->info=h1->info-h2->info;
            ptr->expo=h1->expo;
            if(head==NULL)
            {
                head=ptr;
                current=ptr;
            }
            else
            {
                current->link=ptr;
                current=ptr;
            }
            h1=h1->link;
            h2=h2->link;
        }
        else if(h1->expo>h2->expo)
        {
            ptr->info=h1->info;
            ptr->expo=h1->expo;
            if(head==NULL)
            {
                head=ptr;
                current=ptr;
            }
            else
            {
                current->link=ptr;
                current=ptr;
            }
            h1=h1->link;
        }
        else
        {
            ptr->info=-(h2->info);
            ptr->expo=h2->expo;
            if(head==NULL)
            {
                head=ptr;
                current=ptr;
            }
            else
            {
                current->link=ptr;
                current=ptr;
            }
            h2=h2->link;
        }
    }
    return head;
}
int main()
{
    printf("Enter the first linked list:\n");
    n* head1=create();
    printf("\nEnter the second linked list:\n");
    n* head2=create();
    printf("\nThe first linked list is:\n");
    display(head1);
    printf("\nThe second linked list is:\n");
    display(head2);
    n* head3=add(head1,head2);
    n* head4=sub(head1,head2);
    printf("\n\nThe added linked list is:\n");
    display(head3);
    printf("\n\nThe subtracted linked list is:\n");
    display(head4);
}