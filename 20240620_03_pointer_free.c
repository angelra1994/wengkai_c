#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{


    void *p;
    printf("p=%p(%%p)\n", p);

    p=malloc(100);
	printf("malloc(100), p=%p(%%p)\n", p); 
    p++;
    printf("p++, p=%p(%%p)\n", p);   // 76929
    free(p);
	int i;
	p = &i;
	printf("&i, p=%p(%%p)\n", p);
	free(p);
	// free(p);
	free(NULL);
    free(1);
    return 0;
}
