#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
typedef struct node n;
int ifDataPresent(n *head, int data)
{
    n *x = head;
    while (x != NULL)
    {
        if (x->info == data)
            return 1;
        x = x->next;
    }
    return 0;
}
int length(n *head)
{
    int len = 0;
    n *x = head;
    while (x != NULL)
    {
        len++;
        x = x->next;
    }
    return len;
}
void display(n *head)
{
    n *x = head;
    if (x == NULL)
    {
        printf("\nEmpty List");
        return;
    }
    while (x != NULL)
    {
        printf("%d ", x->info);
        x = x->next;
    }
}
n *InsAtFront(n *head)
{
    n *ptr = (n *)malloc(sizeof(n));
    printf("\nEnter the data to be inserted: ");
    scanf("%d", &ptr->info);
    ptr->prev = ptr->next = NULL;
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
n *InsAtEnd(n *head)
{
    n *ptr = (n *)malloc(sizeof(n));
    printf("\nEnter the data to be inserted: ");
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
n *DelAtIndex(n *head)
{
    int ind, len;
    printf("\nEnter the index from which node is to be deleted: ");
    scanf("%d", &ind);
    len = length(head);
    if (ind < 0 || ind >= len)
        printf("\nInvalid index!Deletion not possible!");
    else if (ind == 0)
    {
        n *x = head;
        head = head->next;
        free(x);
        head->prev = NULL;
    }
    else
    {
        n *x = head;
        ind--;
        while (ind--)
            x = x->next;
        if (x->next->next == NULL)
        {
            n *ptr = x->next;
            x->next = NULL;
            free(ptr);
        }
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
n *InsBeforeData(n *head)
{
    int data;
    printf("\nEnter the node before which data is to be inserted: ");
    scanf("%d", &data);
    if (!ifDataPresent(head, data))
        printf("\nData not present. Try again later");
    else
    {
        n *ptr = (n *)malloc(sizeof(n));
        ptr->prev = ptr->next = NULL;
        printf("\nEnter the data to be inserted: ");
        scanf("%d", &ptr->info);
        n *x = head;
        if (x->info == data)
        {
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        else
        {
            while (x->info != data)
                x = x->next;
            ptr->next = x;
            ptr->prev = x->prev;
            x->prev->next=ptr;
            x->prev=ptr;
        }
    }
    return head;
}
n *DelAfterData(n *head)
{
    int data;
    printf("\nEnter the node after which data is to be deleted: ");
    scanf("%d", &data);
    if (!ifDataPresent(head, data))
        printf("\nData not present. Try again later");
    else
    {
        n *x = head;
        while (x->info != data)
            x = x->next;
        if (x->next == NULL)
            printf("\nDeletion not possible!End of list");
        else if(x->next->next==NULL)
        {
            n *ptr = x->next;
            x->next = NULL;
            free(ptr);
        }
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
void main()
{
    n *ptr, *head = NULL, *current;
    int ans = 1, ch;
    while (ans)
    {
        ptr = (n *)malloc(sizeof(n));
        printf("\nEnter the info: ");
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
        printf("\nWant to continue?(1/0): ");
        scanf("%d", &ans);
    }
    while (1)
    {
        printf("\n\n**MENU**\n1.Display\n2.Insert at front\n3.Insert at end\n4.Delete from any position\n5.Insert before a given data\n6.Delete after a given data\n7.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display(head);
            break;
        case 2:
            head = InsAtFront(head);
            break;
        case 3:
            head = InsAtEnd(head);
            break;
        case 4:
            head = DelAtIndex(head);
            break;
        case 5:
            head = InsBeforeData(head);
            break;
        case 6:
            head = DelAfterData(head);
            break;
        default:
            exit(0);
        }
    }
}