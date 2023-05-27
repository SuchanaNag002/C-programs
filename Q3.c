//  Create two dynamic 1D arrays containing m and n elements respectively (m may or may not be equal to n) in sorted order. Merge them into a third array merged[ ] in sorted order. Finally display the merged array.
#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int *a,int n)
{
    int i, j,temp;
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
void main()
{
    int m,n,i,j,k;
    printf("Enter the size of first array: ");
    scanf("%d",&m);
    int *arr1=(int*)malloc(m*sizeof(int));
    printf("Enter the elements of first array: ");
    for(i=0;i<m;i++)
        scanf("%d",(arr1+i));
    bubbleSort(arr1,m);
    printf("Enter the size of second array: ");
    scanf("%d",&n);
    int *arr2=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of second array: ");
    for(i=0;i<n;i++)
        scanf("%d",(arr2+i));
    bubbleSort(arr2,n);
    int *arr3=(int*)malloc((m+n)*sizeof(int));
    i=j=k=0;
    while(i<m)
        *(arr3+(k++))=*(arr1+(i++));
    while(j<n)
        *(arr3+(k++))=*(arr2+(j++));
    printf("Merged array is: ");
    for(i=0;i<(m+n);i++)
        printf("%d ",*(arr3+i));
}