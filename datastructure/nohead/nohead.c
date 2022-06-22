#include <stdio.h>
#include <stdlib.h>
#include "nohead.h"
list list_insert(list l, stu *s)
{
	node *newnode = malloc(sizeof(node));
	if(newnode == NULL)
		return NULL;
	newnode->data = *s;
	
	newnode->next = l;
	l = newnode;
	return l;

}

void list_show(list l)
{
	node *cur;
	for(cur = l; cur; cur = cur->next)
		print(cur->data);
}

void print(stu cur)//传指针应该更好
{
	printf("id: %d, name: %s, math: %d, chinese: %d \n",cur.id,cur.name,cur.math,cur.chinese);
}

int list_delete(list *l)
{
	if(*l == NULL)
		return -1;

	node *cur = *l;	

	*l = (*l)->next;
	free(cur);

	return 0;
}


int list_find(list l, int id,stu *s)
{
	if(l == NULL)
		return -1;
	
	for(node *cur = l; cur; cur = cur->next)
		if(cur->data.id == id)
		{
			*s = cur->data;
			return 0;
		}

	return -2;

}
