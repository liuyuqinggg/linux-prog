#include <stdio.h>
#include <stdlib.h>
#include "list.h"


list *list_create()
{
	list *me;
	me = malloc(sizeof(*me));
	if(me == NULL)
	{
		return NULL;
	}
	me->next == NULL;
	return me;
}
int list_insert_at(list *me,int i,datatype *data)
{
	if(i < 0)
		return -1;
	
	list *l = me, *newnode;
	int j = 0;
	while(j < i && l != NULL)
	{
		l = l->next;
		j++;
	}

	if(l)			
	{
		newnode = malloc(sizeof(*newnode));
		if(newnode == NULL)
		{
			printf("malloc error\n");
			exit(1);
		}	
		newnode->data = *data;
		newnode->next = l->next;
		l->next =newnode;
		return 0;
	}
	
	return -2;
	
}

int list_order_insert(list *me, datatype *data)
{
	list *p = me, *q;

	while(p->next && p->next->data < *data)
	{
		p = p->next; 
	}

	q = malloc(sizeof(*q));
	if(q == NULL)
		return -1;

	q->data = *data;
	q->next = p->next;
	p->next = q;

	return 0;
	
	
}

int list_delete_at(list *me,int i, datatype *data)
{
	int j = 0;
	list *p = me, *q;

	if(i < 0)
		return -1;

	*data = -1;
	while(j < i && p)
	{
		p = p->next;
		j++;
	}

	if(p)
	{
		q = p->next;
		p->next = q->next;
		*data = q->data;
		free(q);
	}else
		return -2;
}

int list_delete(list *me,datatype *data)
{
	list *p = me,*q;
	while(p->next && p->next->data != *data)	
		p = p->next;

	if(p->next == NULL)
		return -1;
	else
	{
		q = p->next;
		p->next = q->next;
		free(q);
	}
}

int list_isempty(list *me)
{
	if(me->next == NULL)
		return 0;
	return 1;
}


void list_display(list *me)
{
	list *node  = me->next;
	while(node)
	{
		printf("%d  ",node->data);
		node = node->next;
	}
	printf("\n");
}

void list_destroy(list *me)
{
	list *node = me->next, *next;
	
	while(node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	
	free(me);

}


