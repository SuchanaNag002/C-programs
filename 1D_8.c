#include<stdio.h>
void main()
{
    int n,i,j,k,temp;
    printf("Enter the order of latin matrix: ");
    scanf("%d",&n);
    k=n+1;
    for(i=1;i<=n;i++)
    {
        temp=k;
        while(temp<=n)
        {
            printf("%d ",temp);
            temp++;
        }
        for(j=1;j<k;j++)
            printf("%d ",j);
        k--;
        printf("\n");
    }
}