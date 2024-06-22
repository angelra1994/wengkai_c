#include <stdio.h>

int main(int argc, char const *argv[])
{
/** 
<, <=, ==, >, >=, != 都可以都指针做运算
比较它们在内存中的地址
数组中的单元的地址肯定是线性递增的
*/

/**
0地址，内存中有0地址，但是0地址通常是一个不能随便碰的地址
代码中的指针不应该具有0值，因此可以用0地址来表示特殊的事情：
1. 返回的指针是无效的
2.指针变量没有被真正初始化（先初始化为0）
NULL 是一个预定义的符号，表示0地址。但是有的编译器不愿意用0来表示0地址
 */

/**
指针的类型转换
void* 表示不知道指向什么东西的指针，计算时与 char* 相同（但不相通）
指针也可以转换类型  int *p = &i; void *q = (void*)p;
并没有改变p所指向的变量的类型，而是把q指向的变量不再当作int看待，认为是一个void（某个地址所代表的外部设备，控制寄存器等）
 * 
 */

    char ac[] = {0,1,2,3,4,5,6,7,8,9,' ', '0','1','2','3', -1};
    char *p = ac;
    char *p1 = &ac[5];
    printf("p=%p(%%p)\n", p);
    printf("p+1=%p(%%p), sizeof(char)=%lu\n", p+1, sizeof(char));
    printf("*(p+1)=%d\n", *(p+1));
    printf("p1-p=%d\n", p1-p);

    for (int i = 0; i < sizeof(ac)/sizeof(ac[0]); i++)
    {
        printf("%d\t", ac[i]);
    }
    printf("\n");

    // for (p=ac; *p != -1;)
    while (*p != -1)
    {
        printf("%d\t", *p++);
    }
    printf("\n");

    // *p -> ac[0]
    // *(p+1) -> ac[1]
    // *(p+n) <-> ac[n]

    int ai[] = {0,1,2,3,4,5,6,7,8,9,' ', '0','1','2','3',};
    int *q = ai;
    int *q1 = &ai[6];
    printf("q=%p(%%p)\n", q);
    printf("q1=%p(%%p)\n", q1);
    printf("q+1=%p(%%p), sizeof(int)=%lu\n", q+1, sizeof(int));
    printf("*(q+1)=%d\n", *(q+1));
    printf("q1-q=%d\n", q1-q);  // 这两个地址间，有几个 sizeof(int)

/**
p=000000E8E15FFAC1(%p)
p+1=000000E8E15FFAC2(%p), sizeof(char)=1
*(p+1)=1
p1-p=5
q=000000E8E15FFA80(%p)
q1=000000E8E15FFA98(%p)
q+1=000000E8E15FFA84(%p), sizeof(int)=4
*(q+1)=1
q1-q=6
 */

/**
*p++, 取出p所指的那个数据来。完事之后顺便把p移动到下一个位置去
*的优先级虽然高，但是没有++高。常用与数组类的连续空间操作。例如遍历
在某些cpu上，这可以被翻译成一条汇编指令
 */
    return 0;
}
