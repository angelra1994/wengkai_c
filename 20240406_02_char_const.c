#include <stdio.h>

#define  M  3e-23 
#define  N  950
#define  PI 3.1415926

int main(int argc, char const *argv[])
{
    char a, b, u, v;
    a = 'F';             // F的ascii的值 70 ， 相当于a 的值为70
    b = 'A' + 2;         // 'A'的asci的值为 65 ， 65+2 = 67 , b的值为67
    u = ' ' + 'B';       // ' '是32 ， 'B'是66 ， 所以 32+66 = 98
    v = 'b' - 32;        // 'b'的ascii的值为98 ， 98-32 = 66
    printf("a=%d\n", a); // 按照十进制输出a的值
    printf("b=%d\n", b); // 按照十进制输出b的值
    printf("u=%d\n", u); // 按照十进制输出u的值
    printf("v=%d\n", v); // 按照十进制输出v的值10


    // 一个水分子的质量约为3.0*10^-23g，1夸脱水大约有950g，编写程序，要求输入水的夸脱数，然后显示这么多水中包含说少水分子。
    int num;
    printf("请输入水的夸脱数>:");
    scanf("%d", &num);
    printf("水的夸脱数，num=%d\n", num);
    float count = num * N / M;
    printf("%d夸脱的水有%e个水分子\n", num, count);

    
    int r;
    printf("请输入圆的半径>:");
    scanf("%d", &r);
    printf("圆的半径，r=%d\n", r);
    float s = r * r * PI;
    float c = 2 * r * PI;
    printf("半径为%d的圆，周长是c=%f面积是s=%f\n", r, c, s);


    return 0;
}
