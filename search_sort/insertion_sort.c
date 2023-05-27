#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,i,j,x;
    printf("Enter the number of elements to be entered: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=1;i<n;i++)
    {
        x=arr[i];
        j=i-1;
        while(j>=0 && x<arr[j])
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=x;
    }
    printf("The sorted array is: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}