#include <stdio.h>
#include <stdbool.h>

void swap(int a, int b);


int main()
{
	int a,b,c;
	a = 5;
	b = 6;
	printf("before swap, a=%d, b=%d\n", a, b);
	swap(a, b);
	
	{
		int i = 0;
		
		printf("i=%d, a=%d\n", i, a);
		
		int a = 0;
		printf("i=%d, a=%d\n", i, a);
		
	}
	printf("after swap, a=%d, b=%d\n", a, b);
	return 0;
}


void swap(int x, int y) 
{
	int swap;
	int t = x;
	x = y;
	y = t;
	
}


