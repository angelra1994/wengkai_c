# include <stdio.h>

int main()
{
	
	float a, b, c;
	a = 1.345f;
	b = 1.123f;
	c = a+b;
	if (c == 2.468) {
		printf("c = a+b\n");
	} else {
		printf("c != a+b; c=%.10f, 或%f\n", c, c);
	}
	
	double ff = 1234.56789;
	// 1.234568e+03, 1234.567890, 1.234568E+03
	printf("%e, %f, %E\n", ff, ff, ff);
	
	ff = 1E-10;
	// 1.000000e-10, 0.0000000001000000, 1.000000E-10, 0.000000
	printf("%e, %.16f, %E, %f\n", ff, ff, ff, ff);
	
	// 在%和f之间加上.n是可以指定输出小数点后几位，实现四舍五入的输出。%f 默认输出是6位的四舍五入
	printf("%.3f\n", -0.0049);
	printf("%.30f\n", -0.0049);
	printf("%.3f\n", -0.00049);
	printf("%f\n", -0.0049);
	printf("===========\n");
	
	
	
	printf("%f\n", 1.0/0.0);           // inf
	printf("%f\n", -12.0/0.0);         // -inf
	printf("%f\n", 0.0/0.0);           // nan
	
	//printf("%d\n", 1/0);           // 0 [警告] division by zero is undefined [-Wdiv-by-zero]
	return 0;
}



