#include<stdio.h>
int main(void) 
{
    int num,n,j,sum;
    int lucas0 = 2;
    int lucas1 = 1; int fibo0 = 0, fibo1 = 1;

    printf("Enter a number:\n");
    scanf("%d", &n);
    if(n < 4) num = n +4;
    else num =n;
    int arr[n];
    arr[0] = 2; arr[1] = 0; arr[2] = 1; arr[3] = 1;
    for(j = 4; j <= n; j++)
    {
        if (j%2 ==0) 
        {
            sum = lucas0 + lucas1;
            arr[j] = sum;
            lucas0 = lucas1;
            lucas1 = sum; }
        else
        {
            sum = fibo0+fibo1;
            arr[j] = sum;
            fibo0 = fibo1;
            fibo1 = sum; 
        }
       
    }

    for(j = 0; j <= n; j++)
    {printf("%d ", arr[j]);}
    printf("\n");
	return 0;
}