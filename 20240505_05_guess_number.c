/*
系统随机产生一个100以内的正整数x，与输入的数y进行比较
y>x, "Too big"
y<x, "Too small"
y=x,  
相等表示猜到了。如果猜到，则结束程序。而且程序还需要统计猜的次数
1次猜中           "Bingo!"
3次以内           "Lucky you!"
N(N>3)            "Good Guess!"
超过N次都没有猜到 "Game Over" 并结束程序
在到达N次之前，输入一个负数，也输出一个"Game Over" 
 
输入格式：
输入第一行是2个不超过100的正整数，分别是系统产生的随机数，最大次数N。随后每行给出一个用户的输入，直到出现负数为止
输出格式:
在一行中输出每次猜测相应的结果，直到输出猜对的结果或"Game Over"则结束

输入样例：
58 4
70
50
56
58
60
-2

输出样例：
Too big
Too small
Too small
Good Guess!

*/

#include <stdio.h>

int main() 
{
	int number, n;
	int inp;
	int finished = 0;
	int cnt = 0;
	
	scanf("%d %d", &number, &n);
	do{
		scanf("%d", &inp);
		cnt++;
		if (inp < 0) {
			printf("Game Over\n");
		} else if (inp > number) {
			printf("Too big\n");
		} else if (inp < number) {
			printf("Too small\n");
		} else {
			if (cnt == 1) {
				printf("Bingo!\n");
			} else if (cnt <= 3) {
				printf("Lucky you!\n");
			} else {
				printf("Good Guess!\n");
			}
			finished = 1;
		}
		if (cnt == n) {
			if (!finished) {
				printf("Game Over\n");
				finished = 1;
			}
		}
	} while(!finished);
	return 0;
}
