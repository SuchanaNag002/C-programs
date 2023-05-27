#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include<stdio.h>
char opnds[100][100], oprs[100];
int topr = -1, topd = -1;
void pushd(char *opnd)
{
    strcpy(opnds[++topd], opnd);
}
char *popd()
{
    return (opnds[topd--]);
}

void pushr(char opr)
{
    oprs[++topr] = opr;
}
char popr()
{
    return (oprs[topr--]);
}
int empty(int t)
{
    if (t == 0)
        return (1);
    return (0);
}

void main()
{
    char prfx[100], ch, str[100], op1[100], op2[100], opr[2];
    int i = 0, k = 0, opndcnt = 0;
    printf("Enter a prefix expression: ");
    gets(prfx);
    while ((ch = prfx[i++]) != '\0')
    {
        if (isalnum(ch))
        {
            str[0] = ch;
            str[1] = '\0';
            pushd(str);
            opndcnt++;
            if (opndcnt >= 2)
            {
                strcpy(op2, popd());
                strcpy(op1, popd());
                strcpy(str, "(");
                strcat(str, op1);
                ch = popr();
                opr[0] = ch;
                opr[1] = '\0';
                strcat(str, opr);
                strcat(str, op2);
                strcat(str, ")");
                pushd(str);
                opndcnt -= 1;
            }
        }
        else
        {
            pushr(ch);
            if (opndcnt == 1)
                opndcnt = 0; 
        }
    }
    if (!empty(topd))
    {
        strcpy(op2, popd());
        strcpy(op1, popd());
        strcpy(str, "(");
        strcat(str, op1);
        ch = popr();
        opr[0] = ch;
        opr[1] = '\0';
        strcat(str, opr);
        strcat(str, op2);
        strcat(str, ")");
        pushd(str);
    }
    printf("Infix Expression: %s",opnds[topd]);

}