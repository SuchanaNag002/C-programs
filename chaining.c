#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
typedef struct Node n;
void insert(n **hash, int size)
{
    n *node=(n*)malloc(sizeof(n));
    int key,hkey;
    printf("Enter the value to be inserted: ");
    scanf("%d", &key);
    node->data=key;
    node->link=NULL;
    hkey=key%size;
    if(hash[hkey]==NULL)
        hash[hkey]=node;
    else
    {
        n *x=hash[hkey];
        while(x->link!=NULL)
            x=x->link;
        x->link=node;
    }
}
void delete(n **hash, int size)
{
    n *node, *ptr;
    int key,hkey,f=0;
    printf("Enter the value to be deleted: ");
    scanf("%d", &key);
    hkey = key % size;
    node=hash[hkey];
    if(node!=NULL)
    {
        if(node->data==key)
        {
            ptr=node;
            node=node->link;
            hash[hkey]=node;
            free(ptr);
            f=1;
        }
        else
        {
            while(node->link)
            {
                if(node->link->data==key)
                {
                    ptr=node->link;
                    node->link=ptr->link;
                    free(ptr);
                    f=1;
                    break;
                }
                node=node->link;
            }
        }
        if(f==0)
            printf("No such element exits");
    }
}