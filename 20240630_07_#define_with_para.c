#include <stdio.h>

/**
像函数的宏
#define cube(x) ((x)*(x)*(x))

宏可以带参数，原则
一切都要括号，整个值要括号。参数出现的每一个地方都要括号
#define RADTODEG(x) ((x)*57.29578)

在大型程序的代码中使用 宏 非常普遍
在#和## 两个运算符的帮助下，宏可以非常复杂，如'产生'函数
部分带参宏会被inline函数替代

 */

#define cube(x) ((x)*(x)*(x))

int main(int argc, char const *argv[]) 
{
    printf("cube(%d)=%d\n", 5, cube(5));
    return 0;
}
