# include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
计算平均数，输入一堆数。当输入number为-1 时，表示输入完毕
计算 -1 之前输入的平均数
*/
int main()
{
	int number;
	int sum = 0;
	int count = 0;
	
	
//	do {
//		scanf("%d", &number);
//		if (number != -1) {
//			sum += number;
//			count ++;
//		}
//	} while(number != -1);
	
	
	scanf("%d", &number);
	while(number != -1){
		sum += number;
		count ++;
		scanf("%d", &number);
	}

	printf("平均数是%f，sum=%d， count=%d\n",  1.0 * sum/count, sum, count);
	return 0;
}



