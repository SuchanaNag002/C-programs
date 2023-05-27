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
void insertFront()
{
    n *ptr, *x;
    ptr = (n *)malloc(sizeof(n));
    printf("\nEnter the info : ");
    scanf("%d", &ptr->info);
    ptr->link = NULL;
    if (front == NULL && rear == NULL)
        front = rear = ptr;
    else
    {
        ptr->link = front;
        front = ptr;
    }
}
void deleteRear()
{
    if (front == NULL && rear == NULL)
    {
        printf("\nUnderflow! Deletion not possible\n");
        return;
    }
    n *x = front;
    if (front == rear)
    {
        front = rear = NULL;
        printf("%d has been deleted", x->info);
        free(x);
        return;
    }
    while (x->link != rear)
        x = x->link;
    free(rear);
    rear = x;
    x->link = NULL;
}
void insertRear()
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
void deleteFront()
{
    if (front == rear && front == NULL)
    {
        printf("\nUnderflow! Deletion not possible\n");
        return;
    }
    n *x=front;
    if (front == rear)
        front = rear = NULL;
    else
        front=front->link;
    printf("Deleted element is: %d\n", x->info);
    free(x);
}
int main()
{
    int ch;
    while (1)
    {
        printf("\n*** MENU *** \n1. Display\n2. InsertFront\n3. DeleteRear\n4. InsertRear\n5. DeleteFront\n6. Exit");
        printf("\nenter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display();
            break;
        case 2:
            insertFront();
            break;
        case 3:
            deleteRear();
            break;
        case 4:
            insertRear();
            break;
        case 5:
            deleteFront();
            break;
        case 6:
            exit(0);
        }
    }
}