/*
水仙花数是N位的正整数(N>=3)，每位数字的N次幂之和等于它本身。如 153 = 1^3 + 5^3 + 3^3

输入格式：N(3<=N<=7)
输出格式：递增序输出所有N位的水仙花数，每一个数字占一行

输入样例：
3
输出样例：
153
370
371
407
*/

#include <stdio.h>

int main() 
{
	int n;
//	scanf("%d", &n);
	n = 3;
	
	int first = 1;
	int i = 1;
	while( i<n){
		first *= 10;
		i ++;
	}
	printf("first=%d\n", first);
	// 遍历100-999
	i = first;
	while(i<first*10){
		int t = i;
		int sum = 0;
		do{
			int d = t%10;
			t/=10;
			int p=1;
			int j=0;
			while(j<n){
				p*=d;
				j++;
			}
			sum += p;
		}while(t>0);
		if (sum == i) {
			printf("%d\n", i);
		}
		i++;
	}
	
	
	
	return 0;
}
