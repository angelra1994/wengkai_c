#include <stdio.h>

/**
全家变量
定义在函数外面的变量是全局变量，具有全局的生存期和作用域
在任何函数内部都可以使用它们

 */

int f(void);

int g_all = 12;

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