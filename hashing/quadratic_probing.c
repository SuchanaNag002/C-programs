#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
void insert(int hash[], int m)
{
    int key, ind, i, hkey;
    printf("Enter a value to be inserted into hash table: ");
    scanf("%d", &key);
    hkey = key % m;
    for (i = 0; i < m; i++)
    {
        ind = (hkey + i*i) % m;
        if (hash[ind] == -1)
        {
            hash[ind] = key;
            break;
        }
    }
    if (i == m)
        printf("Hash table full!!Element cannot be inserted");
}
void delete(int hash[], int m)
{
    int key, ind, i, hkey;
    printf("Enter a value to be deleted from hash table: ");
    scanf("%d", &key);
    hkey = key % m;
    for (i = 0; i < m; i++)
    {
        ind = (hkey + i*i) % m;
        if (hash[ind] == key)
        {
            hash[ind] = -1;
            break;
        }
    }
    if (i == m)
        printf("Element was not found");
}
void search(int hash[], int m)
{
    int key, ind, i, hkey;
    printf("Enter a value to be searched in hash table: ");
    scanf("%d", &key);
    hkey = key % m;
    for (i = 0; i < m; i++)
    {
        ind = (hkey + i*i) % m;
        if (hash[ind] == key)
        {
            printf("%d found at index %d", key, ind);
            break;
        }
    }
    if (i == m)
        printf("Element was not found");
}
void display(int hash[], int m)
{
    int i;
    printf("Elements in the hash table are\n");
    for (i = 0; i < m; i++)
    {
        if(hash[i]==-1)
            printf("At index %d \t value =  NULL\n", i);
        else
           printf("At index %d \t value =  %d\n", i,hash[i]); 
    }
}
void main()
{
    int ch, m, i;
    printf("Enter the size of hash table: ");
    scanf("%d", &m);
    int *hash = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
        hash[i] = -1;
    while (1)
    {
        printf("\nPress \n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(hash, m);
            break;
        case 2:
            delete (hash, m);
            break;
        case 3:
            search(hash, m);
            break;
        case 4:
            display(hash, m);
            break;
        case 5:
            exit(0);
        }
    }
}