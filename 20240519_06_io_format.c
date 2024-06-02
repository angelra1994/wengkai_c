#include <stdio.h>
/**
  %d: int
  %u: unsigned
  %ld: long long (long long int)
  %lu: unsigned long long (unsigned long long int)
  
  %c:char
 */

int main()
{

	char c = -1;
	int  i = -1;
	
	/**
	 * 11111111 11111111 11111111 11111111
	 * c=4294967295,i=4294967295
	 * printf, 编译器会将范围小于int的转换成int 作为输出
	 * %u 当作unsigned 进行输出
	 */
	printf("c=%u,i=%u\n", c, i);
	//c=-1,i=-1
	printf("c=%d,i=%d\n", c, i);
	
	c = 012;
	i = 0x12;
	printf("c=%d,i=%d\n", c, i);
	printf("八进制c=%o,十六进制i=%x\n", c, i);
	return 0;
}




