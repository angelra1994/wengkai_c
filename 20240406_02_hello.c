#include <stdio.h>
int main(int argc, char const *argv[])
{
	printf("hello world!!\n");
	// printf("你好!\n");

	int sum = 0;
	int i = 0;
	for (i = 1; i <= 100; i++)
	{
		sum += i;
	}

	printf("Σ1-100=%d\n", sum);

	int a = 0b1010;		 // 二进制   0b开头
	int b = 01010;		 // 八进制   0开头
	int c = 1010;		 // 十进制
	int d = 0x1010;		 // 十六进制 0x开发
	printf("a=%d\n", a); //%d 10进制展示数字
	printf("b=%d\n", b);
	printf("c=%d\n", c);
	printf("d=%d\n", d);

	printf("sizeof(char)                 = %d\n", sizeof(char));		       // 计算char 类型的字节数                  1
	printf("sizeof(unsigned char)        = %d\n", sizeof(unsigned char));	   // 计算unsigned char 类型的字节数         1
	printf("sizeof(short)                = %d\n", sizeof(short));			   // 计算short 类型的字节数                 2
	printf("sizeof(unsigned short)       = %d\n", sizeof(unsigned short));	   // 计算unsigned short 类型的字节数        2
	printf("sizeof(int)                  = %d\n", sizeof(int));				   // 计算int 类型的字节数                   4
	printf("sizeof(unsigned int)         = %d\n", sizeof(unsigned int));	   // 计算unsigned int 类型的字节数	         4
	printf("sizeof(long)                 = %d\n", sizeof(long));			   // 计算long 类型的字节数                  4
	printf("sizeof(unsigned long)        = %d\n", sizeof(unsigned long));	   // 计算unsigned long 类型的字节数         4
	printf("sizeof(long int)             = %d\n", sizeof(long int));		   // 计算long int 类型的字节数              8
	printf("sizeof(unsigned long int)    = %d\n", sizeof(unsigned long int));  // 计算unsigned long int 类型的字节数     8
	printf("sizeof(long long)            = %d\n", sizeof(long long));		   // 计算long long 类型的字节数             8
	printf("sizeof(unsigned long long)   = %d\n", sizeof(unsigned long long)); // 计算unsigned long long 类型的字节数    8
	printf("sizeof(float)                = %d\n", sizeof(float));		   	   // 计算float 类型的字节数                 4
	printf("sizeof(double)               = %d\n", sizeof(double));		       // 计算double 类型的字节数                8
	printf("sizeof(long double)          = %d\n", sizeof(long double));		   // 计算long double 类型的字节数           16
    
	char c1 = 'A';
	printf("'A'=%d,%5c\n",c1,c1);

	printf("' '=%d,=%5c,=0x%x\n",' ', ' ', ' ');
	printf("'  '=%d,=%5c,=0x%x\n",'  ', '  ', '  ');
	printf("'A'=%d,=%5c,=0x%x\n", c1, c1, c1);
	// int i1 = 'AA';
	printf("'AA'=%d,=%5c,=0x%x\n",'AA', 'AA', 'AA');
	// c1 = 65;
	c1 = c1 + ' ';
	printf("'A'+' '=%d,%5c\n",c1,c1);

	// for (i = 0; i < 256; i++)
	// {
	// 	printf("i=%d,%5c\n",i,i);
	// }

	return 0;
}