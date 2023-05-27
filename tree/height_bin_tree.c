#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *lc,*rc;
};
typedef struct node bin_tree;
int maxi(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int height(bin_tree *root)
{
    if(!root)
        return 0;
    int lh= height(root->lc);
    int rh= height(root->rc);
    return 1+maxi(lh,rh);
}
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
    int len=height(root);
    printf("\nThe height of the tree is: %d",len);
}