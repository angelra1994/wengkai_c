#include <stdio.h>
#include "max.h"

/**
头文件
把函数原型放到了 .h文件(头文件)中，需要掉用这个函数的源代码文件(.c文件) 中 #include这个头文件，
就能让编译器在编译的时候知道函数原型(#inclued的预处理)

#include是一个编译预处理指令，和#define一样在编译之前就处理了
把对应.h文件的全部文本内容原封不动地插入到 .c文件中 (#include xx.h 所在) 的那一行
所有也不是一定要在.c文件的最前面 #include

gcc main.c max.c               //-> a.exe  编译链接生成 a.exe/a.out  

gcc --save-temps main.c -c    // 检查 main.i 文件内容
 */


/*
#include有两种形式来指出要插入的文件
"" 要求编译器首先在当前目录(.c文件所在的目录)寻找这个文件，如果没有，到编译器指定的目录去找
<>让编译器只在指定的目录去找
编译器自己知道自己的标准库头文件在哪里
环境变量和编译器命令行参数也可以指定寻找头文件的目录

1.#include不是用来引入库的
2.stdio.h里只有printf的原型，printf的代码在另外的地方，某个.lib(Windows)或.a(Unix)中
3.现在的C语言编译器会默认引入所有的标准库
4.#include <stdio.h>只是为了让编译器知道printf函数的原型，保证你调用的时给出的参数值时正确的类型

在使用和定义这个函数的地方都应该 #include 这个头文件
一般的做法就是任务的.c都有对应的同名.h，把所有对外公开的函数原型和全局变量的声明都放进去

在函数前面加上static就使得它变成只能在所在的编译单元中被使用的函数
在全局变量前面加上static就使得它成为只能在所在编译单元中被使用的全局变量
*/

int main(int argc, char *argv[]) {
	int a = 5;
	int b = 6;
	printf("max(a, b) = %f\n", max(a, b));
	return 0;
}
