#include <stdio.h>
#include <stdbool.h>


int main()
{
	bool b = 2>5;
	bool t = true;
	printf("b=%d, t=%d\n", b, t);
	t = 2;
	bool c;
	printf("b=%d, t=%d, c=%d\n", b, t, c);
	
	// 单目运算符优先级高于双目运算符
	t = !c < 20;
	printf("!c < 20=%d\n", t);
	t = !(c < 20);
	printf("!(c < 20)=%d\n", t);
	
	// 优先级 !>&&>|| not>and>or

	/**
	 * 优先级			运算符				结合性
	 * 1(高) 			()    				从左到右
	 * 2     			! + - ++ --	        从右到左(单目的+和-)
	 * 3				* / %               从左到右
	 * 4				+ -                 从左到右(双目的+和-)
	 * 5				< <= > >=           从左到右
	 * 6				== !=               从左到右
	 * 7				&&                  从左到右
	 * 8				||                  从左到右
	 * 9(低)            = += -= *= /= %=    从右到左  
	 */
	
	return 0;
}




