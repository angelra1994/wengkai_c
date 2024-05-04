# include <stdio.h>

int main()
{
	printf("23+24=%d\n", 23+34);
	printf("23-24=%d\n", 23-34);
	printf("23*24=%d\n", 23*34);
	printf("23/24=%d\n", 23/34);
	// c 语言中 % 是格式指定符，用于printf()函数中指定后续参数的输出格式
	// 打印出 % , 需要用 %% 表示，作为转义
	printf("23%%24=%d\n", 23%34);
	return 0;

}
	
	
