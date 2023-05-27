#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
void search(n*head)
{
    if(head==NULL)
	{
		printf("\nempty list!");
		return;
	}	
    n *x=head;
    int data,f=0;
    printf("Enter the node to be searched: ");
    scanf("%d",&data);
    while(x!=NULL)
    {
        if(x->info==data)
        {
            f=1;
            break;
        }
        x=x->link;
    }
    if(f==1)
        printf("Element present\n");
    else
        printf("Element not present\n");
}
void min_max(n *head)
{
    n *x=head;
    if(head==NULL)
	{
		printf("\nempty list!");
		return;
	}
    int mini=INT_MAX;
    int maxi=INT_MIN;
    while(x!=NULL)
    {
        if(x->info>maxi)
            maxi=x->info;
        if(x->info<mini)
            mini=x->info;
        x=x->link;
    }
    printf("Maximum node is %d \n",maxi);
    printf("Minimum node is %d \n",mini);
}
n* delAtInd(n *head)
{
	n *x=head;
    int ind;
    printf("Enter the index from which it is to be deleted: ");
    scanf("%d",&ind);
    ind--;
	if(head==NULL)
		printf("Empty list! Deletion not possible\n");
	else
	{
		while(ind--)
            x=x->link;
        n *ptr=x->link;
        x->link=ptr->link;
        free(ptr);
	}
	return head;
}
n* insertbeg(n* head)
{
	n *ptr;
	ptr = (n*)malloc(sizeof(n));
	printf("\nenter the info : ");
	scanf("%d",&ptr->info);
	ptr->link=NULL;
	if(head==NULL)
		head=ptr;
	else
	{
		ptr->link=head;
		head=ptr;
	}
	return head;
}
n* insertend(n* head)
{
	n *ptr = (n*)malloc(sizeof(n));
	printf("\nEnter the info : ");
	scanf("%d",&ptr->info);
	ptr->link=NULL;
	if(head==NULL)
		head=ptr;
	else
	{
        n *x=head;
        while(x->link!=NULL)
            x=x->link;
        x->link=ptr;
        ptr->link=NULL;
	}
	return head;
}
n* delBeforeData(n *head)
{
	if(head==NULL)
		printf("\nDeletion not possible. empty list!");
	else
	{
       n *x=head;
       int data;
       printf("\nEnter the data whose previous node is to be deleted : ");
	   scanf("%d",&data);
       if(x->link->info==data)
        return x->link;
       while(x->link->link->info!=data)
            x=x->link;
       n *ptr=x->link;
       x->link=ptr->link;
       free(ptr);
	}
	return head;
}
n* delAfterData(n *head)
{
	if(head==NULL)
		printf("\nDeletion not possible. empty list!");
	else
	{
       n *x=head;
       int data;
       printf("\nEnter the data after whom node is to be deleted : ");
	   scanf("%d",&data);
       while(x->info!=data && x->link!=NULL)
            x=x->link;
       n *ptr=x->link;
       x->link=ptr->link;
       free(ptr);
	}
	return head;
}
n* deletebeg(n *head)
{
	n *x;
	if(head==NULL)
		printf("\nDeletion not possible. empty list!");
	else
	{
		x=head;
		head=head->link;
		free(x);
	}
	return head;
}
n* insBeforeData(n *head)
{
	n *x=head;
	n *ptr = (n*)malloc(sizeof(n));
    int data;
	printf("\nEnter the info : ");
	scanf("%d",&ptr->info);
    printf("Enter the data before which node is to be inserted: ");
    scanf("%d",&data);
	ptr->link=NULL;
	if(head==NULL)
		head=ptr;
	else if(head->info==data)
	{
		ptr->link=head;
		head=ptr;
	}
	else
	{
		while(x->link->info!=data)
            x=x->link;
        ptr->link=x->link;
        x->link=ptr;
	}
	return head;
}
n* insAfterData(n *head)
{
	n *x=head;
	n *ptr = (n*)malloc(sizeof(n));
    int data;
	printf("\nEnter the info : ");
	scanf("%d",&ptr->info);
    printf("Enter the data after which node is to be inserted: ");
    scanf("%d",&data);
	ptr->link=NULL;
	if(head==NULL)
		head=ptr;
	else
	{
		while(x->info!=data && x!=NULL)
            x=x->link;
        ptr->link=x->link;
        x->link=ptr;
	}
    return head;
}
n *deleteend(n *head)
{
	if(head==NULL)
	{
		printf("\nEmpty List");
		return head;
	}
	if(head->link==NULL)
		return NULL;
	n *x=head;
	while(x->link->link!=NULL)
		x=x->link;
	n *ptr=x->link;
	x->link=ptr->link;
	free(ptr);
	return head;
}
n* insAtInd(n *head)
{
	n *x=head;
	n *ptr = (n*)malloc(sizeof(n));
    int ind;
	printf("\nEnter the info : ");
	scanf("%d",&ptr->info);
    printf("Enter the index at which it is to be inserted: ");
    scanf("%d",&ind);
    ind--;
	ptr->link=NULL;
	if(head==NULL)
		head=ptr;
	else
	{
		while(ind--)
            x=x->link;
        ptr->link=x->link;
        x->link=ptr;
	}
	return head;
}
int main()
{
	n *head=NULL, *ptr, *current, *x;
	int ans, ch;
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
	while(1)
	{
		printf("\n*** MENU *** \n1. Display\n2. Insert at the begining\n3. Insert at the end\n4. Delete from the begining");
		printf("\n5. Insert at index\n6. delete from any index\n7. Insert before Data\n8. Delete before data\n9. Insert after data\n");
		printf("10.Delete after data\n11.Delete from end\n12. Search a node\n13. Find maximum and minimum\n14. Exit\nenter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: display(head);
				break;
			case 2: head=insertbeg(head);
				break;
            case 3: head=insertend(head);
				break;
			case 4: head=deletebeg(head);
				break;
			case 5: head=insAtInd(head);
                break;
            case 6: head=delAtInd(head);
                break;
            case 7:head=insBeforeData(head);
                break;
            case 8:head=delBeforeData(head);
                break;
            case 9:head=insAfterData(head);
                break;
            case 10:head=delAfterData(head);
                break;
			case 11:head=deleteend(head);
				break;
            case 12: search(head);
                break;
            case 13: min_max(head);
                break;
            case 14: exit(0);
                break;
		}
	}
}






