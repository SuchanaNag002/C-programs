#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node n;
n *top = NULL;
void display(n *top)
{
    n *x;
    if (top == NULL)
    {
        printf("\nempty stack!");
        return;
    }
    x = top;
    while (x != NULL)
    {
        printf("%d ", x->info);
        x = x->link;
    }
}
n *push(n *top)
{
    n *ptr;
    ptr = (n *)malloc(sizeof(n));
    printf("\nenter the info : ");
    scanf("%d", &ptr->info);
    ptr->link=NULL;
    if(top==NULL)
        top=ptr;
    else
    {
        ptr->link=top;
        top=ptr;
    }
    return top;
}
void peek(n *top)
{
    if (top == NULL)
        printf("\nEmpty stack!");
    else
        printf("The top element is %d\n", top->info);
}
n *pop(n *top)
{
    n *x;
    if (top == NULL)
        printf("\nUnderflow error.Empty stack!!!\n");
    else
    {
        x = top->link;
        free(top);
        top = x;
    }
    return top;
}
int main()
{
    int ch;
    while (1)
    {
        printf("\n*** MENU *** \n1. Display\n2. Push\n3. Peek\n4. Pop");
        printf("\n5. Exit\n");
        printf("\nenter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display(top);
            break;
        case 2:
            top = push(top);
            break;
        case 3:
            peek(top);
            break;
        case 4:
            top = pop(top);
            break;
        case 5:
            exit(0);
        }
    }
}