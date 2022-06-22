#include <stdio.h>
#include <stdlib.h>
#include <queue.h>

static struct node_st *tree = NULL;

struct score_st
{
    int id;
    char name[32];
    int math;
    int chinese;
};

struct node_st
{
    struct score_st data;
    struct node_st *left;
    struct node_st *right;
};

int insert(struct node_st **root,struct score_st *data)
{
    struct node_st *node;
    if((*root) == NULL)
    {
        node = malloc(sizeof *node);
        if(node == NULL)
            return -1;
        
        node->data = *data;
        node->left = NULL;
        node->right = NULL;

        *root = node;
        return 0;
    }

    if(data->id <= (*root)->data.id)
        return insert(&(*root)->left,data);
    else
        return insert(&(*root)->right,data);
}

struct score_st *find(struct node_st *root,int id)
{
    if(root == NULL)
        return NULL;

    if(id == root->data.id)
        return &root->data;

    if(id < root->data.id)
        return find(root->left,id);
    else
        return find(root->right,id);

}

void print_s(const void *record)
{
    const struct score_st *p = record;
    printf("%d %s %d %d\n",p->id,p->name,p->math,p->chinese);
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
    

    printf("%d\n",root->data.id);
    draw_(root->left,level + 1);


}

void draw(struct node_st *root)
{
    draw_(root,0);
    printf("-----------------------\n\n");
    // getchar();
}

static int get_num(struct node_st *root)
{
    if(root == NULL)
        return 0;

    return get_num(root->left) + 1 + get_num(root->right);
}

static struct node_st *find_min(struct node_st *root)
{
    if(root->left == NULL)
        return root;
    return find_min(root->left);
}

static struct node_st *find_max(struct node_st *root)
{
    if(root->right == NULL)
        return root;
    return find_max(root->right);
}

static void turn_left(struct node_st **root)
{
    struct node_st *cur = *root;

    *root = cur->right;
    cur->right = NULL;
    find_min(*root)->left = cur;
    // draw(*root);
}

static void turn_right(struct node_st **root)
{
    struct node_st *cur = *root;

    *root = cur->left;
    cur->left = NULL;
    find_max(*root)->right = cur;
    // draw(*root);
}

void balance(struct node_st **root)
{
    if(*root == NULL)
        return;
    int sub;
    while (1)
    {
        sub = get_num((*root)->left) - get_num((*root)->right);

        if(sub >= -1 && sub <=1)
            break;

        if(sub < -1)
            turn_left(root);
        else    
            turn_right(root);
    }
    balance(&(*root)->left);
    balance(&(*root)->right);
    
}

int delete(struct node_st **root,int id)
{
    struct node_st **node = root;
    struct node_st *cur;

    while ((*node) != NULL && (*node)->data.id !=id)
    {
        if(id < (*node)->data.id)
        node = &(*node)->left;
        else
        node = &(*node)->right;
    }
    
    if(*node == NULL)
        return -1;

    cur = *node;
    if(cur->left == NULL)
        *node = cur->right;
    else
    {
        *node = cur->left;
        find_max(cur->left)->right = cur->right;
    }

    free(cur);
    return 0;
}

void travel_pre(struct node_st *root)
{
    if(root == NULL)
        return;
    print_s(&root->data);
    travel_pre(root->left);
    travel_pre(root->right);

}

void travel_in(struct node_st *root)
{
    if(root == NULL)
        return;
    
    travel_in(root->left);
    print_s(&root->data);
    travel_in(root->right);

}

void travel_post(struct node_st *root)
{
    if(root == NULL)
        return;
    
    travel_post(root->left);
    travel_post(root->right);
    print_s(&root->data);

}

void travel_level(struct node_st *root)
{

    struct node_st *cur;
    int ret;
    if(root == NULL)
        return;
    QUEUE *qu = queue_create(sizeof(struct node_st *));
    if(qu == NULL)
        return ;

    queue_enqueue(qu,&root);

    while (1)
    {
        ret = queue_dequeue(qu,&cur);

        if(ret == -1)
            break;
        print_s(&cur->data);

        if(cur->left != NULL)
            queue_enqueue(qu,&cur->left);
        
        if(cur->right != NULL)
            queue_enqueue(qu,&cur->right);
    }
    

    
    queue_destroy(qu);

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

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,7,6,5,9,8,4};
    
    
    struct score_st tmp;

    for (int  i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {

        tmp.id = arr[i];
        snprintf(tmp.name,32,"stu%id",arr[i]);
        tmp.math = rand()%100;
        tmp.chinese = rand()%100;
        insert(&tree,&tmp);

    }

    int tmpid = 5;
    struct score_st *datap;

    // datap = find(tree,tmpid);

    // if(datap == NULL)
    //     printf("can't find\n");
    // else
    //     print_s(datap);

    draw(tree);

    balance(&tree);

    draw(tree);

    
    // delete(&tree,tmpid);
    travel_pre(tree);
    printf("-----------------------\n\n");
    travel_in(tree);
    printf("-----------------------\n\n");
    travel_post(tree);
    printf("-----------------------\n\n");
    travel_level(tree);
    destroy(&tree);
    draw(tree);
    return 0;
}
