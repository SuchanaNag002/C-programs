#include <stdio.h>
#include <stdlib.h>
int front = -1, rear = -1;
void display(int *arr, int *priority)
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty!\n");
        return;
    }
    int i = front;
    while (i <= rear)
    {
        printf("Element: %d, Priority: %d\n", arr[i], priority[i]);
        i++;
    }
}
void push(int *arr, int *priority, int maxsize)
{
    int item, x;
    if (rear == (maxsize - 1))
    {
        printf("\nOverflow\n");
        return;
    }
    else
    {
        printf("Enter the item to be inserted and its priority: ");
        scanf("%d%d", &item, &x);
        if (front == rear && front == -1)
            front = rear = 0;
        else
            rear++;
        arr[rear] = item;
        priority[rear] = x;
    }
}
void pop(int *arr, int *priority)
{
    int i, j;
    if (front == rear && front == -1)
    {
        printf("\nUnderflow!Deletion not possible\n");
        return;
    }
    if (front == rear)
        front = rear = -1;
    else
    {
        int maxp = priority[front];
        int maxn = arr[front];
        for (i = front; i <= rear; i++)
        {
            if (priority[i] > maxp)
            {
                maxp = priority[i];
                maxn = arr[i];
            }
        }
        for (i = front; i <= rear; i++)
        {
            if (priority[i] == maxp)
            {
                for (j = i; j < rear; j++)
                {
                    arr[j] = arr[j + 1];
                    priority[j] = priority[j + 1];
                }
                break;
            }
        }
        rear--;
        printf("%d was deleted with priority %d\n", maxn, maxp);
    }
}
void peek(int *arr, int *priority)
{
    int maxp = priority[front], maxi;
    for (int i = front; i <= rear; i++)
    {
        if (priority[i] > maxp)
        {
            maxp = priority[i];
            maxi = arr[i];
        }
    }
    printf("%d is the peek element", maxi);
}
int main()
{
    int i, ch, maxsize;
    printf("Enter the number of elements to be entered into the queue: ");
    scanf("%d", &maxsize);
    int *arr = (int *)malloc(maxsize * sizeof(int));
    int *priority = (int *)malloc(maxsize * sizeof(int));
    while (1)
    {
        printf("\n*** MENU *** \n1. Display\n2. Push\n3. Pop\n4. Peek");
        printf("\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display(arr, priority);
            break;
        case 2:
            push(arr, priority, maxsize);
            break;
        case 3:
            pop(arr, priority);
            break;
        case 4:
            peek(arr, priority);
            break;
        case 5:
            exit(0);
        }
    }
}