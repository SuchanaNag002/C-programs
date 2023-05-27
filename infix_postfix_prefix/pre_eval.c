#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define size 100
int st[100];
int top=-1;
void push(char ch)
{
	st[++top]=ch;
}
int pop()
{
	return st[top--];
}
int prec(char ch)
{
	if(ch=='(')
		return 0;
	else if(ch==')')
		return 1;
	else if(ch=='+'||ch=='-')
		return 2;
	else if(ch=='*' || ch=='/' || ch=='%')
		return 3;
	else if(ch=='^')
		return 4;
	else
		return -1;
}
void main()
{
	char prefix[size];
	char ch;
	st[++top]=')';
	printf("Enter the prefix expression: ");
	gets(prefix);
	int i,k,n,x,res;
	n=strlen(prefix);
	for(i=n-1;i>=0;i--)
	{
		ch=prefix[i];
		if(isalpha(ch))
		{
			printf("Enter the value of %c: ",ch);
			scanf("%d",&x);
			push(x);
		}
		else
		{
			int op1=pop();
			int op2=pop();
			switch(ch)
			{
				case '+':
					res=op1+op2;
					break;
				case '-':
					res=op1-op2;
					break;
				case '*':
					res=op1*op2;
					break;
				case '%':
					res=op1%op2;
					break;
				case '/':
					res=op1/op2;
					break;
				case '^':
					res=op1^op2;
					break;
			}
			push(res);
		}
	}
	printf("Answer: %d\n",pop());
}
