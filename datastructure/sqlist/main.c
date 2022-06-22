#include <stdio.h>
#include <stdlib.h>

#include "sqlist.h"

int main()
{
	datatype arr[] = {11,22,34};
	datatype arr1[] = {11,33,44};
	sqlist *list;
	sqlist *list1;
//	list = 	sqlist_create();
	sqlist_create1(&list);
	sqlist_create1(&list1);
	if(list == NULL)
	{
		fprintf(stderr,"sqlist_create() failed!\n");
		exit(1);
	}

	for(int i = 0,err; i < sizeof(arr)/sizeof(*arr); i++)
		if((err = sqlist_insert(list,0,&arr[i])) != 0)
		{
			if(err == -1)
				fprintf(stderr,"The array is full.\n");
			else if(err == -2)
				fprintf(stderr,"the pos you choose is wrong.\n");
			else
				fprintf(stderr,"Error!\n");
			
			exit(1);
		}
	for(int i = 0,err; i < sizeof(arr1)/sizeof(*arr1); i++)
		if((err = sqlist_insert(list1,0,&arr1[i])) != 0)
		{
			if(err == -1)
				fprintf(stderr,"The array is full.\n");
			else if(err == -2)
				fprintf(stderr,"the pos you choose is wrong.\n");
			else
				fprintf(stderr,"Error!\n");
			
			exit(1);
		}
	sqlist_display(list);
	sqlist_display(list1);
//	sqlist_delete(list, 0);
	list = union_(list,list1);
	sqlist_display(list);
	sqlist_destory(list);
	exit(0);
}
