#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *prev, *next;
};
typedef struct node n;
void display(n *head)
{
	n *x;
	if (head == NULL)
	{
		printf("\nempty list!");
		return;
	}
	x = head;
	while (x != NULL)
	{
		printf("%d ", x->info);
		x = x->next;
	}
}
void search(n *head)
{
	if (head == NULL)
	{
		printf("\nEmpty list!");
		return;
	}
	n *x = head;
	int data, f = 0;
	printf("Enter the node to be searched: ");
	scanf("%d", &data);
	while (x != NULL)
	{
		if (x->info == data)
		{
			f = 1;
			break;
		}
		x = x->next;
	}
	if (f == 1)
		printf("Element present\n");
	else
		printf("Element not present\n");
}
n *insertbeg(n *head)
{
	n *ptr = (n *)malloc(sizeof(n));
	printf("\nEnter the info : ");
	scanf("%d", &ptr->info);
	ptr->next = ptr->prev = NULL;
	if (head == NULL)
		head = ptr;
	else
	{
		ptr->next = head;
		head->prev = ptr;
		head = ptr;
	}
	return head;
}
n *insertend(n *head)
{
	n *ptr = (n *)malloc(sizeof(n));
	printf("\nEnter the info : ");
	scanf("%d", &ptr->info);
	ptr->prev = ptr->next = NULL;
	if (head == NULL)
		head = ptr;
	else
	{
		n *x = head;
		while (x->next != NULL)
			x = x->next;
		x->next = ptr;
		ptr->prev = x;
	}
	return head;
}
n *deletebeg(n *head)
{
	n *x;
	if (head == NULL)
		printf("\nDeletion not possible. Empty list!");
	else if (head->next == NULL)
		return NULL;
	else
	{
		x = head;
		head = head->next;
		head->prev = NULL;
		free(x);
	}
	return head;
}
n *deletend(n *head)
{
	n *x;
	if (head == NULL)
		printf("\nDeletion not possible. Empty list!");
	else if (head->next == NULL)
		return NULL;
	else
	{
		x = head;
		while (x->next != NULL)
			x = x->next;
		x->prev->next = NULL;
		free(x);
	}
	return head;
}
n *insAtInd(n *head)
{
	n *x = head;
	n *ptr = (n *)malloc(sizeof(n));
	int ind;
	printf("Enter the index at which it is to be inserted: ");
	scanf("%d", &ind);
	ptr->next = ptr->prev = NULL;
	if (head == NULL)
	{
		printf("\nEnter the info : ");
		scanf("%d", &ptr->info);
		head = ptr;
	}
	else if (ind == 0)
		head = insertbeg(x);
	else
	{
		ind--;
		while (ind--)
			x = x->next;
		if (x->next == NULL)
			head = insertend(head);
		else
		{
			printf("\nEnter the info : ");
			scanf("%d", &ptr->info);
			ptr->next = x->next;
			x->next = ptr;
			ptr->next->prev = ptr;
			ptr->prev = x;
		}
	}
	return head;
}
n *delAtInd(n *head)
{
	n *x = head;
	int ind;
	printf("Enter the index from which it is to be deleted: ");
	scanf("%d", &ind);
	if (head == NULL)
		printf("Empty list! Deletion not possible\n");
	if (ind == 0)
		head = deletebeg(head);
	else
	{
		ind--;
		while (ind--)
			x = x->next;
		if (x->next == NULL)
			return NULL;
		else if (x->next->next == NULL)
			head = deletend(head);
		else
		{
			n *ptr = x->next;
			x->next = ptr->next;
			ptr->next->prev = x;
			free(ptr);
		}
	}
	return head;
}
n *insAfterData(n *head)
{
	n *x = head;
	n *ptr = (n *)malloc(sizeof(n));
	int data;
	printf("\nEnter the info : ");
	scanf("%d", &ptr->info);
	printf("Enter the data after which node is to be inserted: ");
	scanf("%d", &data);
	ptr->next = ptr->prev = NULL;
	if (head == NULL)
		head = ptr;
	else
	{
		while (x->info != data && x != NULL)
			x = x->next;
		if (x->next == NULL)
		{
			x->next = ptr;
			ptr->prev = x;
		}
		else
		{
			ptr->next = x->next;
			ptr->next->prev = ptr;
			x->next = ptr;
			ptr->prev = x;
		}
	}
	return head;
}
n *insBeforeData(n *head)
{
	n *x = head;
	n *ptr = (n *)malloc(sizeof(n));
	int data;
	printf("\nEnter the info : ");
	scanf("%d", &ptr->info);
	printf("Enter the data before which node is to be inserted: ");
	scanf("%d", &data);
	ptr->next = ptr->prev = NULL;
	if (head == NULL)
		head = ptr;
	else if (head->info == data)
	{
		ptr->next = head;
		head->prev = ptr;
		head = ptr;
	}
	else
	{
		while (x->next->info != data)
			x = x->next;
		ptr->next = x->next;
		x->next->prev = ptr;
		x->next = ptr;
		ptr->prev = x;
	}
	return head;
}
n *delBeforeData(n *head)
{
	if (head == NULL)
		printf("\nDeletion not possible. empty list!");
	else
	{
		n *x = head;
		int data;
		printf("\nEnter the data whose previous node is to be deleted : ");
		scanf("%d", &data);
		while (x->next->info != data)
			x = x->next;
		if (x == head)
			head = deletebeg(head);
		else
		{
			x->prev->next = x->next;
			x->next->prev = x->prev;
			free(x);
		}
	}
	return head;
}
n *delAfterData(n *head)
{
	if (head == NULL)
		printf("\nDeletion not possible. empty list!");
	else
	{
		n *x = head;
		int data;
		printf("\nEnter the data after whom node is to be deleted : ");
		scanf("%d", &data);
		while (x->info != data && x->next != NULL)
			x = x->next;
		if (x->next->next == NULL)
			head = deletend(head);
		else
		{
			n *ptr = x->next;
			x->next = ptr->next;
			ptr->next->prev = x;
			free(ptr);
		}
	}
	return head;
}
int main()
{
	n *head = NULL, *ptr, *current, *x;
	int ans, ch;
	while (1)
	{
		ptr = (n *)malloc(sizeof(n));
		printf("\nEnter the info : ");
		scanf("%d", &ptr->info);
		ptr->next = ptr->prev = NULL;
		if (head == NULL)
		{
			head = ptr;
			current = ptr;
		}
		else
		{
			current->next = ptr;
			ptr->prev = current;
			current = ptr;
		}
		printf("\nWant to continue (1/0)? : ");
		scanf("%d", &ans);
		if (ans == 0)
			break;
	}
	while (1)
	{
		printf("\n*** MENU *** \n1. Display\n2. Insert at the beginning\n3. Insert at the end\n4. Delete from the beginning");
		printf("\n5. Delete from the end\n6. Insert at index\n7. Delete from any index\n8. Insert before Data\n9. Delete before Data\n10. Insert after data\n");
		printf("11. Delete after data\n12. Search a node\n13. Exit\nEnter your choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			display(head);
			break;
		case 2:
			head = insertbeg(head);
			break;
		case 3:
			head = insertend(head);
			break;
		case 4:
			head = deletebeg(head);
			break;
		case 5:
			head = deletend(head);
			break;
		case 6:
			head = insAtInd(head);
			break;
		case 7:
			head = delAtInd(head);
			break;
		case 8:
			head = insBeforeData(head);
			break;
		case 9:
			head = delBeforeData(head);
			break;
		case 10:
			head = insAfterData(head);
			break;
		case 11:
			head = delAfterData(head);
			break;
		case 12:
			search(head);
			break;
		default:
			exit(0);
		}
	}
}