#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Global Variable
char stack[50];
int top = -1;
// Function to Push Elements into Stack
void push(char ch)
{
    stack[++top] = ch;
}
char pop()
{
    return stack[top--];
}
void convert(char exp[])
{
    int l, i, j = 0;
    char infix[20];
    strrev(exp);
    l = strlen(exp);
    for (i = 0; i < 50; i++)
    {
        stack[i] = '\0';
    }
    printf("\nThe Infix Expression is: ");
    for (i = 0; i < l; i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
            push(exp[i]);
        else
        {
            infix[j++] = exp[i];
            infix[j++] = pop();
        }
    }
    infix[j] = exp[top--];
    strrev(infix);
    puts(infix);
}

int main()
{
    char exp[50];
    printf("\nEnter the Postfix Expression: ");
    gets(exp);
    convert(exp);
    return 0;
}