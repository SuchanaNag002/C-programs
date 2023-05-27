#include<stdio.h>
#define size 5
void display(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
void bubble_sort(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void find_union(int arr1[],int arr2[],int union_arr[])
{
    int i=0,j=0,k=0;
    while(i<size && j<size)
    {
        if(arr1[i]<arr2[j])
        {
            union_arr[k]=arr1[i];
            i++;
        }
        else if(arr1[i]>arr2[j])
        {
            union_arr[k]=arr2[j];
            j++;
        }
        else
        {
            union_arr[k]=arr2[j];
            i++;
            j++;
        }
        k++;
    }
    if(i==size)
    {
        while(j<size)
        {
            union_arr[k]=arr2[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<size)
        {
            union_arr[k]=arr1[i];
            i++;
            k++;
        }
    }
    printf("The union array is: ");
    display(union_arr,k);
}
void intersection(int arr1[],int arr2[],int inter_arr[])
{
    int i=0,j=0,k=0;
    while(i<size && j<size)
    {
        if(arr1[i]<arr2[j])
            i++;
        else if(arr1[i]>arr2[j])
            j++;
        else
        {
            inter_arr[k]=arr1[i];
            i++;
            j++;
            k++;
        }
    }
    printf("The intersection array is: ");
    display(inter_arr,k);
}
void main()
{
    int arr1[size],arr2[size],union_arr[size*2],inter_arr[size];
    int ind;
    printf("Enter the first array elements: ");
    for(ind=0;ind<size;ind++)
        scanf("%d",&arr1[ind]);
    bubble_sort(arr1,size);
    printf("Enter the second array elements: ");
    for(ind=0;ind<size;ind++)
        scanf("%d",&arr2[ind]);
    bubble_sort(arr2,size);
    printf("The first array is: ");
    display(arr1,size);
    printf("The second array is: ");
    display(arr2,size);
    find_union(arr1,arr2,union_arr);
    intersection(arr1,arr2,inter_arr);
}