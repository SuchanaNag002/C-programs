#include<stdio.h>
int conversion(int x,int dig)
{
    int i=1,r,con_num=0;
    while (x) 
    {
        r = x%dig;
        x/=dig;
        con_num+=(r*i);
        i*=10;
    }
    return con_num;
}
void main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Binary equivalent of %d is: %d \n",n,conversion(n,2));
    printf("Octal equivalent of %d is: %d \n",n,conversion(n,8));
    if(n>=10 && n<=15)
        printf("Hexadecimal equivalent of %d is: %c \n",n,(65+n-10));
    else
        printf("Hexadecimal equivalent of %d is: %d \n",n,conversion(n,16));
}