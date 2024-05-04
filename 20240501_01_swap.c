# include <stdio.h>
/*
交换两个数
*/
int main() {
	int a, b, t;
	a = 5;
	b = 6;
	
	printf("交换前, a=%d,b=%d\n", a, b);
	t = a;
	a = b;
	b = t;
	printf("交换后, a=%d,b=%d\n", a, b);
	
	t = 10;
	printf("t++=%d\n", t++);
	printf("t=%d\n", t);
	printf("++t=%d\n", ++t);
	printf("t=%d\n", t);
	return 0;

}



