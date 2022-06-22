#include <stdio.h>
#include <stdlib.h>

#include "sqstack.h"

void compute(sqstack *snum, datatype *op)
{
    datatype n1,n2,n;
    st_pop(snum,&n2);
    st_pop(snum,&n1);

    switch (*op)
    {
    case '+':
       n = n1 + n2;
        break;
    case '-':
       n = n1 - n2;
        break;
    case '*':
       n = n1 * n2;
        break;
    case '/':
       n = n1 / n2;
        break;
    
    default:
        exit(1);
    }

    st_push(snum,&n);
}

int get_prio(int op)
{
    switch (op)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;
    
    default:
        exit(1);
    }
}

void deal_bracket(sqstack *snum,sqstack *sop)
{
    datatype old_op;
    st_top(sop,&old_op);

    while(old_op != '(')
    {
        st_pop(sop,&old_op);
        compute(snum,&old_op);
        st_top(sop,&old_op);
    }

    st_pop(sop,&old_op);
}

void deal_op(sqstack *snum,sqstack *sop, int op)
{

    int old_op;
    if(st_isempty(sop) || op == '(')
    {
        st_push(sop,&op);
        return;
    }

    st_top(sop,&old_op);

    if(get_prio(op) > get_prio(old_op))
    {
        st_push(sop,&op);
        return;
    }

    while(get_prio(op) <= get_prio(old_op))
    {
        st_pop(sop,&old_op);
        compute(snum,&old_op);
        if(st_isempty(sop))
            break;

        st_top(sop,&old_op);
    }
    
    st_push(sop,&op);
}

int main(int argc, char const *argv[])
{

    int i = 0;  //要记得初始化
    char str[] = "(3+4)*5-6+3*2-1";
    sqstack *snum, *sop;
    int value = 0;
    int flag = 0;

    snum = st_create();
    if(snum == NULL)
        exit(1);
        
    sop = st_create();
    if(sop == NULL)
        exit(1);

    while(str[i] != '\0')
    {
        if(str[i] >'0' && str[i] < '9')
        {
            value = value * 10 +  str[i] - '0';

            flag = 1;
        }
        else // is op
        {
            if(flag)
            {
                st_push(snum,&value);
                flag = 0;
                value = 0;
            }
            if(str[i] == ')')
            {
                deal_bracket(snum,sop);
            }
            else
            {
                deal_op(snum,sop,str[i]);
            }
        }
        
        i++;
    }

    if(flag)
        st_push(snum,&value);

    int old_op;

    while (!st_isempty(sop))
    {
        st_pop(sop, &old_op);
        compute(snum,&old_op);
    }

    st_pop(snum, &value);
    printf("%d\n",value);

    st_destroy(snum);
    st_destroy(sop);

    return 0;
}
