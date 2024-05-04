# include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
猜数
*/
int main()
{
	srand(time(0));
	// 1-100 之间的一个数 [1, 100]
	int number = rand()%100 + 1;
	
	int count = 0;
	int a = 0;
	printf("有一个1-100之间的整数。");
	printf("尝试猜一猜\n");
	
	do {
		scanf("%d", &a);
		count++;
		if (a > number) {
			printf("你猜的数字大了\n");
		} else if (a < number) {
			printf("你猜的数字小了\n");
		}
	} while(a != number);

	printf("你用%d次猜到了答案%d\n", count, number);
	return 0;
}



