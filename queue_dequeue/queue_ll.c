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
    if (front == rear && front == NULL)
    {
        printf("\nQueue is empty!\n");
        return;
    }
    n *x = front;
    while (x != NULL)
    {
        printf("%d ", x->info);
        x = x->link;
    }
}
void insert()
{
    n *ptr, *x;
    ptr = (n *)malloc(sizeof(n));
    printf("\nEnter the info : ");
    scanf("%d", &ptr->info);
    ptr->link = NULL;
    if (front == rear && front == NULL)
        front = rear = ptr;
    else
    {
        rear->link = ptr;
        rear = ptr;
    }
}
void delete ()
{
    if (front == NULL && rear==NULL)
    {
        printf("\nUnderflow! Deletion not possible\n");
        return;
    }
    int x = front->info;
    if (front == rear)
        front = rear = NULL;
    else
        front = front->link;
    printf("Deleted element is: %d\n", x);
}
int main()
{
    int ch;
    while (1)
    {
        printf("\n*** MENU *** \n1. Display\n2. Insert\n3. Delete\n4. Exit");
        printf("\nenter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display();
            break;
        case 2:
            insert();
            break;
        case 3:
            delete ();
            break;
        case 4:
            exit(0);
        }
    }
}