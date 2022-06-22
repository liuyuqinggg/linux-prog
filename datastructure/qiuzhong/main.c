#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "sqstack.h"
#define NUM_BALL 28

int check(queue *q)
{
    int i = (q->head + 1) % MAXSIZE;

    while (i != q->tail)
    {
        if(q->data[i] > q->data[(i+1) % MAXSIZE])
            return 0;
        i = (i+1) % MAXSIZE;
    }

    return 1;
    
}

int main(int argc, char const *argv[])
{
    
    queue *q;
    sqstack *st_min, *st_fivemin, *st_hour;

    q = qu_create();
    if(q == NULL)
        exit(1);

    st_min = st_create();
    if(st_min == NULL)
        exit(1);

    st_fivemin = st_create();
    if(st_fivemin == NULL)
        exit(1);

    st_hour = st_create();
    if(st_hour == NULL)
        exit(1);

    for (int i = 1; i <= NUM_BALL; i++)
    {
        qu_enqueue(q,&i);
    }

    qu_travel(q);


    int out,in, time = 0;

    while (1)
    {
        qu_dequeue(q,&out);
        time++;

        if(st_min->top != 3)
        {
            st_push(st_min,&out);
        }else
        {
            while (!st_isempty(st_min))
            {
                st_pop(st_min,&in);
                qu_enqueue(q,&in);
            }

            if(st_fivemin->top != 10)
            {
                st_push(st_fivemin,&out);
            }else
            {
                while (!st_isempty(st_fivemin))
                {
                    st_pop(st_fivemin,&in);
                    qu_enqueue(q,&in);
                }

                if(st_hour->top != 10)
                {
                    st_push(st_hour,&out);
                }else
                {
                    while (!st_isempty(st_hour))
                    {
                        st_pop(st_hour,&in);
                        qu_enqueue(q,&in);
                    }
                    qu_enqueue(q,&out);

                    if(check(q))
                        break;
                }
                
            }
            
        }
    }
    

    
    printf("%d\n",time);
    qu_travel(q);

    qu_destroy(q);
    st_destroy(st_min);
    st_destroy(st_fivemin);
    st_destroy(st_hour);

    return 0;
}
