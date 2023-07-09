#include<stdio.h>
int conversion(int x, int dig)
{
    int r, dig, res=0, i=1;
    while(x)
    {
        r=x%dig;
        x=x/dig;
        res+=(r*i);
        i*=10;
    }
    return num;
}
int main()
{

}