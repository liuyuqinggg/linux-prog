#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1024

int main(int argc, char const *argv[])
{
    FILE *src,*des;
    char buf[MAXSIZE];

    if(argc < 3)
    {
        fprintf(stderr,"Usage:%s <src_file> <des_file>\n",argv[0]);
        exit(1);
    }
    src = fopen(argv[1],"r");//使用满足需求的最低权限即可，这里不要用r+模式
    if(src == NULL)
    {
        perror("fopen():");
        exit(1);
    }

    des = fopen(argv[2],"w");
    if(des == NULL)
    {
        fclose(src);
        perror("fopen():");
        exit(1);
    }

    int n;

    while ((n = fread(buf,1,MAXSIZE,src)) > 0)//会在buf后加上 '\0'
    {
        fwrite(buf,1,n,des);  //会在去除buf '\0' 
    }
    

    fclose(src);
    fclose(des);
    return 0;
}
