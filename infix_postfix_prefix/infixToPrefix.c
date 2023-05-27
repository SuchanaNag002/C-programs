#include<stdio.h>
#include<ctype.h>
#include<string.h>
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
	char infix[size],prefix[size];
	char ch;
	st[++top]=')';
	printf("Enter the infix expression: ");
	gets(infix);
	int i,k,n;
	n=strlen(infix);
	//printf("%d\n",n);
	for(i=0;i<n/2;i++)
	{
		char temp=infix[i];
		infix[i]=infix[n-i-1];
		infix[n-i-1]=temp;
	}
	i=k=0;
	while((ch=infix[i++])!='\0')
	{
		if(ch==')')
			push(ch);
		else if(isalnum(ch))
			prefix[k++]=ch;
		else if(ch=='(')
		{
			while(st[top]!=')')
				prefix[k++]=pop();
			pop();
		}
		else
		{
			while(prec(ch)<prec(st[top]))
				prefix[k++]=pop();
			push(ch);
		}
	}
	while(st[top]!=')')
		prefix[k++]=pop();
	prefix[k]='\0';
	n=strlen(prefix);
	for(i=0;i<n/2;i++)
	{
		char temp=prefix[i];
		prefix[i]=prefix[n-i-1];
		prefix[n-i-1]=temp;
	}
	printf("The postfix expression is: %s\n",prefix);
}
