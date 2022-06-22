#include<stdio.h>
#include<stdlib.h>
#include"list.h"

#define NAMESIZE 32
struct score_st
{
    int id;
    char name[NAMESIZE];
    struct list_head node;
    int math;
    int chinese;
};

void print_s(struct score_st *p)
{
    printf("%d %s %d %d\n",p->id,p->name,p->math,p->chinese);
}


int main(int argc, char const *argv[])
{
    struct score_st *tmp;
    struct score_st *p;
    struct list_head *cur;
    LIST_HEAD(head);

    for (int i = 0; i < 7; i++)
    {

        tmp = malloc(sizeof(struct score_st));
        tmp->id = i;
        snprintf(tmp->name,NAMESIZE,"std%d",i);
        tmp->math = rand()%100;
        tmp->chinese = rand()%100;

        // print_s(tmp);
        list_add(&tmp->node,&head);
    }
    
    // printf("%p \n",&head);
    // printf("%p \n",head.next);
    // printf("%p \n",head.next->next);

    list_for_each(cur,&head)
    {
        p = list_entry(cur,struct score_st ,node);
        print_s(p);
    }


    return 0;
}
