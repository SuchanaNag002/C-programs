#include<stdio.h>
#include<stdlib.h>
void getVal(int **mat, int row, int col)
{
    int i,j;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            scanf("%d",(*(mat+i)+j));
}
void multiply(int **mat1, int **mat2, int** res, int r1, int r2, int c1, int c2)
{
    int i,j,k;
    for(i=0;i<r1;i++)
        for(j=0;j<c2;j++)
            *(*(res+i)+j)=0;
    for(i=0;i<r1;i++)
        for(j=0;j<c2;j++)
            for(k=0;k<c1;k++)
                res[i][j]+=mat1[i][k]*mat2[k][j];
}
void display(int **mat, int row, int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
}
void main()
{
    int r1, r2, c1, c2, i, j;
    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d%d",&r1,&c1);
    printf("Enter the number of rows and columns of second matrix: ");
    scanf("%d%d",&r2,&c2);
    if(c1!=r2)
        printf("Multiplication not possible\n");
    else
    {
        int **mat1=(int**)malloc(r1*sizeof(int*));
        for(i=0;i<r1;i++)
            mat1[i]=(int*)malloc(c1*sizeof(int));
        printf("Enter the elements of first matrix:\n");
        getVal(mat1,r1,c1);
        int **mat2=(int**)malloc(r2*sizeof(int*));
        for(i=0;i<r2;i++)
            mat2[i]=(int*)malloc(c2*sizeof(int));
        printf("Enter the elements of second matrix:\n");
        getVal(mat2,r2,c2);
        printf("The first matrix is:\n");
        display(mat1,r1,c1);
        printf("The second matrix is:\n");
        display(mat2,r2,c2);
        int **res=(int**)malloc(c1*sizeof(int*));
        for(i=0;i<c1;i++)
            res[i]=(int*)malloc(r2*sizeof(int));
        printf("The multiplied matrix is:\n");
        multiply(mat1,mat2,res,r1,c1,r2,c2);
        display(res,r1,c2);
    }
    
}