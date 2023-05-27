#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
	int info;
	struct node *lc,*rc;
};
typedef struct node bin_tree;
void create(bin_tree *root)
{
	char ans;
	bin_tree *ptr;
	printf("\nDo you want to create the left child of %d? ",root->info);
	fflush(stdin);
	scanf("%c",&ans);
	if(ans=='Y' || ans=='y')
	{
		ptr=(bin_tree*)malloc(sizeof(bin_tree));
		printf("\nEnter the information for the left child: ");
		scanf("%d",&ptr->info);
		ptr->lc=ptr->rc=NULL;
		root->lc=ptr;
		create(root->lc);
	}
	else
		root->lc=NULL;
	printf("\nDo you want to create the right child of %d? ",root->info);
	fflush(stdin);
	scanf("%c",&ans);
	if(ans=='Y' || ans=='y')
	{
		ptr=(bin_tree*)malloc(sizeof(bin_tree));
		printf("\nEnter the information for the right child: ");
		scanf("%d",&ptr->info);
		ptr->lc=ptr->rc=NULL;
		root->rc=ptr;
		create(root->rc);
	}
	else
		root->rc=NULL;
}

void preorder(bin_tree *root)
{
	if(root==NULL)
		return;
	printf("%d ",root->info);
	preorder(root->lc);
	preorder(root->rc);
}

void inorder(bin_tree *root)
{
	if(root==NULL)
		return;
	inorder(root->lc);
	printf("%d ",root->info);
	inorder(root->rc);
}

void postorder(bin_tree *root)
{
	if(root==NULL)
		return;
	postorder(root->lc);
	postorder(root->rc);
	printf("%d ",root->info);
}

int count_print_leaves(bin_tree *root)
{
    if(!root)
        return 0;
    if(!root->lc && !root->rc)
    {
        printf("%d ",root->info);
        return 1;
    }
    return count_print_leaves(root->lc)+count_print_leaves(root->rc);
}

int search(bin_tree *root, int x)
{
    if(!root)
        return 0;
    if(root->info==x)
        return 1;
    return search(root->lc,x) || search(root->rc,x);
}

int maximum(bin_tree *root)
{
    if(!root)
        return INT_MIN;
    int maxi=root->info;
    int left=maximum(root->lc);
    int right=maximum(root->rc);
    if(left>maxi)
        maxi=left;
    if(right>maxi)
        maxi=right;
    return maxi;
}

int minimum(bin_tree *root)
{
    if(!root)
        return INT_MAX;
    int mini=root->info;
    int left=minimum(root->lc);
    int right=minimum(root->rc);
    if(left<mini)
        mini=left;
    if(right<mini)
        mini=right;
    return mini;
}

int main()
{
	bin_tree *root=NULL,*ptr;
	int ch;
	printf("\nenter the information for the root: ");
	ptr=(bin_tree*)malloc(sizeof(bin_tree));
	scanf("%d",&ptr->info);
	ptr->lc=ptr->rc=NULL;
	root=ptr;
	create(root);
	while(1)
	{
		printf("\n***MENU***");
		printf("\n1. Preorder\n2. Inorder\n3. Postorder\n4. Count And Print Leaves\n5. Search a node\n6. Find maximum and minium node\n7. Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: preorder(root);
					break;
			case 2: inorder(root);
					break;
			case 3: postorder(root);
					break;
			case 4: int x=count_print_leaves(root);
                    printf("\nTotal leaf nodes = %d",x);
                    break;
            case 5: int val;
                    printf("\nEnter the node to be searched: ");
                    scanf("%d",&val);
                    if(search(root,val))
                        printf("\nNode is present");
                    else
                        printf("\nNode is absent");
                    break;
            case 6: int maxi=maximum(root);
                    int mini=minimum(root);
                    printf("\nMaximum node value is: %d",maxi);
                    printf("\nMinimum node value is: %d",mini);
                    break;
            case 7: exit(0);
		}
	}
}

