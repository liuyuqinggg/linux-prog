#include <stdio.h>
#include <stdlib.h>
#define NUM 8

struct node
{
    int data;
    struct node *next;
};

struct node *create(int num)
{
    struct node *head, *newnode, *cur;
    int i = 1;

    head = malloc(sizeof(struct node));
    head->data = i;
    head->next = head;
    cur = head;

    i++;

    for (; i <= num; i++) 
    {
        newnode = malloc(sizeof(struct node));
        newnode->data = i;
        
        newnode->next = head;
        cur->next = newnode;
        cur = newnode;
    }

    return head;
    
}

void show(struct node *l)
{
    struct node *node = l;
    while(node)
    {
        printf("%d ", node->data);
        if(node->next == l)//赋值不能写成等号
            break;
        else
            node = node->next;
    }    
    printf("\n");
}


void kill(struct node **l,int n)
{
    struct node *node = *l, *pre;
    int i = 1;

    while(node && node->next != node)
    {
        while(i < n)
        {
            pre = node;
            node = node->next;
            i++;
        }

        pre->next = node->next;
        printf("%d ",node->data);
        free(node);
        node = pre->next;

        i=1;
    }

    *l = node;

    printf("\n");
        
        
}


void kill1(struct node **l,int n)//自己一开始写的
{
    struct node *node = *l, *pre;
    int i = 1;

    while(node && node->next != node)
    {
        if(i % n == 0)
        {
            // tmp = node;
            pre->next = node->next;
            printf("%d ",node->data);
            free(node);
            node = pre->next;
        } else
        {
            pre = node;
            node = node->next;
        }
        i++;
    }

    *l = node;

    printf("\n");
        
        
}


int main(int argc, char const *argv[])
{
    struct node *l;
    l = create(NUM);

    show(l);

    // kill1(&l,3);
    kill(&l,3);

    show(l);

    return 0;
}
