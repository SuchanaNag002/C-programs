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
    if (last == NULL)
    {
        printf("\nempty list!");
        return;
    }
    n *x = last->link;
    while (x != last)
    {
        printf("%d ", x->info);
        x = x->link;
    }
    printf("%d ", last->info);
}
void search(n *last)
{
    if (last == NULL)
    {
        printf("\nEmpty list!");
        return;
    }
    int data, f = 0;
    printf("Enter the node to be searched: ");
    scanf("%d", &data);
    if (last->info == data)
        f = 1;
    else
    {
        n *x = last->link;
        while (x != last)
        {
            if (x->info == data)
            {
                f = 1;
                break;
            }
            x = x->link;
        }
    }
    if (f == 1)
        printf("Element present\n");
    else
        printf("Element not present\n");
}
n *insertbeg(n *last)
{
    n *ptr = (n *)malloc(sizeof(n));
    printf("\nEnter the info : ");
    scanf("%d", &ptr->info);
    ptr->link = NULL;
    if (last == NULL)
    {
        ptr->link = ptr;
        last = ptr;
    }
    else
    {
        ptr->link = last->link;
        last->link = ptr;
    }
    return last;
}
n *insertend(n *last)
{
    n *ptr = (n *)malloc(sizeof(n));
    printf("\nEnter the info : ");
    scanf("%d", &ptr->info);
    ptr->link = NULL;
    if (last == NULL)
    {
        ptr->link = ptr;
        last = ptr;
    }
    else
    {
        ptr->link = last->link;
        last->link = ptr;//last is always the newly entered element
        last = ptr;
    }
    return last;
}
n *deletebeg(n *last)
{
    n *x;
    if (last == NULL)
        printf("\nDeletion not possible. Empty list!");
    else if (last->link == last)
        last = NULL;
    else
    {
        x = last->link;
        last->link = x->link;
        free(x);
    }
    return last;
}
n *deletend(n *last)
{
    n *x = last->link;
    if (last == NULL)
        printf("\nDeletion not possible. Empty list!");
    else if (last->link == last)
        last = NULL;
    else
    {
        while (x->link != last)
            x = x->link;
        x->link = last->link;
        free(last);
        last = x;
    }
    return last;
}
n *insAtInd(n *last)
{
    n *x = last->link;
    n *ptr = (n *)malloc(sizeof(n));
    int ind;
    printf("Enter the index at which it is to be inserted: ");
    scanf("%d", &ind);
    ptr->link = NULL;
    if (last == NULL)
    {
        printf("\nEnter the info : ");
        scanf("%d", &ptr->info);
        last = ptr;
        last->link = last;
    }
    else if (ind == 0)
        last = insertbeg(last);
    else
    {
        ind--;
        while (ind--)
            x = x->link;
        if (x == last)
            last = insertend(last);
        else
        {
            printf("\nEnter the info : ");
            scanf("%d", &ptr->info);
            ptr->link = x->link;
            x->link = ptr;
        }
    }
    return last;
}
n *delAtInd(n *last)
{
    n *x = last->link;
    int ind;
    printf("Enter the index from which it is to be deleted: ");
    scanf("%d", &ind);
    if (last == NULL)
        printf("Empty list! Deletion not possible\n");
    if (ind == 0)
        last = deletebeg(last);
    else
    {
        ind--;
        while (ind--)
            x = x->link;
        if (x->link == last) // deletes last node
        {
            x->link = last->link;
            free(last);
            last = x;
        }
        else
        {
            n *ptr = x->link;
            x->link = ptr->link;
            free(ptr);
        }
    }
    return last;
}
n *insAfterData(n *last)
{
    n *x = last->link;
    n *ptr = (n *)malloc(sizeof(n));
    int data;
    printf("Enter the data after which node is to be inserted: ");
    scanf("%d", &data);
    ptr->link = NULL;
    while (x->info != data && x != last)
        x = x->link;
    if (last == NULL)
    {
        last = ptr;
        last->link = last;
    }
    else if (x == last)
        last = insertend(last);
    else
    {
        printf("\nEnter the info : ");
        scanf("%d", &ptr->info);
        ptr->link = x->link;
        x->link = ptr;
    }
    return last;
}
n *insBeforeData(n *last)
{
    n *ptr = (n *)malloc(sizeof(n));
    int data;
    printf("\nEnter the info : ");
    scanf("%d", &ptr->info);
    printf("Enter the data before which node is to be inserted: ");
    scanf("%d", &data);
    ptr->link = NULL;
    if (last == NULL)
    {
        last = ptr;
        last->link = last;
    }
    else
    {
        n *x = last->link;
        while (x->link->info != data)
            x = x->link;
        ptr->link = x->link;
        x->link = ptr;
    }
    return last;
}
n *delBeforeData(n *last)
{
    if (last == NULL)
        printf("\nDeletion not possible. empty list!");
    else
    {
        n *x = last->link;
        int data;
        printf("\nEnter the data whose previous node is to be deleted : ");
        scanf("%d", &data);
        while (x->link->link->info != data)
            x = x->link;
        if (last->link->info == data)
            last = deletend(last);
        else if (last->link->link->info == data)
            last = deletebeg(last);
        else
        {
            n *ptr = x->link;
            x->link = ptr->link;
            free(ptr);
        }
    }
    return last;
}
n *delAfterData(n *last)
{
    if (last == NULL)
        printf("\nDeletion not possible. empty list!");
    else
    {
        n *x = last->link;
        int data;
        printf("\nEnter the data after whom node is to be deleted : ");
        scanf("%d", &data);
        while (x->info != data && x->link != last)
            x = x->link;
        if (last->info == data)
            last = deletebeg(last);
        else if (x->link->info == last->info)
            last = deletend(last);
        else
        {
            n *ptr = x->link;
            x->link = ptr->link;
            free(ptr);
        }
    }
    return last;
}
int main()
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
    while (1)
    {
        printf("\n*** MENU *** \n1. Display\n2. Insert at the beginning\n3. Insert at the end\n4. Delete from the beginning");
        printf("\n5. Delete from the end\n6. Insert at index\n7. Delete from any index\n8. Insert before Data\n9. Delete before Data\n10. Insert after data\n");
        printf("11. Delete after data\n12. Search a node\n13. Exit\nEnter your choice: ");
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
            last = insertend(last);
            break;
        case 4:
            last = deletebeg(last);
            break;
        case 5:
            last = deletend(last);
            break;
        case 6:
            last = insAtInd(last);
            break;
        case 7:
            last = delAtInd(last);
            break;
        case 8:
            last = insBeforeData(last);
            break;
        case 9:
            last = delBeforeData(last);
            break;
        case 10:
            last = insAfterData(last);
            break;
        case 11:
            last = delAfterData(last);
            break;
        case 12:
            search(last);
            break;
        default:
            exit(0);
        }
    }
}