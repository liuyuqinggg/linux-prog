#ifndef QUEUE_H__
#define QUEUE_H__

typedef  int datatype;
#define MAXSIZE 6

typedef struct node_st
{
    datatype data[MAXSIZE];
    int head,tail;
}queue;

queue *qu_create();

int qu_isempty(queue *);
int qu_isfull(queue *q);

int qu_enqueue(queue *,datatype *);

int qu_dequeue(queue *,datatype *);

void qu_travel(queue *);

void qu_clear(queue *);

void qu_destroy(queue *);


#endif