# include <stdio.h>
/*
将身高从英尺作为单位转换成米 
*/
int main() {
	
	printf("请分别输入身高的英尺和英寸，""如输入\"5 7\"表示5英尺7英寸\n");
	int foot;
	int inch;
	scanf("%d    %d", &foot, &inch);
	// inch / 12 整数和整数的运算只能是整数 ((5 + 0) * 0.3048)
	printf("身高是%f米。\n", ((foot + inch / 12) * 0.3048));
	

	printf("身高是%f米。\n", ((foot + inch / 12.0) * 0.3048));
	
	float foot1;
	double inch1;
	scanf("%f    %lf", &foot1, &inch1);
	printf("身高是%f米。\n", ((foot1 + inch1 / 12) * 0.3048));

	return 0;

}



