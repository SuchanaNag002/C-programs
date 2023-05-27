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
void insertRear(int *arr, int maxsize)//same as queue insert
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
void deleteFront(int *arr)//same as queue delete
{
    if (front == rear && front == -1)
    {
        printf("\nUnderflow!Deletion not possible\n");
        return;
    }
    int x = arr[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    printf("%d has been deleted:\n", x);
}
void insertFront(int *arr, int maxsize)
{
    int item;
    if (front == 0 && rear==maxsize-1)
    {
        printf("\nOverflow\n");
        return;
    }
    else
    {
        printf("Enter the item to be inserted: ");
        scanf("%d", &item);
        if (front == rear && front == -1)
            front = rear = 0;
        else
            front--;
        arr[front] = item;
    }
}
void deleteRear(int *arr)
{
    if (front == rear && front == -1)
    {
        printf("\nUnderflow!Deletion not possible\n");
        return;
    }
    int x = arr[rear];
    if (front == rear)
        front = rear = -1;
    else
        rear--;
    printf("%d has been deleted:\n", x);
}
void main()
{
    int i, ch, maxsize, n;
    printf("Enter the number of elements to be entered into the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    maxsize = n;
    while (1)
    {
        printf("\n*** MENU *** \n1. Display\n2. InsertFront\n3. DeleteRear\n4. InsertRear\n5. DeleteFront\n6. Exit");
        printf("\nenter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display(arr);
            break;
        case 2:
            insertFront(arr,maxsize);
            break;
        case 3:
            deleteRear(arr);
            break;
        case 4:
            insertRear(arr, maxsize);
            break;
        case 5:
            deleteFront(arr);
            break;
        case 6:
            exit(0);
        }
    }
}