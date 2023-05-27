#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *lc,*rc;
};
typedef struct node bst;
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
    int i;
	bin_tree *root=NULL,*ptr;
	printf("\nEnter the information for the root: ");
	ptr=(bin_tree*)malloc(sizeof(bin_tree));
	scanf("%d",&ptr->info);
	ptr->lc=ptr->rc=NULL;
	root=ptr;
	create(root);
}