#include <stdio.h>
#include <stdlib.h>
int front = -1, rear = -1;
void display(int *arr)
{
    if (front == rear && front == -1)
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
void insert(int *arr, int maxsize)
{
    int item;
    if (rear == (maxsize - 1))
    {
        printf("\nOverflow\n");
        return;
    }
    else
    {
        printf("Enter the item to be inserted: ");
        scanf("%d", &item);
        if (front == rear && front == -1)
            front=rear=0;
        else
            rear++;
        arr[rear] = item;
    }
}
void delete (int *arr)
{
    if (front == rear && front == -1)
    {
        printf("\nUnderflow!Deletion not possible\n");
        return;
    }
    int x = arr[front];
    if (front == rear)//only a single element in queue
        front = rear = -1;
    else
        front++;
    printf("%d has been deleted:\n", x);
}
void main()
{
    int i, ch, maxsize;
    printf("Enter the number of elements to be entered into the array: ");
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
            display(arr);
            break;
        case 2:
            insert(arr, maxsize);
            break;
        case 3:
            delete (arr);
            break;
        case 4:
            exit(0);
        }
    }
}