#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *src,*des;
    int ch; //char有无符号是未定义行为

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

    while (1)
    {
        ch = fgetc(src);
        if(ch == EOF)
            break;
        fputc(ch,des);  
    }
    

    fclose(src);
    fclose(des);
    return 0;
}
