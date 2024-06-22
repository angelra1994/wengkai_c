#include <stdio.h>

/*
int putchar(int c)  向标准输出写出一个字符。返回写了几个字符，EOF(-1)表示写失败
int getchar(void)   从标准输入读入一个字符。返回类型是int是为了返回EOF(-1)

Windows -> Ctrl-Z  (EOF)
Uxix    -> Ctrl-D  (EOF)
*/

/* argv[0] 是命令本身，当使用Unix符号链接时，反映符号链接的名字 */
int main(int argc, char const *argv[]) 
{
    int ch;
    while ((ch = getchar()) != EOF)
    {
        putchar(ch);
    }
    printf("EOF");
    return 0;
    
}
