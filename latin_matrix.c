#include<stdio.h>
void main()
{
    int n, i, j, k, l;
    printf("Enter the order of latin matrix: ");
    scanf("%d",&n);
    k=n+1;
    for(i=1;i<=n;i++)
    {
        l=k;
        while(l<=n)
        {
            printf("%d ",l);
            l++;
        }
        for(j=1;j<k;j++)
            printf("%d ",j);
        k--;
        printf("\n");
    }
}