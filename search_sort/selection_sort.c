#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,i,j,min,pos,temp;
    printf("Enter the number of elements to be entered: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n-1;i++)
    {
        min=arr[i];
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                pos=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[pos];
        arr[pos]=temp;
    }
    printf("The sorted array is: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}