#include <stdio.h>
#include <stdlib.h>
int front = -1, rear = -1;
void display(int *queue)
{
    if (rear == -1 && front == -1)
    {
        printf("\nStack is empty!\n");
        return;
    }
    int i = front;
    while (i <= rear)
    {
        printf("%d ", queue[i]);
        i++;
    }
}
void peek(int *queue)
{
    if (front == -1 && rear == -1)
        printf("\nEmpty stack!");
    else
        printf("The top element is %d\n", queue[front]);
}
void queuePop(int *queue)
{
    if (front == rear && front == -1)
    {
        printf("\nUnderflow!Deletion not possible\n");
        return;
    }
    int x = queue[front];
    if (front == rear) // only a single element in queue
        front = rear = -1;
    else
        front++;
    printf("%d has been deleted:\n", x);
}
void queuePush(int *queue, int maxsize)
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
        if (rear == -1 && front == -1)
            front = rear = 0;
        else
            rear++;
        queue[rear] = item;
        for (int i = front; i < rear; i++)
        {
            int temp = queue[i];
            queue[i] = queue[rear];
            queue[rear] = temp;
        }
    }
}
void main()
{
    int i, ch, maxsize;
    printf("Enter the number of elements to be entered into the stack: ");
    scanf("%d", &maxsize);
    int *queue = (int *)malloc(maxsize * sizeof(int));
    while (1)
    {
        printf("\n*** MENU *** \n1. Display\n2. Push\n3. Pop\n4. Peek\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display(queue);
            break;
        case 2:
            queuePush(queue, maxsize);
            break;
        case 3:
            queuePop(queue);
            break;
        case 4:
            peek(queue);
            break;
        case 5:
            exit(0);
        }
    }
}