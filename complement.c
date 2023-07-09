#include<stdio.h>
#include<string.h>
int main()
{
    char num[50],res[50];
    printf("Enter the number: ");
    gets(num);
    int len=strlen(num),carry=1,i,j,x;
    x=len;
    for(i=0;i<len;i++)
    {
        if(num[i]=='0')
            num[i]='1';
        else
            num[i]='0';
    }
    for(i=len-1;i>=0;i--)
    {
        if(num[i]=='1' && carry==1)
        {
            res[i]='0';
            if(i==0)
            {
                for(j=len-1;j>=0;j--)
                    res[j+1]=res[j];
                res[i]='1';
                x=len+1;
            }
        }
        else if(num[i]=='0' && carry==1)
        {
            res[i]='1';
            carry=0;
        }
        else
            res[i]=num[i];
    }
    res[x]='\0';
    printf("The 2's complement is: %s",res);
}