#ifndef LLIST_H__
#define LLIST_H__

#define LLIST_FORWARD 1
#define LLIST_BACKWARD 2

typedef void llist_op(const void *);
typedef int llist_cmp(const void *,const void *);

struct llist_node_st
{
   void *data;
   struct llist_node_st *prev;
   struct llist_node_st *next;
};

typedef struct 
{
    int size;
    struct llist_node_st head;
} LLIST;

LLIST *llist_create(int size);

int llist_insert(LLIST *l, const void *data, int mode);

void *llist_find(LLIST *l, const void *key,llist_cmp *cmp);

int llist_delete(LLIST *l,const void *key,llist_cmp *cmp);

int llist_fetch(LLIST *l,const void *key,llist_cmp *cmp, void *data);

void llist_travel(LLIST *l,llist_op *);

void llist_destroy(LLIST *l);




#endif