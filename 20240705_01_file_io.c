#include <stdio.h>

/*
文件输入输出
用 > 和 < 做重定向   (程序运行时候的重定向，< 和 > 利用文件做输入输出)

gcc .\20240705_01_file_io.c -o file_io

.\file_io.exe
12345                          // 输入
12345                          // 输出
ret(scanf)=1, ret(printf)=6    // 输出

.\file_io.exe > 12.out
12345

more 12.out

echo '12345' > 12.in
cat .\12.in

./file_io.exe < 12.in
12345
ret(scanf)=1, ret(printf)=6

./file_io.exe < 12.in > 12.out

*/

/* printf的返回值：输出的字符数*/
/* scanf的返回值：输入的项目数*/
int main(int argc, char const *argv[])
{
    int num;
    int i1 = scanf("%i", &num);                           // 1234
    int i2 = printf("%d\n", num);                         // 1234
    printf("ret(scanf)=%d, ret(printf)=%d\n", i1, i2);    // ret(scanf)=1, ret(printf)=5  还有一个\n

    return 0;
}
