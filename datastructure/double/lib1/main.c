#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "llist.h"
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

int id_cmp(const void *key,const void *data)
{
    const int *id = key;
    const struct score_st *std = data;
    if(*id == std->id)
        return 0;
    return -1;
}

int name_cmp(const void *key,const void *data)
{
    const char *name = key;
    const struct score_st *std = data;
    return strcmp(name,std->name);
}

int main(int argc, char const *argv[])
{
    LLIST *handler;
    struct score_st tmp;
    int res = 0;

    handler = llist_create(sizeof(struct score_st)); //头结点的size属性

    for (int i = 0; i < 7; i++)
    {
        tmp.id = i;
        snprintf(tmp.name,NAMESIZE,"std%d",i);
        tmp.math = rand()%100;
        tmp.chinese = rand()%100;
        // res = llist_insert(handler,&tmp,LLIST_FORWARD);
        res = llist_insert(handler,&tmp,LLIST_BACKWARD);
        if(res)
            exit(1);
    }
    
    
    llist_travel(handler,print_s);

    printf("--------------------------\n");

    struct score_st *std;
    int id = 2;
    char *name = "std3";
    // std = llist_find(handler,&id,id_cmp);
    std = llist_find(handler,name,name_cmp);
    if(std != NULL)
        print_s(std);
    else    
        printf("can not find\n");

    printf("--------------------------\n");

    res = llist_delete(handler,name,name_cmp);

    if(res == 0)
        llist_travel(handler,print_s);
    else
        printf("can not delete\n");

         printf("--------------------------\n");

    res = llist_fetch(handler,&id,id_cmp,std);
     if(res == 0)
    {
        llist_travel(handler,print_s);
         printf("--------------------------\n");
        print_s(std);
    }
    else
        printf("can not fetch\n");


    llist_destroy(handler);
    return 0;
}
