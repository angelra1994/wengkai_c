#include <stdio.h>

/** C中有如下的按位运算的运算符
 ·&     按位的与         让某一位或某些位为0: a & 0xFE; 取一个数中的一段 a & 0xFF
 ·|     按位的或         使得一位或某些位为1: a | 0x01; 把两个数拼起来 0x00FF & 0xFF00
 ·~     按位取反         ~Xi = 1 - Xi*
  ·^    按位的异或       a ^ b ^ b = a     一个数和0异或是它本身；Xi ^ 0 = Xi； b ^ b = 0
 ·<<    左移            x << = i;  x *= 2       x << = n  x *= 2的n次幂
 ·>>    右移            对于unsigned的类型，左边填0，对于signed的类型，左边填原来的最高位(保持符号位不变)
 */
int getNumberof1(int n);
void bit_print(int number);

int main(int argc, char const *argv[])
{
    unsigned char c = 0xA5;  //1010 0101
    printf("   c=%hhx(%%hhx)\n", c);
    printf("  ~c=%hhx\n", ~c);
    printf("  -c=%hhx\n", -c);   
    printf("   c=%x(%%x)\n", c);
    printf("   c=%d(%%d)\n", c);
    printf("c<<2=%hhx(%%hhx)\n", c<<2);   
    printf("c<<2=%x(%%x)\n", c<<2);   
    printf("c<<2=%d(%%d)\n", c<<2);   

    printf("%d\n", getNumberof1(c));

    int a = 0x80000000;
    unsigned int b = 0x80000000;
    printf("a=%d, b=%u\n", a, b);
    printf("a>>1=%d, b>>1=%u\n", a>>1, b>>1);
    printf("a>>2=%d, b>>2=%u\n", a>>2, b>>2);
    printf("a>>3=%d, b>>3=%u\n", a>>3, b>>3);
    printf("a<<1=%d, b<<1=%u\n", a<<1, b<<1);
    printf("a<<-1=%d, b<<-1=%u\n", a<<-1, b<<-1);  // 为定义的行为。不同的编译器可能会报错


    bit_print(a);  //0x80000000;
    bit_print(5);
    bit_print(0xFF);
    bit_print(0xFFFFFFFF);
    bit_print(0x0FFFFFFF);
    bit_print(0xAAAAAAAA);
    bit_print(0x55555555);
    return 0;
}

int getNumberof1(int n) {
    int count = 0;
    while (n != 0)
    {
        if ((n&1) == 1) {
            count ++;
        }
        n >>= 1;
    }
    return count;
}

void bit_print(int number) 
{
    printf("number=%d(signed dec), number=%u(unsigned dec), number=0b", number, number);
    unsigned mask = 1u << 31;  // 0x80000000
    for ( ; mask; mask >>= 1)
    {
        printf("%d", number & mask ? 1:0);
    }
    printf("(bin)\n");
}


