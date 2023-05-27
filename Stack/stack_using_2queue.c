#include <stdio.h>
#include <stdlib.h>
int front1 = -1, rear1 = -1, front2=-1, rear2=-1;
void display(int *queue1)
{
    if (rear1==-1 && front1 == -1)
    {
        printf("\nStack is empty!\n");
        return;
    }
    int i = front1;
    while (i <= rear1)
    {
        printf("%d ", queue1[i]);
        i++;
    }
}
void peek(int *queue1)
{
    if (front1 ==-1 && rear1 == -1)
        printf("\nEmpty stack!");
    else
        printf("The top element is %d\n", queue1[front1]);
}
void queuePop(int *queue1)
{
    if (front1 == rear1 && front1 == -1)
    {
        printf("\nUnderflow!Deletion not possible\n");
        return;
    }
    int x = queue1[front1];
    if (front1 == rear1)//only a single element in queue
        front1 = rear1 = -1;
    else
    {
        for(int i= front1; i< rear1;i++)
            queue1[i]=queue1[i+1];
        rear1--;
    }
    printf("%d has been deleted:\n", x);
}
void queuePush(int *queue1, int *queue2, int maxsize)
{
    int item,i;
    if (rear1 == (maxsize - 1))
    {
        printf("\nOverflow\n");
        return;
    }
    else
    {
        printf("Enter the item to be inserted: ");
        scanf("%d", &item);
        //push new element to queue2
        front2=rear2=0;
        queue2[rear2]=item;
        //insert elements from queue1(in FIFO fashion) to queue2 one by one, at the end queue1 becomes empty
        if(front1==0)
        {
            for(i=front1;i<=rear1;i++)
                queue2[++rear2]=queue1[i];
        }
        //swap queue1 and queue2 such that ultimately queue2 becomes empty
        front1=0;
        rear1=-1;
        for(i=front2;i<=rear2;i++)
            queue1[++rear1]=queue2[i];
    }
}
void main()
{
    int i, ch, maxsize;
    printf("Enter the number of elements to be entered into the stack: ");
    scanf("%d", &maxsize);
    int *queue1 = (int *)malloc(maxsize * sizeof(int));
    int *queue2 = (int *)malloc(maxsize * sizeof(int));
    while (1)
    {
        printf("\n*** MENU *** \n1. Display\n2. Push\n3. Pop\n4. Peek\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display(queue1);
            break;
        case 2:
            queuePush(queue1, queue2, maxsize);
            break;
        case 3:
            queuePop(queue1);
            break;
        case 4:
            peek(queue1);
            break;
        case 5:
            exit(0);
        }
    }
}