/*
求a的连续和
输入两个整数a和n, 0<=1<=9, 1<=n<8。求数列的和S=a+aa+aaa+...+aaa...a(n个a)

输入格式：
在一行中输入两个整数，先后表示a和n

输出格式:
S的值

输入样例：
2 4

输出样例：
2468
*/

# include <stdio.h>

int main()
{
	int a, n;
//	scanf("%d %d", &a, &n);
	
	a = 2;
	n = 4;
	
	int sum = 0;
	int i;
	int t = 0;
	// 0*10+2 + 2*10+2 + (2*10+2)*10+2 + ...
	for(i=0;i<n;i++){
		t = t*10 + a;
		sum += t;
	}
	
	printf("%d", sum);
	
	return 0;
}



