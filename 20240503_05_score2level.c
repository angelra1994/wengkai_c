# include <stdio.h>
/*
成绩转换
百分制的成绩转换成A-E的五分制
*/
int main()
{
	int score;
	
	scanf("%d", &score);
	if (score >= 90) {
		printf("A\n");
	} else if (score >= 80) {
		printf("B\n");
	} else if (score >= 70) {
		printf("C\n");
	} else if (score >= 60) {
		printf("D\n");
	} else {
		printf("E\n");
	}
	
	score /= 10;
	switch (score) {
	case 10:
	case 9:
		printf("A\n");
		break;
	case 8:
		printf("B\n");
		break;
	case 7:
		printf("C\n");
		break;
	case 6:
		printf("D\n");
		break;
	default:
		printf("E\n");
		break;
	}
	return 0;

}



