#include <stdio.h>
#include <stdlib.h>

#include "sqstack.h"

int main(int argc, char const *argv[])
{

    int arr[] = {1,2,3,4,5};
    int ret;
    int data;
    sqstack *st = st_create();
    if(st == NULL)
        exit(1);
    for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
       ret = st_push(st,&arr[i]);
       if(ret)
            exit(1);
    }

    st_travel(st);
    printf("\n");

    st_top(st,&data);
    printf("%d \n",data);

    while(st_pop(st,&data) == 0)
    {
        printf("%d ",data);
    }

    printf("\n");

    return 0;
}
