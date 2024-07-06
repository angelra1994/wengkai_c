#include <stdio.h>

/** 位段
把一个int的若干位组合成一个结构
struct {
    unsigned int leading : 3;
    unsigned int FLAG1 : 1;
    unsigned int FLAG2 : 1;
    int trailing : 11;
}

可以直接用位段的成员名称来访问，比移位、与、或方便
编译器会安排其中的位的排列，不具有可移植性
当所需的位超过一个int时会采用多个int
 */

// void print_bin(unsigned int number);
void print_bin(unsigned int);

struct U0 {
    unsigned int leading : 3;
    unsigned int FLAG1 : 1;
    unsigned int FLAG2 : 1;
    // int trailing : 27;
    int trailing : 32;
};

int main(int argc, char const *argv[])
{
    struct U0 uu;
    uu.leading = 2;
    uu.FLAG1 = 0;
    uu.FLAG2 = 1;
    uu.trailing = 0;
    printf("sizeof(uu)=%lu\n", sizeof(uu));   // 超过32给bit了，用两个int 去表示 sizeof(uu)=8
    print_bin(*(int*)&uu);     // *(int*)&uu 不道德的强转
    return 0;
}

void print_bin(unsigned int number)
{
    unsigned mask = 1u << 31;  // 0x80000000
    for ( ; mask; mask >>= 1)
    {
        printf("%d", number & mask ? 1:0);
    }
    printf("(bin)\n");
}

