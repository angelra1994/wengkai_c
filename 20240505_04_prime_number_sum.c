/*
统计给定正整数M和N区间内的素数个数，并求和

输入格式：正整数M和N(1<=M<=N<=500)
输出格式：在一行中顺序输出M和N区间内的素数个数以及它们的和

输入样例：
10 31

输出样例：
7 143

*/

#include <stdio.h>

int main() 
{
	int m, n;
	int i;
	int cnt = 0;
	int sum = 0;
	
	//scanf("%d %d", &m, &n);
	m = 1;
	n = 3;
	if (m=1) {
		m=2;
	}
	for(i=m;i<=n;i++) {
		int is_prime = 1;

		int j;
		for(j=2;j<i;j++) {
			if (i%j == 0) {
				is_prime = 0;
				break;
			}
		}
		
		//判断i是否是素数
		if (is_prime) {
			cnt++;
			sum += i;
		}
	}
	printf("%d %d", cnt, sum);
	return 0;
}
