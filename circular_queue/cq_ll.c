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
    if (front==NULL && rear == NULL)
    {
        printf("\nQueue is empty!\n");
        return;
    }
    n *x = front;
    while (x->link!= front)
    {
        printf("%d ", x->info);
        x = x->link;
    }
    printf("%d",x->info);
}
void push()
{
    n *ptr, *x;
    ptr = (n *)malloc(sizeof(n));
    printf("\nEnter the info : ");
    scanf("%d", &ptr->info);
    ptr->link = NULL;
    if (front== NULL && rear == NULL)//if queue is empty 
    {
        front = rear = ptr;
        rear->link=front;
    }
    else
    {
        rear->link = ptr;
        rear = ptr;
        rear->link=front;
    }
}
void pop()
{
    if (rear==NULL && front == NULL)
    {
        printf("\nUnderflow! Deletion not possible\n");
        return;
    }
    int x = front->info;
    if (front == rear)
        front = rear = NULL;
    else
    {
        front = front->link;
        rear->link=front;
    }
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
            push();
            break;
        case 3:
            pop();
            break;
        case 4:
            exit(0);
        }
    }
}