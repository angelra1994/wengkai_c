#include <stdio.h>
#include <stdbool.h>

void cheer(int i) 
{
	printf("cheer %d\n", i);
}

void swap(int x, int y);

int main()
{
	/**
	 * 可能会出现warning: implicit conversion from 'double' to 'int' changes from 2.4 to 2
	 * 调用函数时候给的值与参数的类型不匹配是C语言传统上最大的漏洞
	 * 编译器总是悄悄把类型转换好，但是这可能不是期望的
	 */
	cheer(2.4);
	
	int a,b;
	a = 5;
	b = 6;
	/**
	 * C语言在调用函数时候，永远只能传值给函数
	 * 每一个函数都有自己的变量空间，参数也位于这个独立的空间里面
	 */
	swap(a, b);
	printf("a=%d,b=%d", a, b);
	return 0;
}


void swap(int x, int y) 
{
	int t = x;
	x = y;
	y = t;
	
}


