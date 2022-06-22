#include<stdio.h>
#include<stdlib.h>

#include"queue.h"

QUEUE *queue_create(int initsize)
{
    QUEUE *new;
    new  = llist_create(initsize);
    return new;
}

static int always_match(const void *p,const void *q)
{
    return 0;
}

int queue_enqueue(QUEUE *ptr,const void *data)
{
    return llist_insert(ptr, data, LLIST_BACKWARD);
}

int queue_dequeue(QUEUE *ptr,void *data)
{
    return llist_fetch(ptr,(void *)0, always_match, data);
}

void queue_destroy(QUEUE *ptr)
{
    llist_destroy(ptr);
}