#include <stdio.h>
#include <stdlib.h>
#define maxsize 100
int top=-1,postIndex=0;
void push(int *arr, int val)
{
    int x;
    if ((top + 1) >= maxsize)
        printf("\nStack overflow!!\n");
    else
    {
        top=top+1;
        arr[top] = val;
    }
}
int pop(int *arr)
{
    if (top == -1)
        printf("\nUnderflow error.Empty stack!!!\n");
    else
        return arr[top--];
}
int search(int *in, int elt, int n)
{
    int i;
    for(i=0;i<n;i++)
        if(in[i]==elt)
            return i;
    return -1;
}
void preorderCalc(int *in, int *post, int inStart, int inEnd, int *stack, int n)
{
    if(inStart>inEnd)
        return;
    //Find index of next item in postorder traversal in.
    int val=post[postIndex];
    int inIndex=search(in,val,n);
    postIndex--;
    preorderCalc(in,post,inIndex+1,inEnd,stack,n);
    preorderCalc(in,post,inStart,inIndex-1,stack,n);
    push(stack,val);
}
void preorderTraversal(int *in, int *post, int n)
{
    int n1=n;
    postIndex=n1-1;
    int *stack = (int *)malloc(maxsize * sizeof(int));
    preorderCalc(in, post, 0, n1-1, stack, n);
    while(top!=-1)
        printf("%d ",pop(stack));
}
int main()
{
    int n,i;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    int *inorder=(int*)malloc(n*sizeof(int));
    int *postorder=(int*)malloc(n*sizeof(int));
    printf("Enter the inorder traversal: ");
    for(i=0;i<n;i++)
        scanf("%d",&inorder[i]);
    printf("Enter the postorder traversal: ");
    for(i=0;i<n;i++)
        scanf("%d",&postorder[i]);
    preorderTraversal(inorder, postorder, n);
}