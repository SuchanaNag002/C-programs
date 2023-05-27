#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *lc, *rc;
};
typedef struct node bst;
int count_leaves(bst *root)
{
    if (!root)
        return 0;
    if (!root->rc && !root->lc)
    {
        printf("%d ", root->info);
        return 1;
    }
    return count_leaves(root->lc) + count_leaves(root->rc);
}
int search(bst *root, int val)
{
    if (!root)
        return 0;
    if (root->info == val)
        return 1;
    search(root->lc, val) || search(root->rc, val);
}
void maximum(bst *root)
{
    if (!root)
        return;
    if (!root->rc)
        printf("%d", root->info);
    maximum(root->rc);
}
void minimum(bst *root)
{
    if (!root)
        return;
    if (!root->lc)
        printf("%d", root->info);
    minimum(root->lc);
}
void inorder(bst *root)
{
    if (!root)
        return;
    inorder(root->lc);
    printf("%d ", root->info);
    inorder(root->rc);
}
void preorder(bst *root)
{
    if (!root)
        return;
    printf("%d ", root->info);
    preorder(root->lc);
    preorder(root->rc);
}
void postorder(bst *root)
{
    if (!root)
        return;
    postorder(root->lc);
    postorder(root->rc);
    printf("%d ", root->info);
}
bst *create(bst *root)
{
    bst *ptr, *x, *y;
    ptr = (bst *)malloc(sizeof(bst));
    printf("Enter the info: ");
    scanf("%d", &ptr->info);
    ptr->lc = ptr->rc = NULL;
    if (root == NULL)
        root = ptr;
    else
    {
        x = root;
        while (x != NULL)
        {
            y = x;
            if (ptr->info < x->info)
                x = x->lc;
            else
                x = x->rc;
        }
        if (ptr->info < y->info)
            y->lc = ptr;
        else
            y->rc = ptr;
    }
    return root;
}
int main()
{

    int ans, x, value, count, flag=1;
    bst *root = NULL, *maxi, *mini;
    while (flag)
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
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            printf("Enter the value to be searched: ");
            scanf("%d", &value);
            if (search(root,value))
                printf("Element present\n");
            else
                printf("Element absent\n");
            break;
        case 6:
            maximum(root);
            break;
        case 7:
            minimum(root);
            break;
        case 8:
            count = count_leaves(root);
            printf("\nCount:%d\n", count);
            break;
        }
        printf("\nDo you want to continue?(1/0)?: ");
        scanf("%d", &flag);
    }
}