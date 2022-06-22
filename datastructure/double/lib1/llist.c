#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include"llist.h"


LLIST *llist_create(int initsize)
{
    LLIST *new;
    new = malloc(sizeof(*new));
    if(new == NULL)
        return NULL;
    new->size = initsize;
    new->head.data = NULL;
    new->head.prev = &new->head;
    new->head.next = &new->head;

    return new;
}

int llist_insert(LLIST *l, const void *data, int mode)
{
    struct llist_node_st *new = malloc(sizeof(struct llist_node_st));
    if(new == NULL)
        return -1;
    
    new->data = malloc(l->size);
    if(new->data == NULL)
        return -2;
    memcpy(new->data,data,l->size);

    if(mode == LLIST_FORWARD)
    {
        new->prev = &l->head;
        new->next = l->head.next;
        
    }else if (mode == LLIST_BACKWARD)
    {
        new->prev = l->head.prev;
        new->next = &l->head;
    }else
    {
        return -3;
    }
    new->prev->next = new; 
    new->next->prev = new; 

    return 0;
    
}

static struct llist_node_st *find_(LLIST *l, const void *key,llist_cmp *cmp)
{
    struct llist_node_st *cur, *next;
    for (cur = l->head.next; cur != &l->head; cur = cur->next)
    {
        if(cmp(key,cur->data) == 0)
            break;
    }
    return cur;
}

void *llist_find(LLIST *l, const void *key,llist_cmp *cmp)
{
    struct llist_node_st *res = find_(l, key,cmp);
    return res->data;

}

int llist_delete(LLIST *l,const void *key,llist_cmp *cmp)
{
    struct llist_node_st *node = find_(l,key,cmp);
    if(node == &l->head)
        return -1;
    node->prev->next = node->next;
    node->next->prev = node->prev;

    free(node->data);
    free(node);

    return 0;
}

int llist_fetch(LLIST *l,const void *key,llist_cmp *cmp, void *data)
{
    struct llist_node_st *node = find_(l,key,cmp);
    if(node == &l->head)
        return -1;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    if(data != NULL)
        memcpy(data,node->data,l->size);
    free(node->data);
    free(node);

    return 0;
}

void llist_travel(LLIST *l, llist_op *print_s)
{
    struct llist_node_st *cur = l->head.next;

    for (; cur != &l->head; cur = cur->next)
    {
        print_s(cur->data);
    }
    
}

void llist_destroy(LLIST *l)
{
    struct llist_node_st *cur, *next;
    for (cur = l->head.next; cur != &l->head; cur = next)
    {
        next = cur->next;
        free(cur->data);
        free(cur);
    }

    free(l);
}