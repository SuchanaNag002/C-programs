#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int info;
    struct Node *lc,*rc;
};
typedef struct Node bst;
void displayInorder(bst *root)
{
    if(!root)
        return;
    displayInorder(root->lc);
    printf("%d ",root->info);
    displayInorder(root->rc);
}
bst *create(bst *root)
{
    bst *ptr, *x, *y;
    ptr=(bst*)malloc(sizeof(bst));
    printf("Enter the info: ");
    scanf("%d",&ptr->info);
    ptr->lc=ptr->rc=NULL;
    if(root==NULL)
        root=ptr;
    else
    {
        x=root;
        while(x!=NULL)
        {
            y=x;
            if(ptr->info<x->info)
                x=x->lc;
            else
                x=x->rc;
        }
        if(ptr->info<y->info)
            y->lc=ptr;
        else
            y->rc=ptr;
    }
    return root;
}
int main()
{
    int ans=1;
    bst *root=NULL;
    for(int i=1;i<=5;i++)
        root=create(root);
    displayInorder(root);
}