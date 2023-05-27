#include<stdio.h>
void main()
{
    int n,i;
    printf("Enter the number range: ");
    scanf("%d",&n);
    int arr[n];
    arr[0]=0;
    arr[1]=1;
    for (i=2;i<n;i++)
        arr[i]=arr[i-1]+arr[i-2];
    printf("The fibonacci series is:\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);  
}