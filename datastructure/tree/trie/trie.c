#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FNAME "/home/yuqing/linux-programming/c/datastructure/tree/trie/log"
#define DESC_SIZE 256
#define KEY_SIZE 256
#define BUFSIZE  512

struct node_st
{
    struct node_st *ch[26];
    char des[DESC_SIZE];
};

int get_word(FILE *fp, char *key, char *desc)
{
    char buf[BUFSIZE];
    char *retp;
    int i,j;
   
    retp = fgets(buf,BUFSIZ,fp);
    

    if(retp == NULL)
    {
        return -1;
    }

    // puts(buf);
            
    for (i = 0; i < KEY_SIZE - 1 && buf[i] != ':'; i++)
    {
        key[i] = buf[i];
    }
    key[i] = '\0';
    i++;

    for (j = 0; j < DESC_SIZE - 1 && buf[i] != '\0'; j++,i++)
    {
        desc[j] = buf[i];
    }
    desc[j] = '\0';
    return 0;
    
    
}

struct node_st *newnode()
{
    struct node_st *node;

    node = malloc(sizeof *node);
    if(node == NULL)
        return NULL;

    node->des[0] = '\0';

    for (int i = 0; i < 26; i++)
    {
        node->ch[i] = NULL;
    }
    return node;
    
}

int insert(struct node_st **root,char key[],char des[])
{
    if(*root == NULL)
    {
        *root = newnode();
        if(*root == NULL)
            return -1;
    }

    if(*key == '\0')
    {
        strcpy((*root)->des,des);
        return 0;
    }
    return insert(&((*root)->ch[(*key) - 'a']),key + 1,des);
        
}

char *find(struct node_st *root,char *key)
{
    if(root == NULL)
        return NULL;
    
    if(*key == '\0')
        return root->des;
    return find(root->ch[*key - 'a'],key + 1);
}

int main(int argc, char const *argv[])
{

    struct node_st *tree = NULL;
    FILE *fp ;
    int ret;
    char des[DESC_SIZE], key[KEY_SIZE],*res;

    fp = fopen(FNAME,"r");
    if(fp == NULL)
    {
        fprintf(stderr,"fopen():error\n");
        exit(1);
    }

    while (1)
    {
        ret = get_word(fp,key,des);
        if(ret == -1)
            break;
        else
        {
            puts(key);
            puts(des);
            insert(&tree,key,des);
        }
    }
    

    res = find(tree,"donkey");
    if(res == NULL)
        printf("cant find\n");
    else
        printf("\nfind \n%s\n",res);
    return 0;
}
