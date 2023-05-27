#include <stdio.h>
int main()
{
    int n,i,x,f=0;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements: \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the element to be deleted: ");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            f=1;
            break;
        }
    }
    if(f==0)
        printf("Item not found\n");
    else
    {
        for(i=0;i<n;i++)
            if (arr[i]!=x)
                printf("%d ",arr[i]);  
    }
}
