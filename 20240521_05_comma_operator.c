#include <stdio.h>
#include <stdbool.h>


int main()
{
	/**
	 * 逗号用来连接两个表达式，并以其右边的表达式的值作为它的结果。
	 * 逗号的优先级是所有运算符中最低的，低过赋值计算，所以逗号两边的表达式会先计算
	 * 逗号的组合关系是自左向右。左边表达式会先计算，右边表达式的值就作为逗号运算的结果
	 */
	int i;
	
	
	i= 3+4,5+6;
	// i=7  3+4的值先赋值给了i ','右边的5+6之后计算，但是结果并没有任何表达式使用
	printf("i=%d\n", i);
	
	
	i= (3+4,5+6);
	// i=11  5+6的值作为逗号表达式的返回值赋值给了i，','左边的3+4虽然先计算，但是值并没有使用
	printf("i=%d\n", i);
	
	
	float  x=10.5,  y=1.8,  z=0;
	z = (x+=5, y = x+0.2) ;  
	printf("z=%f， sizeof(z)=%lld\n", z, sizeof(z));
	
	int a = 1;
	int* p = &a;
	printf("size(++a)=%lld, &a=%x, p=%p\n", sizeof(++a), &a, p);
	printf("a=%d\n", a);
	
	
	
	a = 0b1000;
	int b = 0b111;
	printf("a=%d\n", a ~= b);
	
	
	
	/**
	 * 在 for 中使用
	 * for(i=0,j=10;i<j;i++,j--)
	 */
	return 0;
}




