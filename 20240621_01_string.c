#include <stdio.h>

/*
char word[] = {'H', 'E', 'L', 'L', 'O'};       字符数组，不能用字符串的方式去计算

char word[] = {'H', 'E', 'L', 'L', 'O', '\0'}; C语言中可以用字符串运算方式的字符数组.结尾0表示字符串结束，非字符串的内容
char word[] = {'H', 'E', 'L', 'L', 'O', 0};     
字符串以数组形式存在，以数组或指针方式进行访问

字符串变量。编译器会补上结尾的 '\0'
char *str = "Hello";
char word[] = "Hello";
char line[10] = "Hello";

字符串常量
"Hello"  字符串的字面量，字符串的常量。会被编译器变成一个字符数组（并补上结束的0，长度是6）放在某处，
*/

int main(int argc, char const *argv[])
{
/**
char *s = "Hello World";
s是一个指针，初始化位指向一个字符串常量（这个字符串常量位于代码段的内存位置，只读）
由于这个常量所在的地方，实际上s是const char* s, 但是由于历史原因。编译器接受不带 const的 写法
但是试图对s所指的字符串做写入操作会导致严重后果。

如果需要修改字符串，需要使用数组。将这个字符串常量拷贝到 本地变量区
char s[] = "Hello World";
 */
    int i =0;
    char *s1 = "Hello World";
    printf("s1[0]=%c\n", s1[0]);
    char *s2 = "Hello World";
    char s3[] = "Hello World";
    printf("&i=%p\n", &i);
    printf("s1=%p\n", s1);
    printf("s2=%p\n", s2);
    printf("s3=%p\n", s3);
    s3[0] = 'B';
    printf("Here!,s3[0]=%c\n", s3[0]);
/**
char *str = "Hello";
char word[] = "Hello";
数组（构造一个字符串）：这个字符在这里。作为本地变量空间自动被回收
指针（处理一个字符串）：这个字符串不知道在哪里。用于处理参数，动态分配空间

1.字符串可以表达为char*的形式
2. char*不一定是字符串。表示有一个指针指向一个字节或者一串连续的字节（可以指向一个字符，或者字符数组）
只有当 char* 指向的字符数组有结尾的0，才能说它所指的是字符串
 * 
 */


    s1[0] = 'B';
    printf("Here!,s1[0]=%c\n", s1[0]);


    return 0;
}
