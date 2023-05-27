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
void image(bin_tree *root)
{
    if(!root)
        return;
    image(root->lc);
    image(root->rc);
    bin_tree *temp=root->lc;
    root->lc=root->rc;
    root->rc=temp;
}
int maxi(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int heightOfTree(bin_tree *root)
{
    if(!root)
        return 0;
    int lh= heightOfTree(root->lc);
    int rh= heightOfTree(root->rc);
    return 1+maxi(lh,rh);
}
void level_traversal(bin_tree *root, int level)
{
    if(!root)
        return;
    if(level==1)
        printf("%d ",root->info);
    else
    {
        level_traversal(root->lc,level-1);
        level_traversal(root->rc,level-1);
    }
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
    int height=heightOfTree(root);
    printf("Level order traversal of original tree:\n");
    for(i=1; i<=height; i++)
    {
        printf("Level %d: ",i);
        level_traversal(root,i);
        printf("\n");
    }
    image(root);
    printf("Level order traversal of mirror image tree:\n");
    for(i=1; i<=height; i++)
    {
        printf("Level %d: ",i);
        level_traversal(root,i);
        printf("\n");
    }
}