#include <stdio.h>

void fun_static_const(int count);

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 3; i++)
    {
		printf("开始第%d次调用fun_static_const，&i = %p. \n", i, &i);
        fun_static_const(i);
    }
	int a = 3;
	printf("开始第%d次调用fun_static_const，&a = %p. \n", a, &a);
	fun_static_const(a);
    return 0;
}

void fun_static_const(int count) 
{    
    static int s_i = 0;
    printf("第%d次进入fun_static_const，&count = %p，s_i = %d，&s_i = %p. \n", count, &count, s_i, &s_i);
    for (int i = 0; i < 3; i++)
    {
        s_i = s_i + 1;
        printf("s_i=%d, &i=%p\n", s_i, &i);
    }
}
