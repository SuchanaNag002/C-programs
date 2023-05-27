#include<stdio.h>
void bubbleSort(int a[],int n)
{
    int i,j,temp;
    for (i=0;i<n-1;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
    int n,i,l,r,mid,x,f=0;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the element to be searched: ");
    scanf("%d",&x);
    bubbleSort(arr,n);
    l=0;
    r=n-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(x==arr[mid])
        {
            f=1;
            break;
        }
        else if(x>arr[mid])
            l=mid+1;
        else
            r=mid-1;
    }
    if(f==1)
        printf("Element has been found\n");
    else
        printf("Element has not been found\n");
}
