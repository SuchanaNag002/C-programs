#include<stdio.h>
#include<stdlib.h>
void main()
{
    int r,c,i,j;
    printf("Enter the rows and columns of the matrix: ");
    scanf("%d%d",&r,&c);
    int arr[r][c],transpose[c][r];
    printf("Enter the elements of the matrix:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&arr[i][j]);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            transpose[j][i]=arr[i][j];
    }
    printf("The original matrix is:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
    printf("The transposed matrix is:\n");
    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
            printf("%d ",transpose[i][j]);
        printf("\n");
    }
}