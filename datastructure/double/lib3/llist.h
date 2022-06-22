#ifndef LLIST_H__
#define LLIST_H__

#define LLIST_FORWARD 1
#define LLIST_BACKWARD 2

typedef void llist_op(const void *);
typedef int llist_cmp(const void *,const void *);

struct llist_node_st
{
   struct llist_node_st *prev;
   struct llist_node_st *next;
   char data[0];
};

typedef struct llist_head
{
    int size;
    struct llist_node_st head;

    int (*llist_insert)(struct llist_head *l, const void *data, int mode);
    void *(*llist_find)(struct llist_head *l, const void *key,llist_cmp *cmp);
    int (*llist_delete)(struct llist_head *l,const void *key,llist_cmp *cmp);
    int (*llist_fetch)(struct llist_head *l,const void *key,llist_cmp *cmp, void *data);
    void (*llist_travel)(struct llist_head *l,llist_op *);

} LLIST;

LLIST *llist_create(int size);



void llist_destroy(LLIST *l);




#endif