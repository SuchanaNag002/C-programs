#include<stdio.h>
#include<stdlib.h>
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
int balanced(bin_tree *root)
{
    if(!root)
        return 0;
    int lh=balanced(root->lc);
    if(lh==-1)
        return -1;
    int rh=balanced(root->rc);
    if(rh==-1)
        return -1;
    if(abs(lh-rh)>1)
        return -1;
    if(lh>rh)
        return 1+lh;
    else
        return 1+rh;

}
int main()
{
	bin_tree *root = NULL, *ptr;
	int ans=1,x;
	printf("\nenter the information for the root: ");
	ptr = (bin_tree *)malloc(sizeof(bin_tree));
	scanf("%d", &ptr->info);
	ptr->lc = ptr->rc = NULL;
	root = ptr;
	create(root);
    if(balanced(root)==-1)
        printf("\nUnbalanced tree");
    else
        printf("\nBalanced tree");
}