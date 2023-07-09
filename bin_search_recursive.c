#include<stdio.h>
#include<stdlib.h>
int bin_search(int *arr, int low, int high, int x)
{
    if(low>high)
        return -1;
    int mid=(low+high)/2;
    if(x==arr[mid])
        return mid;
    else if(x>arr[mid])
        return bin_search(arr,mid+1,high,x);
    return bin_search(arr,low,mid-1,x);
}
int main()
{
    int n,i,x,res;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the element to be searched: ");
    scanf("%d",&x);
    res=bin_search(arr,0,n-1,x);
    if(res!=-1)
        printf("%d was found at index %d\n",x,res);
    else
        printf("%d is not present in the array\n",x);
}