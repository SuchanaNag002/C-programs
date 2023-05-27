#include<stdio.h>
#include<stdlib.h>
int search(int *arr, int elt, int n)
{
    int i;
    for(i=0;i<n;i++)
        if(arr[i]==elt)
            return i;
    return -1;
}
void postorderTraversal(int *in, int *pre, int n)
{
    int root=search(in,pre[0],n);
    //left subtree
    if(root!=0)
        postorderTraversal(in,pre+1,root);
    //right subtree
    if(root!=n-1)
        postorderTraversal(in+root+1,pre+root+1,n-root-1);
    printf("%d ",pre[0]);
}
int main()
{
    int n,i;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    int *inorder=(int*)malloc(n*sizeof(int));
    int *preorder=(int*)malloc(n*sizeof(int));
    printf("Enter the inorder traversal: ");
    for(i=0;i<n;i++)
        scanf("%d",&inorder[i]);
    printf("Enter the preorder traversal: ");
    for(i=0;i<n;i++)
        scanf("%d",&preorder[i]);
    printf("The postorder traversal is: ");
    postorderTraversal(inorder,preorder,n);
}