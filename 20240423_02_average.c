# include <stdio.h>
/*
计算两个数的平均值
*/
int main() {
	int a, b;
	scanf("%d    %d", &a, &b);

	double c = (a + b)/2.0;
	printf("%d和%d平均值是%f。\n", a, b, c);

	return 0;

}



