#include<stdio.h>
void bubblesort(int *arr)
{	
	int size = sizeof(*arr) / sizeof(arr[0]);
    printf("%d",size);
	int i,j,temp;
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("the sorted array is:\n");
	for(i=0;i<size;i++)
	{
		printf("%d,",arr[i]);
	}
}

int main()
{
	int arr[]={2,21,34,5,81,4,9,22,53,13};
	int n;
	printf("enter your choice \n");
	printf("1. for bubble sort \n");
	scanf("%d", &n);
	switch (n)
	{
		case 1:
			bubblesort(arr);
			break;
		default:
			printf("wrong input");
			break;
	}
	return 0;
}