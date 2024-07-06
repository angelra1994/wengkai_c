#include <stdio.h>

/**
静态本地变量
在本地变量定义时加上static修饰符。初始化只会做一次
当函数离开的时候，静态本地变量会继续存在并保持其值
静态本地变量的初始化只会在第一次进入这个函数时做，再次进入会保持上次离开时的值

静态本地变量实际上是特殊的全局变量，位于相同的内存区域
静态本地变量具有全局的生存期，函数内的局部作用域
static 表示这个变量只能在这个函数内部访问，作用域

 */

int f(void);

// int g_all;
int g_all = 12;
// int g2 = g_all;  //  initializer element is not constant 或 initializer element is not a complie-time constant
// int g_all = f(); //  initializer element is not constant。即f() 并不是编译时刻就知道的常量

int main(int argc, char const *argv[]) 
{
    
    f();
    f();
    f();
    return 0;  
}

int f(void)
{
    int all = 1;
    static int s_all = 1;
    printf("&g_all=%p(%%p), &s_all=%p(%%p), &all=%p(%%p)\n", &g_all, &s_all, &all);
    printf("in %s all = %d, s_all = %d\n", __func__, all, s_all);
    s_all += 2;
    all += 2;
    printf("again in %s all = %d, s_all = %d\n", __func__, all, s_all);
    return s_all;

}