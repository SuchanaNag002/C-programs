#include <stdio.h>
#include <stdlib.h>
int front = -1, rear = -1;
void display(int *arr,int maxsize)
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty!\n");
        return;
    }
    int i = front;
    while (i <= rear)
    {
        printf("%d ", arr[i]);
        i++;
    }
}
void push(int *arr, int maxsize)
{
    int item;
    if (front==(rear+1)%maxsize)
    {
        printf("\nOverflow\n");
        return;
    }
    else
    {
        printf("Enter the item to be inserted: ");
        scanf("%d", &item);
        if (front == -1 && rear == -1)
            front=rear=0;
        else
            rear=(rear+1)%maxsize;
        arr[rear] = item;
    }
}
void pop(int *arr,int maxsize)
{
    if (rear==-1 && front == -1)
    {
        printf("\nUnderflow!Deletion not possible\n");
        return;
    }
    int x = arr[front];
    if (front == rear)//only a single element in queue
        front = rear = -1;
    else
        front=(front+1)%maxsize;
    printf("%d has been deleted:\n", x);
}
void main()
{
    int i, ch, maxsize;
    printf("Enter the number of elements to be entered into the queue: ");
    scanf("%d", &maxsize);
    int *arr = (int *)malloc(maxsize * sizeof(int));
    while (1)
    {
        printf("\n*** MENU *** \n1. Display\n2. Insert\n3. Delete\n4. Exit");
        printf("\nenter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display(arr,maxsize);
            break;
        case 2:
            push(arr, maxsize);
            break;
        case 3:
            pop(arr,maxsize);
            break;
        case 4:
            exit(0);
        }
    }
}