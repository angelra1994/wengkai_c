#include <stdio.h>
#include <stdbool.h>


int main()
{
	int a = -1;
	if (a>0 && a++ > 1) {
		printf("ok\n");
	}
	// a=-1, && 右边的逻辑运算被短路了
	printf("a=%d\n", a);
	return 0;
}




