#include <stdio.h>

struct point
{
    int x;
    int y;
};

void getStruct(struct point);
struct point getStruct1(void);
struct point * getStruct2(struct point *);
void print(const struct point *); 
void output(struct point);

int main(int argc, char const *argv[]) 
{
    // struct point o = {0, 0};
    // getStruct(o);

    /*
    C在函数调用的时候是传值的，函数中的p与main的o是不同的。
    函数中的p只是新建一个struct point变量，并复制调用处参数o的值
    */
    // output(o);

    // o = getStruct1();
    // output(o);

    struct point y = {0, 0};
    getStruct2(&y);
    output(y);
    output(*getStruct2(&y));
    print(getStruct2(&y));
    getStruct2(&y) -> x = 0;
    *getStruct2(&y) = (struct point) {1, 2};
    return 0;   
}

void getStruct(struct point p)
{
    scanf("%d", &p.x);
    scanf("%d", &p.y);
    printf("%d, %d\n", p.x, p.y);
}

struct point getStruct1(void)
{
    struct point p;
    scanf("%d", &p.x);
    scanf("%d", &p.y);
    printf("%d, %d\n", p.x, p.y);
    return p;
}

struct point* getStruct2(struct point *p)
{
    scanf("%d", &p->x);  // scanf("%d", (*p).x);
    scanf("%d", &(*p).y);
    printf("%d, %d\n", p->x, p->y);
    return p;
}

void print(const struct point * p) 
{
    printf("%d, %d\n", p->x, p->y);
}

void output(struct point p) 
{
    printf("%d, %d\n", p.x, p.y);
}
