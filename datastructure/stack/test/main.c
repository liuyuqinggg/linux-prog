#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#define NAMESIZE 32

struct score_st
{
    int id; 
    char name[NAMESIZE];
    int math;
    int chinese;
};

void print_s(const void *record)
{
    const struct score_st *p = record;
    printf("%d %s %d %d\n",p->id,p->name,p->math,p->chinese);
}


int main(int argc, char const *argv[])
{
    struct score_st tmp;
    int res;

    STACK *st = stack_create(sizeof(tmp));
    if(st == NULL)
        exit(1);
  
     for (int i = 0; i < 7; i++)
    {
        tmp.id = i;
        snprintf(tmp.name,NAMESIZE,"std%d",i);
        tmp.math = rand()%100;
        tmp.chinese = rand()%100;
        res = stack_push(st,&tmp);
        if(res)
            exit(1);
    }


    while(stack_pop(st,&tmp) == 0)
    {
        print_s(&tmp);
    }

    printf("\n");

    return 0;
}
