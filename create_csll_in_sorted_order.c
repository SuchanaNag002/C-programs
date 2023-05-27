#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node n;
void sort(n *);
void display(n *);
void main()
{

    n *LAST = NULL, *ptr, *head, *x;
    int ans, ch;
    while (1)
    {
        ptr = (n *)malloc(sizeof(n));
        printf("\nEnter the info : ");
        scanf("%d", &ptr->info);
        ptr->link = ptr;
        if (LAST == NULL)
        {
            LAST = ptr;
            head = ptr;
        }
        else
        {
            LAST->link = ptr;
            LAST = ptr;
            LAST->link = head;
        }
        printf("\nwant to continue (1/0)? : ");
        scanf("%d", &ans);
        if (ans == 0)
            break;
    }
    sort(LAST);
}
void sort(n *last)
{
    int item;
    n *x = last->link;
    n *next;
    while (1)
    {
        next = x->link;

        while (next != last->link)
        {
            if (next->info < x->info)
            {
                item = next->info;
                next->info = x->info;
                x->info = item;
            }
            next = next->link;
        }
        x = x->link;
        if (x == last)
            break;
    }
    printf("\nSORTED CSLL :");
    display(last);
}
void display(n *last)
{
    struct node *x;
    if (last == NULL)
    {
        printf("\nempty list");
    }
    x = last->link;
    while (x != last)
    {
        printf("%d ", x->info);
        x = x->link;
    }
    printf(" %d", x->info);
    printf("\n");
}