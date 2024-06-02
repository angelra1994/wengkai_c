/*
输入一个分数，将其约分为最简分式

输入格式：
如 12/34 表示34分之12 最简分式为 6/17
提示：在scanf 中第一个 format字符串 加入"/" 让scanf帮忙处理这个斜杠
输出格式:
同输入格式 6/17

输入样例：
60/120

输出样例：
1/2
*/

# include <stdio.h>

int main()
{
	int dividend, divisor;
	int t=0;
	scanf("%d/%d", &dividend, &divisor);
	
	int a = dividend;
	int b = divisor;
	printf("a=%d,b=%d,t=%d\n", a, b, t);
	while(b != 0){
		t = a%b;
		a = b;
		b = t;
		printf("a=%d,b=%d,t=%d\n", a, b, t);
	}
	printf("%d/%d\n", dividend/a, divisor/a);
	
	return 0;
}



