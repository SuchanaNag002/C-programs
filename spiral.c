#include<stdio.h>
int main()
{
    int i, j, m, n, left, right, dir, top, down;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d",&m,&n);
    int arr[m][n];
    printf("Enter the 2D matrix:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    left=0,top=0,right=n-1,down=m-1,dir=0;
    while(top<=down && left<=right)
    {
        if(dir==0)//left to right
        {
            for(j=left;j<=right;j++)
                printf("%d ",arr[top][j]);
            top++;
        }
        else if(dir==1)//top to down
        {
            for(i=top;i<=down;i++)
                printf("%d ",arr[i][right]);
            right--;
        }
        else if(dir==2)//right to left
        {
            for(j=right;j>=left;j--)
                printf("%d ",arr[down][j]);
            down--;
        }
        else//down to top
        {
            for(i=down;i>=top;i--)
                printf("%d ",arr[i][left]);
            left++;
        }
        dir=(dir+1)%4;
    }
}