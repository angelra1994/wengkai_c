# include <stdio.h>
/*
将一个整数逆序
*/
int main()
{
	int x;
	scanf("%d", &x);
//	x = 123450;

	int digit = 0;
	int ret = 0;

	while(x>0){
		digit = x%10;
		printf("%d\n", digit);
		ret = ret * 10 + digit;
		
		printf("x=%d, digit=%d, ret = %d\n", x, digit, ret);
		x /= 10;
	}
	printf("%d", ret);

	return 0;
}



