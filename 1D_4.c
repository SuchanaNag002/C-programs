#include<stdio.h>
int remDup(int arr[], int n)
{
	if (n==0 || n==1)
		return n;
	int j = 0;
	for (int i=0; i < n-1; i++)
		if (arr[i] != arr[i+1])
			arr[j++] = arr[i];

	arr[j++] = arr[n-1];
	return j;
}

int main()
{
	int n,i;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements: \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
	n = remDup(arr, n);
	for (i=0; i<n; i++)
		printf("%d ",arr[i]);//updated array
}
