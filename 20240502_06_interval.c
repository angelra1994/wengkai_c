# include <stdio.h>
/*
计算两个时间点的时间差
*/
int main() {
	int a = 0;
	int b = 0;
	
	printf("[7>=3+4]: %d\n", 7>=3+4);
	printf("[(7>=3)+4)]: %d\n", (7>=3)+4);
	printf("[5>3==6>4]: %d\n", 5>3==6>4);
	int c = a==b;
	int d = a!=b;
	int e = 2==3;
	// == 和 != 的优先级表其他的低，而连续的关系运算是从左到右进行
	printf("[a==b==6]: %d\n", a==b==6);
	printf("[a==b>6]: %d\n", a==b>6);
	
	int hour1, mintue1;
	int hour2, mintue2;
	
	scanf("%d %d", &hour1, &mintue1);
	scanf("%d %d", &hour2, &mintue2);
	
	int ih = hour2 - hour1;
	int im = mintue2 -  mintue1;
	
	if (im < 0) {
		im = 60 + im;
		ih --;
	}
	
	printf("时间差是%d小时%d分钟\n", ih, im);
	return 0;

}



