#include<stdio.h>
#include<stdlib.h>
void merge(int *a, int low, int mid, int high, int n)
{
    int i,j,k;
    i=k=low;
    j=mid+1;
    int *b=(int*)malloc(n*sizeof(int));
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=high)
        b[k++]=a[j++];
    for(i=low;i<=high;i++)
        a[i]=b[i];
}
void mergeSort(int *a, int low, int high, int n)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSort(a, low, mid, n);
        mergeSort(a, mid+1, high, n);
        merge(a, low, mid, high, n);
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
    mergeSort(arr, 0, n-1, n);
    printf("The sorted array is: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}