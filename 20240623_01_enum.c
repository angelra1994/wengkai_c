#include <stdio.h>
// enum _color {red, yellow, green};
enum COLOR {red, yellow, green, Num_of_Colors};
// enum COLOR {red=1, yellow, green=6, Num_of_Colors};
void f(enum COLOR c);

int main(int argc, char const *argv[]) 
{
    enum COLOR t = yellow;
    f(t);
    f(green);
    // scanf("%d", &t);
    t = 9;
    /* c语言内部的 enum就是int。每一个枚举类型的变量是可以当作int 进行输入输出处理 */
    f(t);

    int color = -1;
    char *ColorNames[Num_of_Colors] = {"red", "yellow", "green", };
    char *colorName = NULL;
    printf("输入你喜欢的颜色编码：");
    scanf("%d", &color);
    if (color >= 0 && color < Num_of_Colors) {
        colorName = ColorNames[color];
    } else {
        colorName = "unknown";
    }
    printf("你喜欢的颜色是：%s\n", colorName);
    return 0;
    
}

void f (enum COLOR c) {
    printf("%d\n", c);
}
