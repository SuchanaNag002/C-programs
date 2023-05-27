#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node n;
int length(n *head)
{
    int len=0;
    n *x=head;
    while(x!=NULL)
    {
        len++;
        x=x->link;
    }
    return len;
}
void display(n *head)
{
    n *x=head;
    if(x==NULL)
        printf("\nEmpty Linked List\n");
    else
    {
        while(x!=NULL)
        {
            printf("%d ",x->info);
            x=x->link;
        }
    }
}
int main()
{
    int ans=1,k,len,i;
    n *head=NULL,*ptr,*current,*x,*y;
    while(ans)
    {
        ptr=(n*)malloc(sizeof(n));
        printf("\nEnter the info: ");
        scanf("%d",&ptr->info);
        ptr->link=NULL;
        if(head==NULL)
            head=current=ptr;
        else
        {
            current->link=ptr;
            current=ptr;
        }
        printf("\nDo you want to continue(1/0)? : ");
        scanf("%d",&ans);
    }
    printf("\nThe original linked list is: ");
    display(head);
    printf("\nEnter the value of k : ");
    scanf("%d",&k);
    len=length(head);
    if(k<0 || k>len)
    {
        printf("\nDeletion not possible");
        return 0;
    }
    else if(k==0)
    {
        printf("\nThe final linked list is: ");
        display(head);
        return 0;
    }
    else if(len==k)
    {
        x=head;
        head=head->link;
        free(x);
        printf("\nThe final linked list is: ");
        display(head);
        return 0;
    }
    x=head;
    for(i=1;i<=len-k;i++)
    {
        y=x;
        x=x->link;
    }
    y->link=x->link;
    free(x);
    printf("\nThe final linked list is: ");
    display(head);
}