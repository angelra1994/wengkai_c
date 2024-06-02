# include <stdio.h>

int main()
{
	/**
	 * 整数
	 *    char -> short -> int -> long -> long long(C99)
	 * 浮点数
	 * 	  float -> double -> long double(C99)
	 * 逻辑
	 *    bool(C99)
	 * 指针
	 * 自定义类型
	 * 
	 * 输入输出时的格式化: %d, %hd, %ld, %lf
	 * 表示的范围: char < short < int < float < double
	 * 内存中占据的大小: 1个字节到16个字节
	 * 内存中的表达形式: 二进制数(补码), 编码(不是自然二进制数, 如float, double)
	 * 运算符 sizeof。计算出某个类型或变量在内存中所占据的字节数 sizeof(int), sizeof(i)
	 * ps sizeof 是一个关键字，不参与运算
	 * 
	 * int/long: 取决与编译器(CPU), 通常的意义是”1个字“ (寄存器的宽度)
	 * 
	 */
	
	int a = 5;
	printf("%lld\n", sizeof(1));
	printf("%lld\n", sizeof(a++));
	printf("a=%d\n", a);
	printf("%lld\n", sizeof(++a));
	printf("a=%d\n", a);	
	printf("sizeof(++a+1.0)=%lld\n", sizeof(++a+1.0));
	printf("a=%d\n", a);
	
	printf("sizeof(int)=%lld\n", sizeof(int));
	printf("sizeof(double)=%lld\n", sizeof(double));
	printf("sizeof(long double)=%lld\n", sizeof(long double));
	printf("sizeof(long)=%lld\n", sizeof(long));
	printf("sizeof(long long)=%lld\n", sizeof(long long));
	printf("sizeof(sizeof(5)=%lld\n", sizeof(sizeof(5)));
	return 0;
}



