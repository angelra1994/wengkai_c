#include <stdio.h>

int main(int argc, char const *argv[]) 
{
    struct date
    {
        int month;
        int day;
        int year;
    };
    
    struct date today;
    today.month = 25;
    today.day = 6;
    today.year = 2024;
    printf("Today's date is %i-%i-%i", today.year, today.month, today.day);
    
    return 0;


    /**
    struct point
    {
        int x;
        int y;
    };
    struct point p1,p2;
    p1和p2都是point，里面有x和y的值

    struct {
        int x;
        int y;
    } p1,p2;
    p1和p2都是一种无名结构，里面有x和y
    p1和p2都是point，里面有x和y的值

    struct point {
        int x;
        int y;
    } p1,p2;
    p1和p2都是point，里面有x和y的值


    1和3都声明了结构point。但是第2种形式没有声明point，只是定义了两个变量
     */
    
}