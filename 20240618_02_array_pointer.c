#include <stdio.h>


int main(int argc, char const *argv[])
{
    int i = 0;
	long p = (long) &i;

	printf("&i=%p, sizeof(i)=%llu\n", &i, sizeof(i));
	printf("&p=%p, sizeof(p)=%llu\n", &p, sizeof(p));
	
	int a[10];
	
	printf("&a=%p, sizeof(&a)=%llu\n", &a, sizeof(&a));
	printf("a=%p, sizeof(a)=%llu\n", a, sizeof(a));
	printf("&a[0]=%p, sizeof(a[0])=%llu\n", &a[0], sizeof(a[0]));
	printf("&a[1]=%p, sizeof(a[1])=%llu\n", &a[1], sizeof(a[0]));

	
	/**
	 * 
	  &i=00000090d3dffa4c, sizeof(i)=4
	  &p=00000090d3dffa48, sizeof(p)=4
	  &a=00000090d3dffa20, sizeof(&a)=8
	  a=00000090d3dffa20, sizeof(a)=40
	  &a[0]=00000090d3dffa20, sizeof(a[0])=4
	  &a[1]=00000090d3dffa24, sizeof(a[1])=4
	 *  
	 */
	
	
    return 0;
}
