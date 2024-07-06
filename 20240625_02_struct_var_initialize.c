#include <stdio.h>

struct date
{
    int month;
    int day;
    int year;
};

int main(int argc, char const *argv[]) 
{
    struct date today = {07, 25, 2024}; 
    struct date this_month = {.month=6, .year=2024}; 
    printf("Today's date is %i-%i-%i\n", today.year, today.month, today.day);
    printf("This month's date is %i-%i-%i\n", this_month.year, this_month.month, this_month.day);
    
    /**
     要访问整个结构体变量，直接使用结构变量的名字
     对于整个结构变量，可以做赋值，取地址，也可以传递给函数参数
     1. p1 = (struct point) {5, 10}; // p1.x = 5, p1.y = 10
     2. p1 = p2; // p1.x = p2.x, p1.y = p2.y
     而数组无法做这两种赋值计算(数组变量是const的玩意)
     */

    struct date day1 = {06, 06, 2006};
    struct date day2;
    day2 = (struct date){07, 07, 2007};
    struct date day3 = day1;
    printf("day3's date is %i-%i-%i\n", day3.year, day3.month, day3.day);
    day3.day = 3;
    printf("day3's date is %i-%i-%i\n", day3.year, day3.month, day3.day);
    printf("day1's date is %i-%i-%i\n", day1.year, day1.month, day1.day);
    printf("day2's date is %i-%i-%i\n", day2.year, day2.month, day2.day);

    /** 结构指针
     * 和数组不同，结构变量的名字并不是结构变量的地址，必须使用&运算符
     * struct date *pDate = &today;
     * 
     * 不加&，编译报错如下
     * incompatible types when initializing type 'struct date *' using type 'struct date'
     */
    struct date *pDate = &today;
    printf("pDate->day is %i\n", pDate->day);
    printf("address of today is %p\n", pDate);

    return 0;


   
}