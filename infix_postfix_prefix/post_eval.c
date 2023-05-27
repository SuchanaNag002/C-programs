#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define size 100
int st[size];
int top=-1;
void push(char ch)
{
	st[++top]=ch;
}
int pop()
{
	return st[top--];
}
void main()
{
	char postfix[size];
	char ch;
	st[++top]='(';
	printf("Enter the postfix expression: ");
	gets(postfix);
	int i=0,x,res;
	for(i=0;postfix[i]!='\0';i++)
	{
		ch=postfix[i];
		if(isalpha(ch))
		{
			printf("Enter the value of %c: ",ch);
			scanf("%d",&x);
			push(x);
		}
		else
		{
			int op2=pop();
			int op1=pop();
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
