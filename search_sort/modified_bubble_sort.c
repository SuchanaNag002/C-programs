#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,i,x,j,flag=1,temp;
    printf("Enter the number of elements to be entered: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0; i<n-1 && flag==1; i++)
    {
        flag=0;
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                flag=1;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("The sorted array is: ");
    for(i = 0; i < n; i++)
        printf("%d ",arr[i]);
}