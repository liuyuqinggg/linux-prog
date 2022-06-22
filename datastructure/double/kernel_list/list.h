#ifndef LINUX_LIST_H__
#define LINUX_LIST_H__

struct list_head
{
    struct list_head *prev;
    struct list_head *next;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name)   struct list_head name = LIST_HEAD_INIT(name)



static inline void __list_add(struct list_head *new, struct list_head *prev, struct list_head *next)
{
    next->prev = new; 
    new->next = next;
    new->prev = prev;
    prev->next = new;
}


static inline void list_add(struct list_head *new, struct list_head *head)
{   
    // printf("%p \n",new);
    // printf("%p \n",head);
    // printf("%p \n",head->next);
    // printf("-------------");
    __list_add(new, head, head->next);
}

#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

 #define offsetof(TYPE, MEMBER)  ((size_t)&((TYPE *)0)->MEMBER)


#define container_of(ptr, type, member) ({              \
    void *__mptr = (void *)(ptr);                   \
    ((type *)(__mptr - offsetof(type, member))); })



#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)




#endif