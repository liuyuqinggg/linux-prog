#include<stdio.h>
#include<stdlib.h>

/*
    缓冲区的作用：大多数情况下是好事，合并系统调用

    行缓冲：换行的时候刷新，满了的时候刷新， 强制刷新（标准输出是这样的）
    全缓冲：满了的时候刷新，强制刷新（默认，只要不是终端设备）
    无缓冲：如stderr,需要立即输出的内容

    setvbuf
 
*/

int main(int argc, char const *argv[])
{
    printf("before");
    fflush(NULL);
    while(1);
    printf("after\n");
    return 0;
}
