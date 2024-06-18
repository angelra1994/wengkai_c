#include <stdio.h>
#include <stdbool.h>

/**
 * C的编译器是自上而下顺序分析代码
 * 
 * 1. 声明 -> 函数原型
 * 其他
 * 2. 定义
 * 
 */

/**
 * 编译器需要知道参数类型，返回值类型
 */
//void sum(int begin, int end);
void sum(int, int);

int max(int a, int b) {
	int ret;
	if (a > b) {
		ret = a;
	} else {
		ret = b;
	}
	return ret;
}


void cheer() 
{
	printf("cheer\n");
}


void sum(int begin, int end) 
{
	int i;
	int sum = 0;
	for(i=begin;i<=end;i++) {
		sum += i;
	}
	printf("从%d到%d的和是%d\n", begin, end, sum);
}


int main()
{
	int a,b,c;
	a = 5;
	b = 6;
	c = max(10, 12);
	c = max(a, b);
	c = max(c, 23);
	printf("%d\n", max(a, b));
	cheer();
	sum(1, 10);
	sum(2, 10);
	return 0;
}





