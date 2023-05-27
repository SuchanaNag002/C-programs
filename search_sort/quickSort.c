#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[], int start, int end)
{
    int pivot,count=0,i,j,pivotInd;
    pivot=arr[start];
    for(i=start+1;i<=end;i++)
        if(arr[i]<=pivot)
            count++;
    pivotInd=start+count;
    swap(&arr[pivotInd],&arr[start]);
    i=start,j=end;
    while(i< pivotInd && j>pivotInd)
    {
        while(arr[i]<pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<pivotInd && j>pivotInd)
        {
            swap(&arr[i],&arr[j]);
            i++;
            j--;
        }
    }
    return pivotInd;
}
void quickSort(int arr[], int start, int end)
{
    if(start>=end)
        return;
    int pos = partition(arr,start,end);
    quickSort(arr, start, pos-1);
    quickSort(arr, pos+1, end);
}
void main()
{
    int n,i;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quickSort(arr,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}