#include <stdio.h>
#include <stdlib.h>
int top=-1;
void display(int *arr, int top)
{
    int ind = top;
    if(top==-1)
    {
        printf("\nEmpty Stack!\n");
        return;
    }
    while (ind >= 0)
    {
        printf("%d ", arr[ind]);
        ind--;
    }
}
int push(int *arr, int maxsize, int top)
{
    int x;
    if ((top + 1) >= maxsize)
    {
        printf("\nStack overflow!!\n");
    }
    else
    {
        top=top+1;
        printf("\nEnter the element to be pushed\n");
        scanf("%d", &x);
        arr[top] = x;
    }
    return top;
}
void peek(int *arr, int top)
{
    if (top == -1)
        printf("\nEmpty stack!");
    else
        printf("The top element is %d\n", arr[top]);
}
int pop(int *arr, int top)
{
    if (top == -1)
        printf("\nUnderflow error.Empty stack!!!\n");
    else
        top--;
    return top;
}
int main()
{
    int i, ch, maxsize;
    printf("Enter the maximum size of stack: ");
    scanf("%d", &maxsize);
    int *arr = (int *)malloc(maxsize * sizeof(int));
    while (1)
    {
        printf("\n*** MENU *** \n1. Display\n2. Push\n3. Peek\n4. Pop");
        printf("\n5. Exit\n");
        printf("\nenter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display(arr, top);
            break;
        case 2:
            top = push(arr, maxsize, top);
            break;
        case 3:
            peek(arr, top);
            break;
        case 4:
            top = pop(arr, top);
            break;
        case 5:
            exit(0);
        }
    }
}