# include <stdio.h>
/*
在终端实现一个加法
*/
int main()
{
	int a,b;
	printf("请输入两个整数，计算二者之和\n");
	// scanf 
	scanf("%d  %d", &a, &b);
	printf("%d + %d = %d\n", a, b, a + b);
	printf("请输入两个整数，计算二者之差\n");

	scanf("%dx%d", &a, &b);
	printf("%d - %d = %d\n", a, b, a - b);
	
	return 0;

}
	
	
