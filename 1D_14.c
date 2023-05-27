#include <stdio.h>
int main()
{
    int n;
    printf("enter the size :");
    scanf("%d", &n);
    char arr[n + 1];
    char arr1[n + 1], arr2[n + 1];
    printf("enter the binary number:");
    scanf("%s", &arr);
    printf("the binary number is %s\n", arr);
    printf("the 1s complement is:");
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == '1')
        {
            arr1[i] = '0';
        }
        else if (arr[i] == '0')
        {
            arr1[i] = '1';
        }
    }
    arr1[n] = '\0';
    printf("%s", arr1);
    int carry = 1;
    printf("\nthe 2s complement is:");
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr1[i] == '1' && carry == 1)
        {
            arr2[i] = '0';
        }
        else if (arr1[i] == '0' && carry == 1)
        {
            arr2[i] = '1';
            carry = 0;
        }
        else
        {
            arr2[i] = arr1[i];
        }
    }
    arr2[n] = '\0';
    printf("%s", arr2);
    return 0;
}
