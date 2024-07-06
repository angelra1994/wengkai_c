#include <stdio.h>

/**
全局变量初始化
没有初始化的全局变量会得到0值
指针会得到NULL值
只能用编译时刻已知的值来初始化全局变量
全局变量的初始化在main函数之前

 */

int f(void);

// int g_all;
int g_all = 12;
// int g2 = g_all;  //  initializer element is not constant 或 initializer element is not a complie-time constant
// int g_all = f(); //  initializer element is not constant。即f() 并不是编译时刻就知道的常量

int main(int argc, char const *argv[]) 
{
    printf("in %s g_all = %d\n", __func__, g_all);
    f();
    printf("again in %s g_all = %d\n", __func__, g_all);
    return 0;  
}

int f(void)
{
    printf("in %s g_all = %d\n", __func__, g_all);
    g_all += 2;
    printf("again in %s g_all = %d\n", __func__, g_all);
    return g_all;

}