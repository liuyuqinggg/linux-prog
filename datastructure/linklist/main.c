#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	int arr[] = {11,2,33,4,55,6};
	list *list = list_create();
	
	if(list == NULL)
	{
		exit(1);
	}


	for(int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		if(list_order_insert(list,&arr[i]) != 0)
			{
				fprintf(stderr,"insert index error\n");
				exit(i);
			}
	}
	
	list_display(list);
	int value = 2;
	//list_delete(list,&value);
	list_delete_at(list,2,&value);
	list_display(list);
	printf("%d\n",value);
	list_destroy(list);

	return 0;

}
