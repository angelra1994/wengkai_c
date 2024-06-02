/*
正整数A(>=6)，从A开始连续的4个数字，输出由它们组成的无重复数字的3位数

输入样例：
2
输出样例：
234 235 243 245 253 254
324 325 342 345 352 354
423 435 432 435 452 453
523 524 532 534 542 543
*/

#include <stdio.h>

int main() 
{
	int a;
//	scanf("%d", &a);
	a = 2;
	
	int i, j, k;
	int cnt = 0;
	i = a;
	while(i <= a+3) {
		j = a;
		while(j <=  a+3) {
			k = a;
			while(k <= a+3) {
				if (i !=j ) {
					if (j != k) {
						cnt ++;
						printf("%d%d%d", i, j, k);
						if (cnt == 6) {
							printf("\n");
							cnt = 0;
						} else {
							printf(" ");
						}
					}
				}
				k++;
			}
			j++;
		}
		i++;
	}
	
	
	return 0;
}
