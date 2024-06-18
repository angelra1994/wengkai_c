#include <stdio.h>

/**
 * scanf("%d", &i); 里面的&
 * 获取变量的地址，它的操作数必须是变量
 * int i; print("%x", &i);
 * 
 * 地址的大小是否和int 相同取决于编译器
 * 
 */
int main(int argc, char const *argv[])
{
    int i = 0;
    printf("%p\n", &i);
	
	int p = (int)&i;
	printf("0x%x\n", p);
	
	long l = (long)&i;
	printf("0x%x\n", l);

	
	printf("%lu\n", sizeof(int));
	printf("%lu\n", sizeof(&i));
	
    return 0;
}
