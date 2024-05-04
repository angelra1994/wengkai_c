# include <stdio.h>

int main()
{
	printf("hello ziyuan\n")
	
	;
	
	
	
	// 逗号表达式
	int i,j,k,x;
	i=1,j=2,k=3;
	printf("i=%d\n", i);
	printf("j=%d\n", j);
	printf("k=%d\n", k);
	
	i=1,(j=2,k=3);
	printf("i=%d\n", i);
	printf("j=%d\n", j);
	printf("k=%d\n", k);
	
	x=i=4,j=6,k=8;
	printf("x=%d\n", x);
	x=(i=4,(j=6,k=8));
	printf("x=%d\n", x);
	x=8*2,x*4;
	printf("x=%d\n", x);
	x=(8*2,x*4);
	printf("x=%d\n", x);
	return 0;
}
