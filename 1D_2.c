#include <stdio.h>
#include <stdlib.h>
#include<math.h>
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
int main()
{
    int n, i,mode, count, maxcount;
    double sum = 0,sum2=0,sd, var,mean,median;
    printf("Enter the number of inputs: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        arr[i] = rand() % 101; // generates a random number between 0 and 100
    bubbleSort(arr,n);
    for (i = 0; i < n; i++)
        printf("%d ",arr[i]);
    maxcount=0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        count=0;
        for (int j = 0; j < n; j++)
            if (arr[i] == arr[j])
                count++;
        if (count > maxcount)
        {
            maxcount = count;
            mode= arr[i];
        }
    }
    mean=sum/n;
    if (n & 1)
        median = arr[n/2];
    else
        median = (arr[(n/2)-1] + arr[n/2]) / 2.0;
    for(i=0;i<n;i++)
        sum2+=(arr[i]-mean)*(arr[i]-mean);
    var=sum2/n;
    sd=sqrt(var);
    printf("\nMean is: %lf\n",mean);
    printf("Median is: %lf\n",median);
    printf("Mode is: %d\n",mode);
    printf("Standard deviation is: %lf\n",sd);
    printf("Variance is: %lf\n",var);
}
