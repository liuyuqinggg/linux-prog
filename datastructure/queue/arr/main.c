#include<stdio.h>
#include<stdlib.h>

#include"queue.h"

int main(int argc, char const *argv[])
{
    queue *sq;
    int arr[] = {1,2,3,4,5};
    sq = qu_create();

    for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        qu_enqueue(sq,&arr[i]);
    }
    
    qu_travel(sq);

    int val;

    while(qu_dequeue(sq,&val) == 0)
        printf("%d ", val);

    printf("\n");


    qu_destroy(sq);
    return 0;
}
