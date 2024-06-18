#include <stdio.h>

/**
 * int divide(int a, int b, int *result);
 * 
 * @return int , 如果除法成功，返回1；否则返回0
 */
int divide(int, int, int *);

int main(int argc, char const *argv[])
{
    int a=5;
	int b=2;
	int c;
	
	/**
	 * 
	 函数返回运算的状态，结果通过指针返回。状态用于处理异常场景
	 常用套路是让函数返回特殊的不属于有效范围内的值表示出错：-1或0，在文件操作有很多类似例子
	 但是当任何数值都是有效的可能结果时，就得分开返回。java/c++ 采用异常机制解决
	 * 
	 */
	if (divide(a, b, &c)) {
		printf("%d/%d=%d\n", a, b, c);
	}
	return 0;
}

int divide(int a, int b, int *result) {
	int ret = 1;
	if ( b==0 ) {
		ret = 0;
	} else {
		*result = a/b;
	}
	return ret;
}

