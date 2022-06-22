#include <stdio.h>
#include <stdlib.h>
#include "nohead.h"

int main()
{
	list l = NULL;
	stu tmp;
	for(int i = 0; i < 7; i++)
	{
		tmp.id = i;
		snprintf(tmp.name,NAMESIZE,"stu%d",i);
		tmp.math = rand() % 100;
		tmp.chinese = rand() % 100;
	
		l = list_insert(l,&tmp);//习惯传二级指针，这里不是传二级指针；
	}
	list_show(l);
	printf("\n\n");
	list_delete(&l);
	list_show(l);
	stu s;
	int ret = list_find(l,3,&s);
	printf("\n\n");
	if(ret == 0)
		print(s);
	
	exit(0);
}
