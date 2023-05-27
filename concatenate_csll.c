#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node n;
void display(n *last)
{
    n *x = last->link;
    if (last == NULL)
    {
        printf("\nempty list!");
        return;
    }
    while (x != last)
    {
        printf("%d ", x->info);
        x = x->link;
    }
    printf("%d ", last->info);
}
n* create()
{
    n *last = NULL, *ptr, *x;
    int ans, ch;
    while (1)
    {
        ptr = (n *)malloc(sizeof(n));
        printf("\nEnter the info : ");
        scanf("%d", &ptr->info);
        ptr->link = ptr;
        if (last == NULL)
            last = ptr;
        else
        {
            ptr->link = last->link;
            last->link = ptr;
            last = ptr;
        }
        printf("\nWant to continue (1/0)? : ");
        scanf("%d", &ans);
        if (ans == 0)
            break;
    }
    return last;
}
int main()
{
    printf("Enter the first linked list:\n");
    n *last1 = create();
    printf("\nEnter the second linked list:\n");
    n *last2 = create();
    printf("\nThe first linked list:\n");
    display(last1);
    printf("\nThe second linked list:\n");
    display(last2);
    n *ptr=last1->link;
    last1->link=last2->link;
    last2->link=ptr;
    printf("\nThe final linked list is:\n");
    display(last2);
}