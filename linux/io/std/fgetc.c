#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    if(argc < 2)
    {
        fprintf(stderr,"Usage...\n");
        exit(1);
    }

    FILE *fp;
    int count = 0;

    fp = fopen(argv[1],"r");
    if(fp == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    while (fgetc(fp) != EOF)
    {
        count++;
    }
    printf("count:%d\n",count);
    fclose(fp);
    

    return 0;
}
