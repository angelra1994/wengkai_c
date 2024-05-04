# include <stdio.h>
/*
BCD解密
BCD数是用两个字节表达的两位十进制的数，每4个比特表示一位。如果一个BCD数的16进制是0x12，表示10进制的12
可能有误解将BCD数转成2进制再转换成十进制输出，会导致BCD的0x12被输出成10进制的18
需要将错误的10进制的输入转换成正确的BCD的10进制输出。如18 -> 0x12 -> 12
输入的10进制数都是有效的BCD数，即转换成16进制后没有没有 A到F 的字母
*/
int main() {
	int start = 0;
	
	// 10进制读入
	scanf("%d", &start);
	
	// 16进制输出
	printf("%x\n", start);
	
	int end = start / 16 * 10 + start % 16;
	printf("%d\n", end);
	return 0;

}



