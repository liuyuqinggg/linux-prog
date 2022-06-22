#include <stdio.h>
#include <stdlib.h>
#include <queue.h>

#define FNAME "/home/yuqing/linux-programming/c/datastructure/tree/save_load/save"
static struct node_st *tree = NULL;


struct node_st
{
    int data;
    struct node_st *left;
    struct node_st *right;
};

int insert(struct node_st **root,int data)
{
    struct node_st *node;
    if((*root) == NULL)
    {
        node = malloc(sizeof *node);
        if(node == NULL)
            return -1;
        
        node->data = data;
        node->left = NULL;
        node->right = NULL;

        *root = node;
        return 0;
    }

    if(data <= (*root)->data)
        return insert(&(*root)->left,data);
    else
        return insert(&(*root)->right,data);
}



void draw_(struct node_st *root,int level)
{
    if(root == NULL)
        return;

    draw_(root->right,level + 1);
    for (int i = 0; i < level; i++)
    {
       printf("    ");
    }
    

    printf("%c\n",root->data);
    draw_(root->left,level + 1);


}

void draw(struct node_st *root)
{
    draw_(root,0);
    printf("-----------------------load\n\n");
    // getchar();
}


void destroy(struct node_st **root)
{

    struct node_st *cur;
    int ret;
    if(*root == NULL)
        return;
    QUEUE *qu = queue_create(sizeof(struct node_st *));
    if(qu == NULL)
        return ;
    queue_enqueue(qu,root);

    while (1)
    {
        ret = queue_dequeue(qu,&cur);

        if(ret == -1)
            break;

        if(cur->left != NULL)
            queue_enqueue(qu,&cur->left);
        
        if(cur->right != NULL)
            queue_enqueue(qu,&cur->right);

        free(cur);
        
    }
    
    *root = NULL;
    
    queue_destroy(qu);

}

int save_(struct node_st *root,FILE *fp)
{
    fputc('(',fp);
    if(root == NULL)
    {
        fputc(')',fp);
        return 0;
    }

    fputc(root->data,fp);

    save_(root->left,fp);
    save_(root->right,fp);

    fputc(')',fp);

}

int save(struct node_st *root,const char *path)
{
    FILE *fp;
    fp = fopen(path,"w");
    if(fp == NULL)
        return -1;

    save_(tree,fp);
    return 0;
}

struct node_st *load_(FILE *fp)
{
    int c;
    c = fgetc(fp);
    struct node_st *tmp;

    if(c != '(')
    {
        fprintf(stderr,"fgetc():error\n");
        exit(1);
    }

    c = fgetc(fp);
    if(c == ')')
        return NULL;

    tmp = malloc(sizeof *tmp);
    if(tmp == NULL)
        exit(1);

    tmp->data = c;
    tmp->left = load_(fp);
    tmp->right = load_(fp);

    c = fgetc(fp);

    return tmp;
    
}

struct node_st *load(const char *path)
{
    FILE *fp;
    struct node_st *root;

    fp = fopen(path,"r");
    if(fp == NULL)
        return NULL;

    root = load_(fp);

    fclose(fp);
    return root;
}

int main(int argc, char const *argv[])
{
    
    tree = load(FNAME);

    draw(tree);

    destroy(&tree);
    
    return 0;
}
