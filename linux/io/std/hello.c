#include <stdio.h>
//#include <stdlib.h>

//void main(void);
//void main(int argc, char **argv);
//int main(int argc, char ** argv);


int main(){
	int *p = NULL;
	int i;
	p = malloc(sizeof(int));
	if(p == NULL)
		return -1;

	printf("hello world!\n");

	exit(0);

}
