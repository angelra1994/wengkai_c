# include <stdio.h>
/*
逆序的三位数
输入700， 输出7
*/
int main() {
	int start = 0;
	
	scanf("%d", &start);
	
	int a = start / 100;
	int c = start % 10;

	int b = start % 100 / 10;
//	int b = start / 10 % 10;
	
	int end = c * 100 + b * 10 + a;
	printf("start=%d,end=%d\n", start, end);
	return 0;

}



