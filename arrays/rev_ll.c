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
    if(head==NULL)
    {
        printf("\nEmpty linked list");
        return;
    }
    n *x=head;
    while(x!=NULL)
    {
        printf("%d ",x->info);
        x=x->link;
    }
}
int main()
{
    n *head=NULL,*curr,*ptr;
    int ans=1;
    while(ans)
    {
        ptr=(n*)malloc(sizeof(n));
        printf("\nEnter the info: ");
        scanf("%d",&ptr->info);
        ptr->link=NULL;
        if(!head)
        {
            head=ptr;
            curr=ptr;
        }
        else
        {
            curr->link=ptr;
            curr=ptr;
        }
        printf("\nDo you want to add another node?(1/0): ");
        scanf("%d",&ans);
    }
    printf("\nThe linked list is: ");
    display(head);
    n *dummy=NULL, *next;
    while(head!=NULL)
    {
        next=head->link;
        head->link=dummy;
        dummy=head;
        head=next;
    } 
    printf("\nThe reverse linked list is: ");
    display(dummy);
}