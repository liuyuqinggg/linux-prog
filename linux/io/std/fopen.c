#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(){

	FILE *fp = NULL;

	int i = 0;

	while (1)
	{
		fp = fopen("tmp","r");

		if(fp == NULL)
		{
			// fprintf(stderr,"fopen() failed, %d\n",errno);
			// perror("fopen()");

			fprintf(stderr,"fopen():%s\n",strerror(errno));
			break;
		}
		i++;
	}

	puts("ok");
	printf("%d\n",i);

	fclose(fp);
	exit(0);
	

}
