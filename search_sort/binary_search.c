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
void main()
{
    int n,i,x,f=0,l,h,mid;
    printf("Enter the number of elements to be entered: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    bubbleSort(arr,n);
    printf("Enter the element to be searched: ");
    scanf("%d",&x);
    l=0,h=n-1;
    //binary search
    while(l<=h)
    {
        mid=l+(h-l)/2;
        if(arr[mid]==x)
        {
            f=1;
            break;
        }
        else if(arr[mid]>x)
            h=mid-1;
        else
            l=mid+1;
    }
    if(f==1)
        printf("%d was found\n",x);
    else
        printf("%d was not found\n",x);
}