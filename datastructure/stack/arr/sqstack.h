#ifndef SQSTACK_H__
#define SQSTACK_H__

#define MAXSIZE 5

typedef int datatype;

typedef struct stack
{
    datatype data[MAXSIZE];
    int top;
}sqstack;

sqstack *st_create();

int st_isempty(sqstack *);
int st_isfull(sqstack *);
int st_push(sqstack *,datatype *);
int st_pop(sqstack *,datatype *);
int st_top(sqstack *,datatype *);

void st_destroy(sqstack *);

void st_travel(sqstack *);




#endif