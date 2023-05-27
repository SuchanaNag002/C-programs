#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *prev;
    struct node *next;
};
typedef struct node n;
void display(n *last)
{
	if(last==NULL)
	{
		printf("\nempty list!");
		return;
	}	
	n *x = last->next;
	while(x!=last)
	{
		printf("%d ",x->info);
		x=x->next;
	}
	printf("%d\n", x->info);
}
n* insertbeg(n* last)
{
	n *ptr;
	ptr = (n*)malloc(sizeof(n));
	printf("\nenter the info : ");
	scanf("%d",&ptr->info);
	ptr->next=ptr;
    ptr->prev = ptr;
	if(last==NULL)
		last=ptr;
	else
	{
        ptr->next = last->next;
        ptr->next->prev = ptr;
        last->next = ptr;
        ptr->prev= last;

	}
	return last;
}

n* deletebeg(n *last)
{
	n *y;
	if(last==NULL)
		printf("\nDeletion not possible. empty list!");
	else if (last->next == last) last = NULL;
	else
	{
		y = last->next;
		last->next= y->next;
        last->next->prev = last;
		free(y);
	}
	return last;
}
void search(n* last){
    printf("Enter target:");
    int target,flag = 0;
    scanf("%d", &target);
	if (last == NULL) printf("Empty List\n");
	else {
		if (last->info ==  target){
            printf("Element Present");
                return;
        }
        n* y = last->next;
        while (y != last){
            if (y->info == target) flag = 1;
            y = y->next;
        }
        if (flag) printf("Element Present");
        else printf("Element not Present");    
	}
}
n* deleteend(n* last){
    if(last==NULL)
		printf("\nDeletion not possible. empty list!");
    else if (last->next == last) {
        last = NULL;
    }
    else{
        n* y = last->prev;
        y->next = last->next;
        y->next->prev = y;
        free(last);
        last = y;
    }
    return last;
}

n* insertEnd(n* last){
        n* ptr;
		ptr = (n*)malloc(sizeof(n));
		printf("\nenter the info : ");
		scanf("%d",&ptr->info);
		ptr->next=ptr;
        ptr->prev=ptr;
		if(last==NULL)
		{
			last = ptr;
		}
		else
		{
			ptr->next = last->next;
			last->next = ptr;
            ptr->prev =  last;
			last=ptr;
            ptr->next->prev = ptr;
		}
        return last;
}
int main()
{
	n *last=NULL, *ptr, *x;
	int ans, ch;
	while(1)
	{
		ptr = (n*)malloc(sizeof(n));
		printf("\nenter the info : ");
		scanf("%d",&ptr->info);
		ptr->next=ptr;
        ptr->prev=ptr;
		if(last==NULL)
			last = ptr;
		else
		{
			ptr->next = last->next;
			last->next = ptr;
            ptr->prev =  last;
			last=ptr;
            ptr->next->prev = ptr;
		}
		printf("\nwant to continue (1/0)? : ");
		scanf("%d",&ans);
		if(ans==0)
			break;
	}
	while(1)
	{
printf("\n*** MENU *** \n1. Display\n2. Insert at the beginning\n3. Insert at the end\n4. Delete from the beginning");
		printf("\n5. Delete from the end\n6. Search a node\n7. Exit\nEnter your choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			display(last);
			break;
		case 2:
			last = insertbeg(last);
			break;
		case 3:
			last  = insertEnd(last);
			break;
		case 4:
			last  = deletebeg(last);
            break;
        case 5: last = deleteend(last);
                break;
		case 6:
			search(last );
			break;
		default:
			exit(0);
		}
	}
}

