# include <stdio.h>
/*
判断一个数是不是素数
*/
int main()
{
	int x;
	scanf("%d", &x);
	
	int i = 1;
	int is_prime = 1;
	for(i=2; i<x; i++) {
		if (x % i == 0) {
			is_prime = 0;
			break;
		}
	}
	if (is_prime) {
		printf("%d是素数", x);
	} else {
		printf("%d不是素数", x);
	}

	return 0;
}



