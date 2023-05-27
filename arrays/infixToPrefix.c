#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 100
char st[100];
int top = -1;
void reverse(char s[])
{
    int n=strlen(s),i;
    for(i=0;i<n/2;i++)
	{
		char temp=s[i];
		s[i]=s[n-i-1];
		s[n-i-1]=temp;
	}
}
void push(char ch)
{
    st[++top] = ch;
}
char pop()
{
    return st[top--];
}
int prec(char ch)
{
    if (ch == '(')
        return 0;
    else if (ch == ')')
        return 1;
    else if (ch == '+' || ch == '-')
        return 2;
    else if (ch == '*' || ch == '/' || ch == '%')
        return 3;
    else if (ch == '^')
        return 4;
}
void main()
{
	char infix[size],prefix[size];
	char ch;
	st[++top]=')';
	printf("Enter the infix expression: ");
	gets(infix);
    reverse(infix);
	int i=0,k=0;
    while((ch=infix[i++])!='\0')
    {
        if(ch==')')
            push(ch);
        else if(isalpha(ch))
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
    reverse(prefix);
    printf("The prefix expression is: %s\n",prefix);
}