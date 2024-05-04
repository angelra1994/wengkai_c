# include <stdio.h>
/*
计算找零钱的代码
*/
int main()
{
	
//	const int AMOUNT = 100;
	int amount = 100;
	int price;
	printf("请输入价格￥（元 CNY）\n");
	scanf("%d", &price);
	printf("请输入现金￥（元 CNY）\n");
	scanf("%d", &amount);

//	int change = AMOUNT - price;
	int change = amount - price;
	
	printf("找您￥%d（元 CNY）\n", change);
	
	return 0;

}
	
	
