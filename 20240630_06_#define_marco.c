#include <stdio.h>

/**
#开头的是编译预处理指令，它们不是C语言的成分，但是C语言程序离不开它们

#define用来定义一个宏 macro
#define <名字> <值>
预处理由于不是C的语句，结尾没有 分号
名字必须是一个单词，但是值可以是任何东西
编译器的编译预处理对于宏是完全的文本替换，把名字替换成值

没有值的宏
#define _DEBUG
这类宏是用于条件编译的，后面有其他的编译预处理指令来检查这个宏是否已经被定义过了

C编译器中预先定义的宏
__LINE__
__FILE__
__DATE__
__TIME__
__STDC__

 */

// const double PI = 3.14159;
#define PI 3.14159
#define FORMAT "%f\n"
#define PI2 2*PI  //PI*2
#define PRT printf("PI=%f ", PI); \
            printf("PI2=%f ", PI2)
 

/**
gcc xx.c --save-temps

.c(源文件) -编译预处理-> .i(中间结果文件) -编译-> .s(汇编代码文件) -汇编-> .o(目标代码文件) -链接-> a.out/a.exe(可执行文件)
 */


int main(int argc, char const *argv[]) 
{
    printf("%s, %d\n", __FILE__, __LINE__);
    printf("%s, %s\n", __DATE__, __TIME__);
    printf(FORMAT, PI2*3.0);
    PRT;
    return 0;
}
