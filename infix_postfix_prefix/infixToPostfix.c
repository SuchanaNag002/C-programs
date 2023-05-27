#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define size 100
char st[100];
int top=-1;
void push(char ch)
{
	st[++top]=ch;
}
char pop()
{
	return st[top--];
}
int prec(char ch)
{
	if(ch==')')
		return 0;
	else if(ch=='(')
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
	char infix[size],postfix[size];
	char ch;
	st[++top]='(';
	printf("Enter the infix expression: ");
	gets(infix);
	int i=0,k=0;
	while((ch=infix[i++])!='\0')
	{
		if(ch=='(')
			push(ch);
		else if(isalnum(ch))
			postfix[k++]=ch;
		else if(ch==')')
		{
			while(st[top]!='(')
				postfix[k++]=pop();
			pop();
		}
		else
		{
			while(prec(ch)<=prec(st[top]))
				postfix[k++]=pop();
			push(ch);
		}
	}
	while(st[top]!='(')
		postfix[k++]=pop();
	postfix[k]='\0';
	printf("The postfix expression is: %s\n",postfix);
}
