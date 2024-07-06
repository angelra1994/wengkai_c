#ifndef MAX_H
#define MAX_H
extern int g_all; // 告诉编译器，在项目的某一个地方有一个叫 g_all 的东西

double max(double, double);

struct Node
{
	int value;
	char* name;
};
#endif
