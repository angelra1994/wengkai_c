#include <stdio.h>
#include <stdbool.h>


int main()
{
	/**
	 * 条件运算符的优先级高于赋值运算符，但是低于其他运算符号
	 * a++ >= 1 && b-- > 2 ? a : b
	 * 条件运算符是自右向左结合的
	 * w < x ? x + w : x < y ? x : y
	 * 建议是别用嵌套的条件运算符，需要从右到左计算出所有的表达式的结果
	 */
	int a = -1;
	if (a>0 && a++ > 1) {
		printf("ok\n");
	}
	printf("a=%d\n", a);
	return 0;
}




