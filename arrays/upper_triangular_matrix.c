#include <stdio.h>
void main()
{

    int i, j, r, c, array[10][10];
    printf("Enter the r and c value:");

    scanf("%d%d", &r, &c);
    for (i = 1; i <= r; i++)
        for (j = 1; j <= c; j++)
            scanf("%d", &array[i][j]);

    printf("Matrix is:\n");
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }

    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            if (i >= j)
                printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            if (j >= i)
                printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}