# include <stdio.h>
/*
do while 方式获取一个整数的位数
*/
int main()
{
	int x;
	int n = 0;
	scanf("%d", &x);
	
	do {
		n++;
		x /= 10;
	} while(x > 0);

	printf("%d\n", n);
	return 0;
}



