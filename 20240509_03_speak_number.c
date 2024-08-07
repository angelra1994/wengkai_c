/*
输入一个整数，输出每一个数字的读音

输入格式：
在一行中输入一个整数，如1234

输出格式:
yi er san si

输入样例：
-600

输出样例：
fu liu ling ling
*/

# include <stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	
	if ( x<0 ) {
		printf("fu ");
		x = -x;
	}
	
	int mask = 1;
	int t = x;
	while( t>9 ){
		t /= 10;
		mask *= 10;
	}
	
	do{
		int d = x / mask;
		switch (d) {
			case 0: printf("ling"); break;
			case 1: printf("yi"); break;
			case 2: printf("er"); break;
			case 3: printf("san"); break;
			case 4: printf("si"); break;
			case 5: printf("wu"); break;
			case 6: printf("liu"); break;
			case 7: printf("qi"); break;
			case 8: printf("ba"); break;
			case 9: printf("jiu"); break;
		} 
		if (mask>9) {
			printf(" ");
		}
		
		x %= 10;
		mask /= 10;
	}while(mask>0);
	printf("\n");
	
	return 0;
}



