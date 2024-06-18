#include <stdio.h>

int main(int argc, char const *argv[])
{
    char a1 = 65;
    char a2 = 'A';
    char b1 = 10;            //  ascii 的10 对应的字符是'\n' , 换行符
    char b2 = '\n';          //  '\n' 的ascii是10 ， 是10 的另外一种写法

    putchar(a1);      // A , 把整数当成字符输出
    putchar(a2);      // A , 把整数当成字符输出
    putchar(b1);      // 换行符, 把整数当成字符输出
    putchar(b2);      // 换行符, 把整数当成字符输出
    putchar(65 + 1);  // A+1 = B
    putchar('A' + 1); // A+1 = B
    putchar('B'+' ') ; // 大写转小写 + ' ' , 输出b 
    int a = putchar('b'-' ') ; // 小写转大写 - ' ' , 输出B 
    int b = printf("\na=%d\n", a);
    printf("b=%d\n", b);

    // putchar 返回值不等于参数
    int r = 0x1070;
    printf("\n0x%x\n", r);
    r = putchar(r);        // 写字符 ch 到 stdout 。在内部，字符于写入前被转换到 unsigned char
    printf("\n0x%x\n", r);

    return 0;
}
