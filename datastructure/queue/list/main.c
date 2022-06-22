#include<stdio.h>
#include<stdlib.h>

#include"queue.h"

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
    int res = 0;
    QUEUE *qu = queue_create(sizeof(struct score_st));
    if(qu == NULL)
        exit(1);

    for (int i = 0; i < 7; i++)
    {
        tmp.id = i;
        snprintf(tmp.name,NAMESIZE,"std%d",i);
        tmp.math = rand()%100;
        tmp.chinese = rand()%100;

        res = queue_enqueue(qu,&tmp);

        if(res)
            exit(1);
    }
        
    while(1)
    {
        res = queue_dequeue(qu,&tmp);

        if(res == 0)
            print_s(&tmp);
        else
            break;
    }
    
    queue_destroy(qu);
    return 0;
}
