/*
计算序列 2/1+3/2+5/3+8/5+...的前n项和。从第2项开始，分子是前一项分子分母的和，分母是前一项分子

 
输入格式：
输入在一行中给出一个正整数N
输出格式:
在一行中输出部分和的值，精确到小数点后2位。结果不超过双精度的范围

输入样例：
20

输出样例：
32.66

*/

#include <stdio.h>

int main() 
{
	int n;
	double a, b;
	double sum = 0.0;
	int i;
	double t;
	
	scanf("%d", &n);
	a = 2;
	b = 1;

	for(i=1;i<=n;i++){
		sum += a/b;
		t = a;
		a = a+b;
		b = t;
	}
	printf("%.2f\n", sum);
	return 0;
}
