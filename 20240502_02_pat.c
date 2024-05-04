# include <stdio.h>
/*
厘米转英寸
*/
int main() {
	int cm = 0;
	
	scanf("%d", &cm);
	
	int foot = cm / 30.48;
	int inch = ((cm / 30.48) - foot) * 12;
	printf("%d英尺%d英寸\n", foot, inch);

	return 0;

}



