//Create a square matrix using dynamic memory allocation, input elements into it and find its trace and normal.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
    int r,c,i,j,trace=0,sum=0;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d",&r,&c);
    int *arr=(int*)malloc((r*c)*sizeof(int));
    printf("Enter the elements in the array: \n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",(arr+c*i+j));
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i==j)
                trace+=(*(arr+c*i+j));
            sum+=(*(arr+c*i+j)) * (*(arr+c*i+j));
        }
    }
    printf("Trace is: %d\n",trace);
    printf("Normal is: %ld\n",sqrt(sum));
}