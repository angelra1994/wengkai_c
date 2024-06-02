#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main()
{
	char c = 255;
	int i = 255;
	// c=-1, i=255
	printf("c=%d, i=%d\n", c, i);
	/**
	 * 
	 * 正数的原码,反码,补码是一致的
	 * 0需要考虑 +0 和 -0 两种情况
	 * +0 : 00000000 00000000 , -0 : 10000000 00000000
	 * +0 : 00000000 00000000 , -0 : 11111111 11111111
	 * +0 : 00000000 00000000 , -0 : 00000000 00000000
	 * 
	 * 原码就是符号位加上真值的绝对值
	 * 11111111
	 * -1 源码: 10000001
	 * -1 反码: 11111110    (符号位不变，其他位取反)
	 * -1 补码: 11111111    (反码+1)
	 * 
	 * -1 + 1 = 0
	 * 11111111 + 00000001 = (1) 00000000
	 *  0 - 1 = -1 = (1) 00000000 - 00000001
	 * 对于-a 来说。其补码就是0-a, 实际是 2^n - a. n是这个类型位数
	 * 
	 * 补码的意义就是拿补码和源码可以加出一个溢出的0 (负数情况，正数情况原码补码之和，左移一位)
	 */
	
	// 00000000 00000000 00000000 11111111
	
	// unsigned 表示这个整数不以补码的形式表示负数。最高位不是符号位
	unsigned char u_c = 255;
	printf("u_c=%d\n", u_c);

	
	
	int a = 0,b =0;
	while(++a>0) {
		
	};
	printf("int类型的最大整数是%d\n", a-1);
	printf("int_max + 1的值是%d\n", a);
	b++;
	while((a=a/10)!=0){
		b++;
	}
	printf("int类型的最大位数是%d\n", b);

	printf("==============");
	
	printf("char bytes:%d\n", sizeof(char));
	
	printf("short bytes:%d\n", sizeof(short));
	
	printf("int bytes:%d\n", sizeof(int));
	
	printf("float bytes:%d\n", sizeof(float));
	
	printf("long bytes:%d\n", sizeof(long));
	
	printf("long int bytes:%d\n", sizeof(long int));
	
	printf("long long bytes:%d\n", sizeof(long long));
	
	printf("long long int bytes:%d\n", sizeof(long long int));
	
	printf("uint64_t bytes:%d\n", sizeof(uint64_t));
	
	printf("uint32_t bytes:%d\n", sizeof(uint32_t));
	
	printf("size_t bytes:%d\n", sizeof(size_t));
	
	return 0;
}




