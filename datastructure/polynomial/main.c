#include <stdio.h>
#include <stdlib.h>

struct item
{
    int coef;
    int exp;
};

typedef struct poly
{
    struct item x;
    struct poly *next;
} polylist;

int create_poly(int a[][2], int n,  polylist **pl)
{
    *pl = malloc(sizeof(polylist));
    if(*pl == NULL)
        return -1;

    polylist *tmp;
    for (int i = 0; i < n; i++)
    {
        tmp = malloc(sizeof(polylist));
        if(tmp == NULL)
            return -1;
        
        tmp->x.coef = a[i][0];
        tmp->x.exp = a[i][1];
        tmp->next = NULL;

        tmp->next = (*pl)->next; 
        (*pl)->next = tmp;
        
    }

    return 0;
    
}

void show(polylist *pl)
{
    while (pl->next)
    {
        if(pl->next->x.coef != 0 )
            printf("%dx^%d ",pl->next->x.coef,pl->next->x.exp);

        pl = pl->next;
    }
    printf("\n");
    
}

int main()
{
    int a[3][2] = {{3,1},{2,3},{4,5}};
    polylist *pl;

    create_poly(a,3,&pl);
    //create-poly();

    show(pl);
    // show();

    // unio();

    // show();
}