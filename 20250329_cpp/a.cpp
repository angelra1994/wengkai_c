#include <stdio.h>
#include <string.h>
class T
{
public:
    int x;
    char y;
    char *z;
    T() { printf("Constructor T::T()\n"); z = NULL;}
    T(T &a) { 
        printf("Constructor T::T(T a)\n");
        this->x = a.x;
        this->y = a.y;
        // this->z = a.z;
        this->z = new char(10);
        memcpy(this->z, a.z, 10);
    }
    ~T()
    {
        printf("Destructor ~T(), x(%%d)=%d, y(%%c)=%c, z(%%p)=%p\n",x, y, z);
        if (z)
        {
            delete z;
            printf("delete z in ~T()\n");
        }
            
    }
    void printz() { printf("%s\n", z); }
};

/**
 * 调用时，这里会构造一个T的实例 T(T &a)。p1不推荐使用，会导致调用复制构造函数 T(T &a)
 * 调用p1的时候会创建一个类型为 T 的新对象 s，并通过复制构造函数将其初始化为传入对象（如 m）的副本。
 */
void p1(T s)
{
    printf("%s,\t", __func__);
    //x
    //y~y4
    //z[8] --> [10]
    s.printz();
    s.z[5]=0;
}

// 调用时，这里传入的是参数的引用（引用拷贝），参数是m本尊的一个别名。因此s不会额外占用栈空间
void p2(T &s)
{
    printf("%s,\t", __func__);
    s.printz();
    s.z[5]=0;
}

// 调用时，这里传入的是变量的地址
void p3(T *s)
{
    printf("%s,\t", __func__);
    s->printz();
    s->z[3]=0;
}

int main()
{
    int a = 49;
    // 49 0 0 0
    int *pa;
    int **ppa;
    // const char *pstr = "abcd";
    char *pstr;
    // 64位的系统，指针变量需要8个字节[8] --> [5]
    char *pstr2 = new char[5];
    printf("pstr2(%%s): %s, pstr2(%%p): %p, strlen(pstr2)(%%lld): %lld\n", pstr2, pstr2, strlen(pstr2));
    printf("pstr2[0](%%c): %c, pstr2[0](%%d): %d\n", pstr2[0], pstr2[0]);
    printf("pstr2[4](%%c): %c, pstr2[4](%%d): %d\n", pstr2[4], pstr2[4]);
    // [8] --> [5](堆)
    int arr[10];

    // exit(1);  会导致*pstr2指向的5个字节的内存空间(new在堆中的)没有释放。循环调用后就会一直申请。 内存泄漏:
    // 堆(全局变量是放在堆里面, new出来的)  栈(函数内部申请的变量)  常量区

    pa = &a;
    ppa = &pa;
    // [8] --> [8] --> [4]
    printf("%d %d\n", *pa, **ppa);
    printf("pa(%%p): %p, ppa(%%p): %p\n", pa, ppa);
    printf("pa[0]: %d\n", pa[0]);

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    printf("arr[0]: %d\n", arr[0]);
    printf("*arr: %d\n", *arr);
    printf("*(arr+1): %d\n", *(arr + 1));
    printf("*(arr+3): %d\n", *(arr + 3));
    printf("*(arr+4): %d\n", *(arr + 4));

    // ppa=&(&a); 表达式必须为左值或函数指示符C/C++(158), error: lvalue required as unary ‘&’ operand
    // &a的计算结果是暂存在寄存器里面的，只能获取到寄存里面的值，而获取不到寄存器的地址

    pstr = (char *)pa;
    printf("stra = %s\n", pstr);
    *(pstr + 1) = *(pstr + 1) + 50;
    // 49 50 0 0
    // a=49*1+50*256+0+0=12849
    printf("stra = %s\n", pstr);
    printf("a = %d\n", a);
    // bool float double
    pstr[3] = '4';
    // 49 50 0 52 此处pstr[2] 是 '\0',字符串结尾符号
    printf("stra = %s\n", pstr);
    pstr[2] = 1;

    // 49 50 1 52; pa[0] = 49*1+50*256+1*65536+52*16777216
    printf("stra = %s\n", pstr);
    // 1 872493617
    printf("%c %d\n", pstr[0], pa[0]);

    //[13] m n 都是存储在栈的零时变量。栈变量初始内存内容是随机的
    T m, n;  // 声明的时候调用了构造函数
    // printf("%d %p %s\n", m.x, m.z, m.z); m.z

    m.x = 1;
    m.y = '2';
    m.z = new char(10);       // 堆里面的
    strcpy(m.z, "012345678"); // 常量区

    // x 占用 [4]
    // y 占用 [1] y2-y4[3], c语言结构体的自然对齐
    // z 占用 [8] --> 指向了长度为 [10] 的内存
    printf("%lld\n", sizeof(m));
    // 01 00 00 00 
    // 50 00 00 00
    // 8个字节的指针内容， -->  48 49 50 51 52 53 54 55 56 
    printf("%d\n", *(&m.x + 1));  // '2'
    printf("%s\n", m.z);

    
    printf("%p %p\n", &m.z, (&m.x + 2));

    // return 0;

    /*  n = m;  -> m.z 和 n.z 指向了同一块堆地址
        free(): double free detected in tcache 2
        Aborted
        此处会crash掉，内存释放了两次
         if (z)
            delete z;  */
    // n = m;
    /*x[4]     1
    //y~y4[4]  '2000'
    //z[8] -->  堆内存中 new出来的 char[10] 指针
    */

    p1(m);  // 调用时候，会构造s=m的操作，在p1函数退出调用会执行s的析构函数
    printf("line %d, p1 %s\n", __LINE__, m.z);

    p2(m);
    printf("line %d, p2 %s\n", __LINE__, m.z);
 
    p3(&m);
    printf("line %d, p3 %s\n", __LINE__, m.z);

    return 0;


}
