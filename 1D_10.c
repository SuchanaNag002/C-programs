#include<stdio.h>
void main()
{
    int d,m,y,i,result=0;
    printf("Enter the date in date/month/year format: ");
    scanf("%d%d%d",&d,&m,&y);
    int arr[13];
    for(i=1;i<=12;i++)
    {
        if(i==1 || i== 3 || i==5 || i==7 ||i==8 || i== 10 || i==12)
            arr[i]=31;
        else if(i==2)
        {
            if(((y % 4 == 0) && (y % 100!= 0)) || (y%400 == 0))
                arr[i]=29;
            else
                arr[i]=28;
        }
        else
            arr[i]=30;
    }
    for(i=1;i<m;i++)
        result+=arr[i];
    result+=(d-1);
    printf("The difference between the dates is %d days\n",result);
}