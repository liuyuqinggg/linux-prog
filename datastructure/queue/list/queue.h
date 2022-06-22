#ifndef QUEUE_H__
#define QUEUE_H__
#include "llist.h"

typedef LLIST QUEUE;

QUEUE *queue_create(int initsize);

int queue_enqueue(QUEUE *, const void *);

int queue_dequeue(QUEUE *, void *);

void queue_destroy(QUEUE *q);

#endif