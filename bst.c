#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int info;
    struct Node *left, *right;
};
typedef struct Node bst;
void maximum(bst *root)
{
    if(!root)
        return;
    if(!root->right)
        printf("Maximum is: %d",root->info);
    maximum(root->right);
}
bst *create(bst *root)
{
    bst *ptr,*x,*y;
    ptr=(bst*)malloc(sizeof(bst));
    printf("Enter the info: ");
    scanf("%d",&ptr->info);
    ptr->left=ptr->right=NULL;
    if(root==NULL)
        root=ptr;
    else
    {
        x=root;
        while(x!=NULL)
        {
            y=x;
            if(ptr->info<x->info)
                x=x->left;
            else
                x=x->right;
        }
        if(ptr->info<y->info)
            y->left=ptr;
        else
            y->right=ptr;
    }
    return root;
}
int main()
{

    int ans, x, f, value, count;
    bst *root = NULL, *maxi, *mini;
    while (1)
    {
        printf("\n1. Add a node\n2. Inorder display\n3. Preorder display\n4. Postorder display\n5. Search");
        printf("\n6.Find maximum element\n7. Find minimum element\n8. Count leaves");
        printf("\nEnter your choice:");
        scanf("%d", &ans);
        switch (ans)
        {
        case 1:
            root = create(root);
            break;
        // case 2:
        //     inorder(root);
        //     break;
        // case 3:
        //     preorder(root);
        //     break;
        // case 4:
        //     postorder(root);
        //     break;
        // case 5:
        //     printf("Enter the value to be searched: ");
        //     scanf("%d", &value);
        //     f = search(root, value);
        //     if (f)
        //         printf("Element present\n");
        //     else
        //         printf("Element absent\n");
        //     break;
        case 6:
            maximum(root);
            break;
        // case 7:
        //     minimum(root);
        //     break;
        // case 8:
        //     count = count_leaves(root);
        //     printf("\nCount:%d\n", count);
        //     break;
        }
        printf("\nDo you want to continue?(1/0)?: ");
        scanf("%d", &x);
        if (x == 0)
            break;
    }
}