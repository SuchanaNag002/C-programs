#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
int main()
{
    int n,i,j,maxcount,count,mode;
    double sum=0,sum2=0,sd,var,mean,median;
    printf("Enter the number of inputs: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        arr[i]=rand()%101;
    bubble_sort(arr,n);
    printf("The array is: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    maxcount=0;
    for(i=0;i<n;i++)
    {
        sum+=arr[i];
        count=0;
        for(j=0;j<n;j++)
            if(arr[i]==arr[j])
                count++;
        if(count>maxcount)
        {
            maxcount=count;
            mode=arr[i];
        }
    }
    mean=sum/n;
    if(n&1)
        median=arr[n/2];
    else
        median=(arr[(n/2)-1]+arr[n/2])/2.0;
    for(i=0;i<n;i++)
        sum2+=(arr[i]-mean)*(arr[i]-mean);
    var=sum2/n;
    sd=sqrt(var);
    printf("\nMean is: %lf",mean);
    printf("\nMedian is: %lf",median);
    printf("\nMode is: %d",mode);
    printf("\nStandard deviation is: %lf",sd);
    printf("\nVariance is: %lf",var);
}