# include <stdio.h>
/*
然后是几点
输入两个数 四位数字表示起始时间，流逝的分钟数。流逝的分钟数可能是超过60也可能是负数
输入输出保证在同一天内
*/
int main() {
	int start = 0;
	int interval = 0;
	
	scanf("%d %d", &start, &interval);
	
	int hour = start / 100;
	int minute = start % 100;
	printf("流逝前, %d点%d分\n", hour, minute);
	
	minute = hour * 60 + minute + interval;
	hour = minute / 60;
	minute = minute % 60;

	int end = hour * 100 + minute;
	
	printf("流逝后, %d点%d分\n", hour, minute);
	printf("start=%d,end=%d\n", start, end);
	return 0;

}



