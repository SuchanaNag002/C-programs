#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,i,x,f=0;
    printf("Enter the number of elements to be entered: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the element to be searched: ");
    scanf("%d",&x);
    //linear search
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            f=1;
            break;
        }
    }
    if(f==1)
        printf("%d was found at index %d\n",x,i);
    else
        printf("%d was not found\n",x);
}