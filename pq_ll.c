#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info, priority;
    struct node *link;
};
typedef struct node n;
n *head=NULL;
void display()
{
    if(head==NULL)
    {
        printf("\nEmpty linked list");
        return;
    }
    n *x=head;
    while(x)
    {
        printf("\nElement: %d, Priority: %d",x->info,x->priority);
        x=x->link;
    }
}
void push()
{
    n *ptr=(n*)malloc(sizeof(n));
    printf("\nEnter the element: ");
    scanf("%d",&ptr->info);
    printf("Enter its priority: ");
    scanf("%d",&ptr->priority);
    ptr->link=NULL;
    if(head==NULL)
        head=ptr;
    else if(ptr->priority>head->priority)
    {
        ptr->link=head;
        head=ptr;
    }
    else
    {
        n *x=head,*y;
        while(x!=NULL && ptr->priority<=x->priority)
        {
            y=x;
            x=x->link;
        }
        y->link=ptr;
        ptr->link=x;
    }
}
void pop()
{
    if(head==NULL)
    {
        printf("\nDeletion not possible");
        return;
    }
    printf("\nElement: %d with Priority: %d was popped",head->info,head->priority);
    head=head->link;
}
void peek()
{
    if(head==NULL)
    {
        printf("\nEmpty List");
        return;
    }
    printf("\nPeek Element: %d with Priority: %d",head->info,head->priority);
}
int main()
{
    n *head1=NULL, *head2=NULL;
    while (1)
    {
        int ch;
        printf("\n*** MENU *** \n1. Display\n2. Push\n3. Pop\n4. Peek");
        printf("\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display();
            break;
        case 2:
            push();
            break;
        case 3:
            pop();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
        }
    }
}