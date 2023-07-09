#include <stdio.h>
#include <stdlib.h>

int binarysearch(int[], int, int, int);
void main()
{
    int n, item, mid, key;
    printf("Please enter the number of elements: ");
    scanf("%d", &n);
    int a[n+1], i = 1;
    printf("Please enter the elements: ");
    while (i <= n)
    {
        scanf("%d", &a[i]);
        i = i + 1;
    }
    printf("Enter the item to be searched: ");
    scanf("%d", &item);
    int lb = 1, ub = n;
    key = binarysearch(a, lb, ub, item);
    if (key == -1)
        printf("Item not found");
    else
        printf("Item found at %d", key);
}
int binarysearch(int A[], int lb, int ub, int item)
{
    int mid;
    if (lb > ub) // base condition
        return -1;
    mid = (lb + ub) / 2;
    if (item == A[mid]) // element found
        return mid;
    else if (item < A[mid])
        return binarysearch(A, lb, mid - 1, item);
    else
        return binarysearch(A, mid + 1, ub, item);
}