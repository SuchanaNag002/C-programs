#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
typedef struct Node n;
void insert(n **hash, int size)
{
    n *node = (n *)malloc(sizeof(n));
    int key, hashKey;
    printf("Enter the value to be inserted: ");
    scanf("%d", &key);
    node->data = key;
    node->link = NULL;
    hashKey = key % size;
    if (hash[hashKey] == NULL)
        hash[hashKey] = node;
    else
    {
        n *temp = hash[hashKey];
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = node;
    }
}
void delete(n *hash[], int size)
{
    n *node, *ptr;
    int key, hashKey,f=0;
    printf("Enter the value to be deleted: ");
    scanf("%d", &key);
    hashKey = key % size;
    node = hash[hashKey];
    if(node != NULL)
    {
        if(node->data == key)
        {
            ptr = node;
            node = node->link;
            hash[hashKey]=node;
            free(ptr);
            f=1;
        }
        else
        {
            while(node->link)
            {
                if(node->link->data == key)
                {
                    ptr = node->link;
                    node->link = node->link->link;
                    free(ptr);
                    f=1;
                    break;
                }
                node = node->link;
            }
        }
    }
    if(f==0)
        printf("No such element exits");
}
void search(n *hash[], int size)
{
    int key, hashKey, f = 0;
    printf("Enter the value to be searched: ");
    scanf("%d", &key);
    hashKey = key % size;
    n *node = hash[hashKey];
    while (node != NULL)
    {
        if (node->data == key)
        {
            f = 1;
            break;
        }
        node = node->link;
    }
    if (f == 0)
        printf("%d is absent",key);
    else
        printf("%d is present at index %d",key,hashKey);
}
void display(n *hash[], int size)
{
    int i;
    n *node;
    for (i = 0; i < size; i++)
    {
        printf("At index %d--> ",i);
        node = hash[i];
        if(node==NULL)
            printf("NULL");
        else
        {
            while (node != NULL)
            {
                printf("%d ", node->data);
                node = node->link;
            }
        }
        printf("\n");
    }
}
void main()
{
    int size, ch, i;
    printf("Enter the size of the hash table: ");
    scanf("%d", &size);
    n **hash = (n **)malloc(size * sizeof(n*));
    for(i=0;i<size;i++)
        hash[i]=NULL;
    while (1)
    {
        printf("\n*** MENU *** \n1. Display\n2. Insert\n3. Delete\n4. Search\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display(hash, size);
            break;
        case 2:
            insert(hash, size);
            break;
        case 3:
            delete (hash, size);
            break;
        case 4:
            search(hash, size);
            break;
        case 5:
            exit(0);
        }
    }
}
