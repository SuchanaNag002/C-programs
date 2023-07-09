#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
char stack[size];
int top=-1;
void reverse(char exp[], int l)
{
    for(int i=0; i<l/2; i++)
    {
        char ch=exp[i];
        exp[i]=exp[l-i-1];
        exp[l-i-1]=ch;
    }
}
void push(char ch)
{
    stack[++top]=ch;
}
char pop()
{
    return stack[top--];
}
void convert(char postfix[])
{
    int i,j=0,l;
    char infix[size];
    l=strlen(postfix);
    reverse(postfix,l);
    for (i = 0; i < size; i++)
        stack[i] = '\0';
    for(i=0;i<l;i++)
    {
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
            push(postfix[i]);
        else
        {
            infix[j++]=postfix[i];
            if(top>=0)
                infix[j++]=pop();
        }
    }
    reverse(infix,l);
    printf("The infix expression is: %s\n",infix);
}
int main()
{
    char postfix[size];
    printf("Enter the postfix expression: ");
    gets(postfix);
    convert(postfix);
}