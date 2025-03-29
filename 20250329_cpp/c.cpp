#include <stdio.h>
#include <string.h>
class T
{
public:
    int x;
    char y;
    // char y2;
    // char y3;
    // char y4;
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

int main(int argc, char const *argv[])
{
    T m, n;  // 声明的时候调用了构造函数
    // printf("%d %p %s\n", m.x, m.z, m.z); m.z

    m.x = 1;
    m.y = '2';
    m.z = new char(10);       // 堆里面的
    strcpy(m.z, "012345678"); // 常量区

    // x 占用 [4]
    // y 占用 [1] y2-y4[3], c语言结构体的自然对齐
    // z 占用 [8] --> 指向了长度为 [10] 的内存
    printf("sizeof(m)=%ld\n", sizeof(m));
    printf("m.x = %d\n", m.x);  // 1
    // 01 00 00 00 
    // 50 00 00 00
    // 8个字节的指针内容， -->  48 49 50 51 52 53 54 55 56 
    printf("m.y=%d(%%d), m.y=%c(%%c)\n", *(&m.x + 1), *(&m.x + 1));  // '2'
    printf("m.z=%s, m.z=%s, line:%d\n", m.z, *(char**)(&m.x + 2), __LINE__);
    printf("m.z=%s, m.z=%p, line:%d\n", m.z, (char*)(&m.x + 2), __LINE__);
    printf("m.z=%p, m.z=%p, line:%d\n", m.z, *(char*)(&m.x + 2), __LINE__);
    printf("%p %p, line:%d\n", &m.z, (&m.x + 2), __LINE__);
    return 0;
}
