#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i;
    double sum=0,avg,num;
    printf("Enter the number of inputs: ");
    scanf("%d",&n);
    printf("The random numbers between 0 and 1 are: ");
    for(i=1;i<=n;i++)
    {
        num=(double)rand()/(double)RAND_MAX;//b/w 0 and 1
        printf("%lf ",num);
        sum+=num;
    }
    avg=sum/n;
    printf("\nSum: %lf",sum);
    printf("\nAverage: %lf",avg);
}