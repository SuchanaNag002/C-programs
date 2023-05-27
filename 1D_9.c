#include<stdio.h>
#include<stdlib.h>
void main()
{
    int m,n,i,j,k,l;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d",&m,&n);
    int arr[m][n];
    printf("Enter the matrix elements:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    // k - starting row index
    // m - ending row index
    // l - starting column index
    // n - ending column index
    // i - iterator
    printf("The spiral form of matrix is:\n");
    k=l=0;
    while (k < m && l < n) 
    {
        //Print the first row from the remaining rows 
        for (i = l; i < n; ++i) 
            printf("%d ", arr[k][i]);
        k++;
        //Print the last column from the remaining columns
        for (i = k; i < m; ++i) 
            printf("%d ", arr[i][n - 1]);
        n--;
        //Print the last row from the remaining rows
        if (k < m)
        {
            for (i = n - 1; i >= l; --i) 
                printf("%d ", arr[m - 1][i]);
            m--;
        }
        //Print the first column from the remaining columns
        if (l < n) 
        {
            for (i = m - 1; i >= k; --i) 
                printf("%d ", arr[i][l]);
            l++;
        }
    }
}