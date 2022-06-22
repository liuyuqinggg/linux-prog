#include <stdio.h>
#include <stdlib.h>

#include "sqstack.h"


sqstack *st_create()
{
    sqstack * new;
    new  = malloc(sizeof(sqstack));
    if(new == NULL)
        return NULL;
    
    new->top = -1;
    return new;
}

int st_isempty(sqstack *st)
{
    return (st->top == -1);
}

int st_isfull(sqstack *st)
{
    return (st->top == (SIZE -1));
}

int st_push(sqstack *st,type *data)
{
    if(st_isfull(st))
        return -2;
    
    st->data[++st->top] = *data;
    return 0;
    
}

int st_pop(sqstack *st,type *data)
{
    if(st_isempty(st))
        return -1;

    *data = st->data[st->top--];
    return 0;
}

int st_top(sqstack *st,type *data)
{
    if(st_isempty(st))
        return -1;

    *data = st->data[st->top];
    return 0;
}

void st_destroy(sqstack *st)
{
    free(st);
}

void st_travel(sqstack *st)
{
    for (int i = 0; i <= st->top; i++)
    {
        printf("%d ",st->data[i]);
    }
    printf("\n");
}
