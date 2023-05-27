//Input an array of n elements into an array A[ ]. Create an array pointers *B[ ], whose each element is a  pointer to the corresponding elements of A[ ]. Find the sum of the elements of the array A[ ] using the array of pointers B[].
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,i,sum=0;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int *b=a;//points to 0th element
    for(i=0;i<n;i++)
    {
        sum+=*b;
        b++;
    }
    printf("The sum is: %d\n",sum);
}