# include <stdio.h>
/*
用1角，2角，5角的硬币 凑整数 x元
*/
int main()
{
	int x;
	int a, b, c;
	
	// scanf("%d", &x);
	x = 2;
	
	
	// break和continue只能跳出当前的循环
	for(a=1;a<x*10;a++){
		for(b=1;b<x*10/2;b++){
			for(c=1;c<x*10/5;c++){
				if (a + b*2 + c*5 == x*10) {
					printf("可以用%d个1角加%d个2角加%d个5角凑成%d元\n",a,b,c,x);
					break;
				}
			}
		}
	}
	
	printf("====接力break====\n");
	int exit = 0;
	// 接力break
	for(a=1;a<x*10;a++){
		for(b=1;b<x*10/2;b++){
			for(c=1;c<x*10/5;c++){
				if (a + b*2 + c*5 == x*10) {
					printf("可以用%d个1角加%d个2角加%d个5角凑成%d元\n",a,b,c,x);
					
					exit = 1;
					break;
				}
			}
			if (exit) break;
		}
		if (exit) break;
	}

	printf("====使用goto====\n");
	// 使用goto
	for(a=1;a<x*10;a++){
		for(b=1;b<x*10/2;b++){
			for(c=1;c<x*10/5;c++){
				if (a + b*2 + c*5 == x*10) {
					printf("可以用%d个1角加%d个2角加%d个5角凑成%d元\n",a,b,c,x);
					goto out;
				}
			}
		}
	}
	out:
	return 0;
}



