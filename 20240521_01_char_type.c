#include <stdio.h>


int main()
{

	char c;
	char d;
	c = 1;
	d = '1';
	//c=1, d=49
	printf("c=%d, d=%d\n",c, d);
	
	// printf 和 scanf 里 可以用 %c 来输入输出字符
	// 输入 '1' 这个字符给 char c
	scanf("%c", &c);
	// c='1', c=49
	printf("c='%c', c=%d\n", c, c);

	scanf("%d", &c);  // 以整数的形式读入 50
	// c='2', c=50
	printf("c='%c', c=%d\n", c, c);
	
	int i;
	printf("==========");
	/**
	 * 12B
	 * i=12, c='B', c=66
	 * 
	 * 12     1
	 * i=12, c='1', c=49
	 */
	scanf("%d %c", &i, &c);
	printf("i=%d, c='%c', c=%d\n", i, c, c);
	/**
	 * 12    1
	 * i=12, c=' ', c=32
	 */
	scanf("%d%c", &i, &c);   // 读完了整数，第一个非整数的字符给%c
	printf("i=%d, c='%c', c=%d\n", i, c, c);
	
	/**
	 * a+'a'-'A' 可以把以大字母变成小写
	 * a+'A'-'a' 可以把以小字母变成大写
	 */
	return 0;
}




