# include <stdio.h>
/*
输出一个非负整数，正序输出它的每一位数字
*/
int main()
{
	int x;
//	scanf("%d", &x);
	x = 13425;
//	x = 700;
	int t = x;
	int mask = 1;
	while( t>9 ){
		t /= 10;
		mask *= 10;
	}
	printf("mask=%d\n", mask);
	
	t = x;
	do{
		int d = t /mask;
		printf("%d", d);
		if (mask > 9 ) {
			printf(" ");
		}
		t %= mask;
		mask /= 10;
	}while(mask > 0);
	printf("\n");
	
	
	printf("== ==\n");
	
    t = 0;
	do{
		int d = x%10;
		t = t*10 + d;
		x /= 10;
	} while( x>0 );
	printf("x=%d,t=%d\n", x, t);
	
	x = t;
	do {
		int d = x%10;
		printf("%d", d);
		if ( x > 9) {
			printf(" ");
		}
		x /= 10;
	} while( x>0 );
	printf("\n");
	return 0;
}



