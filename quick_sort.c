#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition( int arr[], int low, int high)
{
    int pivot=arr[high];
    int i=low-1,j;
    for(j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            //swap
            swap(&arr[i],&arr[j]);
        }
    }
    //swap with pivot
    i++;
    swap(&arr[i],&arr[high]);
    return i;
}
void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
int main()
{
    int n,i;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quickSort(arr, 0, n-1);
    printf("The sorted array is: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}