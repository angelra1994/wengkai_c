#include <stdio.h>

//void f(int *p);
void f(int *);
void g(int);

int main(int argc, char const *argv[])
{
    int i = 10;
	printf("&i=%p\n", &i);
	f(&i);
	g(i);
	int* p = &i;
//	f(p);

	/**
	 * 互相反作用
	 int*p = &i 变量取地址
	 int y = *p 取指针p指向的地址绑定的变量 
	 
	 *&yptr -> * (&yptr) -> * (yptr的地址) -> 得到那个地址上的变量 -> yptr
	 &*yptr -> &(*yptr) -> &(y) -> 得到y的地址，也就是yptr -> yptr
	 
	 * 
	 */

	
	
    return 0;
}

void f(int *p)
{
	printf(" p=%p\n", p);
	printf(" *p=%d\n", *p);
	*p = 26;
}

void g(int k)
{
	printf(" k=%d\n", k);
}
