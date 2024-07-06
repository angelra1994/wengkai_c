#include <stdio.h>
#include <stdlib.h>

/**
项目
在Dev C++ 中新建一个项目，把几个源代码文件加入进去
对于项目，Dev C++ 的编译会项目中所有的源代码文件都编译后，链接起来
有的IDE有分开的编译和构建两个按钮，前者是对单个源代码文件编译，后者是对整个项目做链接


编译单元，一个.c 文件时一个编译单元
编译器每次编译只能处理一个编译单元
 */

int max(int, int);

int main(int argc, char *argv[]) {
	int a = 5;
	int b = 6;
	printf("max(a, b) = %d\n", max(a, b));
	return 0;
}
