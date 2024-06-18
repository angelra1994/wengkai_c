#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned char a = 0xe4, b;
    printf("a=%c, a=%d, a=0x%x\n", a, a, a);
    b = a<<3;
    
    printf("b=%c, b=%d, b=0x%x\n", b, b, b);

    a = 0xe4;
    b = a>>3;
    printf("b=%c, b=%d, b=0x%x\n", b, b, b);


    char x = -10;        //  10 的二进制:    0b 0000 1010
                         //     按位取反：   0b 1111 0101
                         // -10 补码形式：   0b 1111 0110    
    char y = x >> 3;     // >>3 带符号位右移 0b 1111 1110 



    // y=0x%x 整型提升，y=0xfffffffe  按照4字节进行输入
    printf("y=%c, y=%d, y=0x%x\n", y, y, y);
    return 0;
}