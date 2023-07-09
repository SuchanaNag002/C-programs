#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node n;
n *front = NULL, *rear = NULL;
void display()
{
    if (front == NULL && rear == NULL)
    {
        printf("\nEmpty List");
        return;
    }
    n *x = front;
    while (x!= rear)
    {
        printf("%d ", x->info);
        x = x->link;
    }
    printf("%d",x->info);
}
void push()
{
    n *ptr = (n *)malloc(sizeof(n));
    printf("\nEnter the element to be pushed: ");
    scanf("%d", &ptr->info);
    ptr->link = NULL;
    if (front == NULL && rear == NULL)
        front = rear = ptr;
    else
    {
        rear->link = ptr;
        rear = ptr;
    }
    rear->link = front;
}
void pop()
{
    if (front == NULL && rear == NULL)
    {
        printf("\nUnderflow error!!Deletion not possible");
        return;
    }
    int x = front->info;
    if (front == rear)
        front = rear = NULL;
    else
    {
        front = front->link;
        rear->link = front;
    }
    printf("\nItem deleted is: %d", x);
}
int main()
{
    int ch;
    while (1)
    {
        printf("\n1. Display queue\n2. Push an element\n3. Pop an element\n4. Exit");
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
            exit(0);
            break;
        }
    }
}