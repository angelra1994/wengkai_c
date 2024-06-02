# include <stdio.h>

int main()
{
	/**
	 * 当运算符两边出现类型不一致的时候，会自动转换成范围大的类型
	 * char -> short -> int -> long -> long long
	 * int -> float -> double
	 * 
	 * 对于printf，任何小于int的类型都会被转成int，float都会被转成double
	 * 但是scanf不会，要输入short，需要%hd，longlong 需要 %ld
	 */
	
	/**
	 * 强制类型转换，通常是转换成较小的类型。且强制转换的优先级高于四则运算
	 * (类型)
	 * (int)10.2
	 * (short)32
	 * 需要注意安全性，如
	 * (short)32768
	 * 
	 */
	
	printf("%d\n", 32768);
	printf("%d\n", (short)32768);  // -32768
	printf("%d\n", (char)32768);   // 0    32768 = 10...0(15bit0)。而char是取最低的8个bit
	
	int i = 32768;
	short s = (short) i;
	printf("i=%d\n", i);
	printf("s=%hd\n", s);
	return 0;
}



