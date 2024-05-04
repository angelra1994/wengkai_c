# include <stdio.h>
/*
将阶乘
*/
int main()
{
	int n;
	scanf("%d", &n);

	int fact = 1;
	
	int i = 1;
	while(i <= n){
		fact *= i;
		i ++;
	}

	printf("%d\n", fact);

	fact = 1;
	for(int j=1;j<=n;j++) {
		fact *= j;
	}
	printf("%d!=%d\n", n, fact);
	
	i = n;
	fact = 1;
//	for(n = n; n>1; n--) {
	for(; n>1; n--) {
		fact *= n;
	}
	
	printf("%d!=%d\n", i, fact);

	return 0;
}



