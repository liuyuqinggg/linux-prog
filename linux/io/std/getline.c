#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//建议自己实现一个getline getline_free
int main(int argc, char const *argv[])
{

    FILE *fp;
    char *linebuf;
    size_t linesize;
    if(argc < 2)
    {
        fprintf(stderr,"Usage---\n");
        exit(1);
    }

    fp = fopen(argv[1],"r");
    if(fp == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    while (1)
    {
        if(getline(&linebuf,&linesize,fp) < 0)
        {
            break;
        }

        printf("%ld\n",strlen(linebuf));
        printf("%ld\n",linesize);
    }
    


    fclose(fp);
    return 0;
}
