#include <stdio.h>
#include <stdlib.h>
#define maxsize 100
struct treeStructure
{
	int info;
	struct treeStructure *lc, *rc;
};
typedef struct treeStructure Tree;
struct stackStrcuture
{
	int size, top;
	Tree **array;
};
typedef struct stackStrcuture Stack;
Stack *createStack()
{
	Stack *stack=(Stack*)malloc(sizeof(Stack));
	stack->size=maxsize;
	stack->top=-1;
	stack->array=(Tree**)malloc(maxsize*sizeof(Tree*));
	return stack;
}
int isFull(Stack *stack)
{
	return stack->top-1 == stack->size;
}
int isEmpty(Stack *stack)
{
	return stack->top==-1;
}
void push(Stack *stack, Tree *node)
{
	if(isFull(stack))
		return;
	stack->array[++stack->top]=node;
}
Tree *pop(Stack *stack)
{
	if(isEmpty(stack))
		return NULL;
	return stack->array[stack->top--];
}
Tree *peek(Stack *stack)
{
	if(isEmpty(stack))
		return NULL;
	return stack->array[stack->top];
}
void preorder(Tree *root)
{
	Tree *temp = root;
	Stack *stack = createStack();
	int flag = 1;
	printf("\nThe non-recursive preorder traversal is: ");
	while (flag) // Loop run until temp is null and stack is empty
	{
		if (temp)
		{
			printf("%d ", temp->info);
			push(stack, temp);
			temp = temp->lc;
		}
		else
		{
			if (!isEmpty(stack))
			{
				temp = pop(stack);
				temp = temp->rc;
			}
			else
				flag = 0;
		}
	}
}
void inorder(Tree *root)
{
	Tree *temp = root;
	Stack *stack = createStack();
	int flag = 1;
	printf("\nThe non-recursive inorder traversal is: ");
	while (flag) // Loop run until temp is null and stack is empty
	{
		if (temp)
		{
			push(stack, temp);
			temp = temp->lc;
		}
		else
		{
			if (!isEmpty(stack))
			{
				temp = pop(stack);
				printf("%d ", temp->info);
				temp = temp->rc;
			}
			else
				flag = 0;
		}
	}
}
void postorder(Tree *root)
{
	Tree *temp = root;
	Stack *stack = createStack();
	int flag = 1;
	printf("\nThe non-recursive postorder traversal is: ");
	do
    {
        while (temp)
        {
            if (temp->rc)
                push(stack, temp->rc);
            push(stack, temp);
 
            temp = temp->lc;
        }
        temp = pop(stack);
        if (temp->rc && peek(stack) == temp->rc)
        {
            pop(stack); 
            push(stack, temp); 
            temp = temp->rc; 
            
        }
        else 
        {
            printf("%d ", temp->info);
            temp = NULL;
        }
    } 
	while (!isEmpty(stack));
}
void create(Tree *root)
{
	char ans;
	Tree *ptr;
	printf("\nDo you want to create the left child of %d? ", root->info);
	fflush(stdin);
	scanf("%c", &ans);
	if (ans == 'Y' || ans == 'y')
	{
		ptr = (Tree *)malloc(sizeof(Tree));
		printf("\nEnter the information for the left child: ");
		scanf("%d", &ptr->info);
		ptr->lc = ptr->rc = NULL;
		root->lc = ptr;
		create(root->lc);
	}
	else
		root->lc = NULL;
	printf("\nDo you want to create the right child of %d? ", root->info);
	fflush(stdin);
	scanf("%c", &ans);
	if (ans == 'Y' || ans == 'y')
	{
		ptr = (Tree *)malloc(sizeof(Tree));
		printf("\nEnter the information for the right child: ");
		scanf("%d", &ptr->info);
		ptr->lc = ptr->rc = NULL;
		root->rc = ptr;
		create(root->rc);
	}
	else
		root->rc = NULL;
}
int main()
{
	Tree *root = NULL, *ptr;
	int ans=1,x;
	printf("\nenter the information for the root: ");
	ptr = (Tree *)malloc(sizeof(Tree));
	scanf("%d", &ptr->info);
	ptr->lc = ptr->rc = NULL;
	root = ptr;
	create(root);
	while(ans)
	{
		printf("\n1. Inorder traversal\n2. Postorder traversal\n3. Preorder traversal\nEnter your choice: ");
		scanf("%d",&x);
		switch(x)
		{
			case 1: inorder(root);
					break;
			case 2: preorder(root);
					break;
			case 3: postorder(root);
					break;
			default: printf("\nInvalid choice");
					 break;	
		}
		printf("\n\nDo you want to continue?(1/0): ");
		scanf("%d",&ans);
	}
}