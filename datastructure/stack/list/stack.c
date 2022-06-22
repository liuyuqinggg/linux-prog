#include<stdio.h>
#include<stdlib.h>

#include"stack.h"

static int always_match(const void *p,const void *q)
{
    return 0;
}

STACK *stack_create(int initsize)
{
    llist_create(initsize);
}

int stack_push(STACK *ptr,const void *data)
{
    return llist_insert(ptr,data,LLIST_FORWARD);
}

int stack_pop(STACK *ptr,void *data)
{
    return llist_fetch(ptr,(void *)0,always_match,data);
}

void stack_destroy(STACK *ptr)
{
    llist_destroy(ptr);
}