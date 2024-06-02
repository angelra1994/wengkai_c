#include <stdio.h>
#include <stdbool.h>



int max(int a, int b) {
	int ret;
	if (a > b) {
		ret = a;
	} else {
		ret = b;
	}
	return ret;
}


void cheer() 
{
	printf("cheer\n");
}


int main()
{
	int a,b,c;
	a = 5;
	b = 6;
	c = max(10, 12);
	c = max(a, b);
	c = max(c, 23);
	printf("%d\n", max(a, b));
	cheer();
	sum(1, 10);
	sum(2, 10);
	return 0;
}


void sum(int begin, int end) 
{
	int i;
	int sum = 0;
	for(int i=begin;i<=end;i++) {
		sum += i;
	}
	printf("从%d到%d的和是%d\n", begin, end, sum);
}



