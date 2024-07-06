#include <stdio.h>
#include "max.h"
#include "main.h"   // [错误] redefinition of 'struct Node'

/**
变量的声明
int i;  是变量的定义
extern int i;  是变量的声明

声明是不产生代码的东西
	函数原型
	变量声明
	结构声明
	宏声明
	枚举声明
	类型声明
	inline函数
定义是产生代码的东西
 */

/**
只有声明可以被放在头文件中
否则会造成一个项目中多个编译单元里有重名的实体
某些编译器允许几个编译单元中存在同名的函数，或者用weak修饰符来强调这种存在

同一个编译单元里，同名的结构不能被重复声明
避免头文件在一个编译单元被#include多次，需要"标准头文件结构"
 */

/**
#ifndef __LIST_HEAD__
#define __LIST_HEAD__

#include "node.h"

typedef struct _list {
	Node* head;
	Node* tail;
} List;
#endif


运用条件编译和宏，保证这个头文件在一个编译单元只会被#include一次
#pragma once也能起到相同的作用，但是并不是所有的编译器都支持
 */


int main(int argc, char** argv) {
	printf("Hello world!\n");
	int a = 5;
	int b = 6;
	printf("max(a, b) = %f\n", max(a, g_all));
	return 0;
}
