#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int *arr, int n)
{
    int flag=1;
    int i,j,temp;
    for(i=0; i<n-1 && flag==1; i++)
    {
        flag=0;
        for(j=0; j<n-1-i; j++)
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
}
int binSearch(int *arr, int l, int h, int x)
{
    if(h>=l)
    {
        int mid = l + (h - l)/2;
        if(arr[mid] == x)
            return mid;
        if(arr[mid] > x)
            return binSearch(arr, l, mid-1, x);
        return binSearch(arr, mid+1, h, x);
    }
    return -1;
}
void main()
{
    int n,i,x;
    printf("Enter the number of elements to be entered: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    bubbleSort(arr,n);
    printf("Enter the element to be searched: ");
    scanf("%d",&x);
    int ans = binSearch(arr, 0, n-1, x);
    if(ans!=-1)
        printf("%d was found\n",x);
    else
        printf("%d was not found\n",x);
}