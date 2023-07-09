#include <stdio.h>
#include <stdlib.h>
void main()
{
    int r, c, i, j;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &r, &c);
    // int *arr[r];
    int **arr = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i++)
        arr[i] = (int *)malloc(c * sizeof(int));
    printf("Enter the elements:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", (*(arr + i) + j));
    printf("Matrix is:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("The upper traingular matrix is\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(j>=i)
                printf("%d ",*(*(arr+i)+j));
            else
                printf("  ");
        }
        printf("\n");
    }
}