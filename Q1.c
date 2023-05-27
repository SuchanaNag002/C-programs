//Create a dynamic 1D array of n elements and search an element using linear search through a function int linearSearch(a,n) which would return 1 if the element is found and 0 otherwise.
#include<stdio.h>
#include<stdlib.h>
int linearSearch(int *a,int n)
{
    int x,f=0,i;
    printf("Enter the element to be searched: ");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
            return 1;
    }
    return 0;
}
void main()
{
    int n,i,ans;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",(arr+i));
    ans=linearSearch(arr,n);
    if(ans==1)
        printf("Element has been found\n");
    else
       printf("Element has not been found\n"); 
}