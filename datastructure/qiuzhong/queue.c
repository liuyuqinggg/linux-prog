#include<stdio.h>
#include<stdlib.h>

#include"queue.h"

queue *qu_create()
{
    queue *sq;
    sq = malloc(sizeof(*sq));
    if(sq == NULL)
        return NULL;
    sq->head = 0;
    sq->tail = 0;

    return sq;
}

int qu_isempty(queue *sq)
{
    if(sq->tail == sq->head)
        return 0;

    return 1;
}

int qu_isfull(queue *sq)
{
    if((sq->tail + 1) % MAXSIZE == sq->head)
        return 0;
    return 1;
}

int qu_enqueue(queue *sq,datatype *data)
{
    if(qu_isfull(sq) == 0)
        return -1;

    sq->tail = (sq->tail + 1) % MAXSIZE;
    sq->data[sq->tail] = *data;
    return 0;
    
}

int qu_dequeue(queue *sq,datatype *data)
{
    if(qu_isempty(sq) == 0)
        return -1;
    *data = sq->data[(sq->head + 1) % MAXSIZE];
    sq->head = (sq->head + 1) % MAXSIZE;
    return 0;
}

void qu_travel(queue *sq){
    if(qu_isempty(sq) == 0)
        return ;
    
    int i = (sq->head + 1) % MAXSIZE;

    while(i != sq->tail)
    {
        printf("%d ",sq->data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("%d \n",sq->data[i]);
    
}

void qu_clear(queue *sq)
{
    sq->head = sq->tail;
}

void qu_destroy(queue *sq)
{
    free(sq);
}