#include <stdio.h>
int main()
{
    int n, m;
    printf("enter the 1st and 2nd array size:");
    scanf("%d %d", &n, &m);
    int arr[n], arr1[m], a[n + m], b[n];

    printf("enter the element in 1:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter the element in 2:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = arr[i];
    }
    for (int i = n; i < (n + m); i++)
    {
        a[i] = arr1[i - n];
    }
    int d = n + m;
    int v = n + m;
    int s = 0;
    printf("\nthe intersection is \n");
    for (int i = 0; i < v; i++)
    {
        for (int j = i + 1; j < v; j++)
        {
            if (a[i] == a[j])
            {
                b[s] = a[i];
                s++;
            }
        }
    }

    for (int i = 0; i < s; i++)
    {
        printf("%d ", b[i]);
    }

    for (int i = 0; i < d; i++)
    {
        for (int j = i + 1; j < d; j++)
        {
            if (a[i] == a[j])
            {

                for (int k = j; k < d - 1; k++)
                {
                    a[k] = a[k + 1];
                }
                d--;
                j--;
            }
        }
    }
    int c;
    for (int i = 0; i < d; i++)
    {
        for (int j = i + 1; j < d; j++)
        {
            if (a[i] > a[j])
            {
                c = a[i];
                a[i] = a[j];
                a[j] = c;
            }
        }
    }
    printf("\nthe union is \n");
    for (int i = 0; i < d; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
