#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};
typedef struct node n;

void display(n *);

int main()
{
    n *last = NULL, *last2 = NULL, *ptr, *x;
    int ans, ch;
    printf("ENTER THE first LIST:\n");
    while (1)
    {
        ptr = (n *)malloc(sizeof(n));
        printf("\nenter the info : ");
        scanf("%d", &ptr->info);
        ptr->next = ptr;
        ptr->prev = ptr;
        if (last == NULL)
        {
            last = ptr;
        }
        else
        {
            ptr->next = last->next;
            last->next = ptr;
            ptr->prev = last;
            last = ptr;
            ptr->next->prev = ptr;
        }
        printf("\nwant to continue (1/0)? : ");
        scanf("%d", &ans);
        if (ans == 0)
            break;
    }
    printf("ENTER THE SECOND LIST:\n");
    while (1)
    {
        ptr = (n *)malloc(sizeof(n));
        printf("\nenter the info : ");
        scanf("%d", &ptr->info);
        ptr->next = ptr;
        ptr->prev = ptr;
        if (last2 == NULL)
        {
            last2 = ptr;
        }
        else
        {
            ptr->next = last2->next;
            last2->next = ptr;
            ptr->prev = last2;
            last2 = ptr;
            ptr->next->prev = ptr;
        }
        printf("\nwant to continue (1/0)? : ");
        scanf("%d", &ans);
        if (ans == 0)
            break;
    }
    printf("FIRST LIST:\n");
    display(last);
    printf("SECOND LIST:\n");
    display(last2);
    x = last->next;
    last->next = last2->next;
    last2->next->prev = last;
    last2->next = x;
    x->prev = last2;
    printf("CONCATINATED LIST:\n");
    display(last2);
}

void display(n *last)
{
    if (last == NULL)
    {
        printf("\nempty list!");
        return;
    }
    n *x = last->next;
    while (x != last)
    {
        printf("%d ", x->info);
        x = x->next;
    }
    printf("%d\n", x->info);
}