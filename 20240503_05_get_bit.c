# include <stdio.h>
/*
while 方式获取一个整数的位数
*/
int main()
{
	int x;
	int n = 0;
	scanf("%d", &x);
	
	// x=0 的 场景
	n++;
	x /= 10;

	while(x > 0) {
		n++;
		x /= 10;
	}
	printf("%d\n", n);
	return 0;

}



