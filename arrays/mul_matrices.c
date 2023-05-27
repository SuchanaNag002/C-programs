#include<stdio.h>
void getElements(int mat[][10],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            scanf("%d",&mat[i][j]);
    }
}
void multiply(int mat1[][10],int mat2[][10],int res[][10],int r1,int c1,int r2,int c2)
{
    int i,j,k;
    for(i=0;i<r1;i++)
        for(j=0;j<c2;j++)
            res[i][j]=0;
    for(i=0;i<r1;i++)
        for(j=0;j<c2;j++)
            for(k=0;k<c1;k++)
                res[i][j]+=mat1[i][k]*mat2[k][j];
}
void display(int mat[][10],int row,int col)
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
    int r1,r2,c1,c2,i,j;
    int mat1[10][10],mat2[10][10],res[10][10];
    printf("Enter the rows and columns of first matrix: ");
    scanf("%d%d",&r1,&c1);
    printf("Enter the rows and columns of second matrix: ");
    scanf("%d%d",&r2,&c2);
    if(c1!=r2)
        printf("Multiplication not possible\n");
    else
    {
        printf("Enter the elements of first matrix:\n");
        getElements(mat1,r1,c1);
        printf("Enter the elements of second matrix:\n");
        getElements(mat2,r2,c2);
        multiply(mat1,mat2,res,r1,c1,r2,c2);
        printf("The first matrix is:\n");
        display(mat1,r1,c1);
        printf("The second matrix is:\n");
        display(mat2,r2,c2);
        printf("The multiplied matrix is:\n");
        display(res,r1,c2);
    }
}