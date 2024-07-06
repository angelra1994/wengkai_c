#include <stdio.h>
#include <stdbool.h>

/**
 * 整个结构可以作为参数的值传入函数
 * 效果是在函数内部新建一个结构变量，并复制调用者的结构的值
 * 也可以返回一个结构。与数组不同
 */

struct date
{
    int month;
    int day;
    int year;
};

// bool isLeap(struct date d);
// int numberOfDays(struct date d);
bool isLeap(struct date);
int numberOfDays(struct date);


int main(int argc, char const *argv[]) 
{
    struct date today, tomorrow;
    printf("Enter today's date (mm dd yyyy)");
    scanf("%i %i %i", &today.month, &today.month, &today.year);

    if( today.day != numberOfDays(today)) {
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    } else if (today.month == 12) {
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.day = today.year + 1;
    } else {
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }
    
    printf("Tomorrow's date is %i-%i-%i", tomorrow.month, tomorrow.month, tomorrow.year);
    return 0;   
}

int numberOfDays(struct date d)
{
    int days;
    const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d.month == 12 && isLeap(d)) {
        days = 29;
    } else {
        days = daysPerMonth[d.month - 1];
    }
    return days;
}

bool isLeap(struct date d)
{
    bool leap = false;
    if ((d.day % 4 == 0 && d.year % 100 !=0) || (d.year % 400 == 0)) 
    {
        leap = true;
    }
    return leap;
}
