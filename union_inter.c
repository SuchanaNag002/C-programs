#include<stdio.h>
#include<stdlib.h>
#define size 50
void getValue(int arr[], int n)
{
    printf("Enter the array elements: ");
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
}
void selectionSort(int arr[], int n)
{
    int i,j,min,pos,temp;
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
}
int remDup(int arr[], int *n)
{
    int i,k=0;
    for(i=0;i<(*n-1);i++)
    {
        if(arr[i]!=arr[i+1])
            arr[k++]=arr[i];
    }
    arr[k++]=arr[*n-1];
    *n=k;
}
int findUnion(int arr1[], int arr2[], int unionArr[], int n1, int n2)
{
    printf("The union is: ");
    int i=0, j=0, k=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
            unionArr[k++]=arr1[i++];
        else if(arr1[i]>arr2[j])
            unionArr[k++]=arr2[j++];
        else
        {
            unionArr[k]=arr1[i];
            i++;
            j++;
            k++;
        }
    }
    while(i<n1)
        unionArr[k++]=arr1[i++];
    while(j<n2)
        unionArr[k++]=arr2[j++];
    return k;
}
int findIntersection(int arr1[], int arr2[], int interArr[], int n1, int n2)
{
    printf("The intersection is: ");
    int i=0, j=0, k=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
            i++;
        else if(arr1[i]>arr2[j])
            j++;
        else
        {
            interArr[k]=arr1[i];
            i++;
            j++;
            k++;
        }
    }
    return k;
}
void display(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int main()
{
    int arr1[size], arr2[size], interArr[size], unionArr[2*size];
    int n1,n2,len;
    printf("Enter the size of 1st array: ");
    scanf("%d",&n1);
    getValue(arr1, n1);
    selectionSort(arr1, n1);
    printf("Enter the size of 2nd array: ");
    scanf("%d",&n2);
    getValue(arr2, n2);
    selectionSort(arr2, n2);
    printf("The 1st array is: ");
    display(arr1, n1);
    remDup(arr1,&n1);
    printf("The 2nd array is: ");
    display(arr2, n2);
    remDup(arr2,&n2);
    len=findUnion(arr1,arr2,unionArr,n1,n2);
    display(unionArr,len);
    len=findIntersection(arr1,arr2,interArr,n1,n2);
    display(interArr,len);
}