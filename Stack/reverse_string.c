#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 100
int top=-1;
void push(char *stack, char item)
{
    top=top+1;
    stack[top] = item;
}
char pop(char *stack)
{
    char x=stack[top];
    top--;
    return x;
}
void reverse(char *stack, char *str)
{
    int n=strlen(str),i;
    for(i=0;i<n;i++)
        push(stack,str[i]);
    for(i=0;i<n;i++)
        str[i]=pop(stack);
}
int main()
{
    char str[maxsize],stack[maxsize];
    printf("Enter the string: ");
    gets(str);
    reverse(stack,str);
    printf("Reversed string is: %s",str);
}