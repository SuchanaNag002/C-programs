#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};
typedef struct Node n;
n *create()
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
    return head;
}
n *rotate(n *head, int k)
{
    int len=1;
    if(!head || !head->link || k==0)
        return head;
    n *x=head;
    while(x->link && ++len)
        x=x->link;
    x->link=head;
    k=k%len;
    k=len-k;
    while(k--)
        x=x->link;
    head=x->link;
    x->link=NULL;
    return head;
}
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
    printf("\n");
}
int main()
{
    int k;
    n *head=create();
    printf("The linked list is: ");
    display(head);
    printf("Enter the rotation value: ");
    scanf("%d",&k);
    head=rotate(head,k);
    printf("The rotated linked list is: ");
    display(head);
}