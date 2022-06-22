#ifndef NOHEAD_H__
#define NOHEAD_H__


#define NAMESIZE 32


typedef struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
} stu;

typedef struct node_st
{
	struct score_st data;
	struct node_st *next;
}node, *list;
list list_insert(list l,stu *s);
void list_show(list l);
int list_delete(list*);
int list_find(list, int id,stu *);

void print(stu);

#endif
