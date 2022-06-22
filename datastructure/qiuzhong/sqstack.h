#ifndef SQSTACK_H__
#define SQSTACK_H__

#define SIZE 15

typedef int type;

typedef struct stack
{
    type data[SIZE];
    int top;
}sqstack;

sqstack *st_create();

int st_isempty(sqstack *);
int st_isfull(sqstack *);
int st_push(sqstack *,type *);
int st_pop(sqstack *,type *);
int st_top(sqstack *,type *);

void st_destroy(sqstack *);

void st_travel(sqstack *);




#endif