#include <stdio.h>

/**
联合
union AnElt {
    int i;
    char c;
} elt1, elt2;

所有成员共享一个空间
同一时间，只有一个成员是有效的
union的大小是其最大成员的内存占用大小

初始化，对第一个成员做初始化


elt1.i = 4; 
elt2.c = 'a';
elt2.i = 0xDEADBEEF;

| c|
|EF|DE|AD|DE| 
|     i     |

sizeof(union ...) = sizeof(每一个成员最大值)。一个联合体所有成员占据同一块内存空间

 */

typedef union {
    int i;
    char ch[sizeof(int)];
} CHI;


int main(int argc, char const *argv[]) 
{
    union AnElt {
        int i;
        char c;
    } elt1, elt2;

    elt1.i = 4; 
    elt2.c = 'a';  // 97 -> 0X61
    elt2.i = 0xDEADBEEF;
    printf("elt1.c=0X%X\n", elt1.c);  // elt1.c=0X4
    printf("elt2.c=0X%X\n", elt2.c);  // elt2.c=0XFFFFFFEF

    CHI chi;
    int i;
    chi.i = 1234;
/**
chi
  i |00|00|04|D2| 
 ch  [0][1][2][3]
 chi.i = 1234 -> 0X04D2
 ch[0]=D2
 ch[1]=04
 ch[2]=00
 ch[3]=00
 X86的机器是小端机器，低位字节在前

 可以使用union 获取一个整数内部的各个字节。第一个变量可以是int，double，float类型
 */

    for (i = 0; i < sizeof(int); i++)
    {
        printf("%02hhX", chi.ch[i]);
    }
    printf("\n");
    return 0;  
}
