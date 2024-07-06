#include <stdio.h>

/**
C语言中typedef关键字来声明一个已有的数据类型的新名字

typedef int Length;
使得Length(新的名字) 成为 了int(原来)类型的别名

typedef 声明了新的名字
typedef long int64_t; // 重载已有的类型名字，新名称的含义更清晰，具有移植性
typedef struct ADate {
    int month;
    int day;
    int year;
} Date;               // 简化了复杂的名字
int64_t i = 100000000000000000;
Date d = {9, 9, 2019};


typedef struct {
    int month;
    int day;
    int year;
} Date;   // 这样的一个 struct我们起了一个别名叫 Date

typedef int Length; // Length就等价与int类型
typedef *char[10] Strings; // Strings 是10个字符串的数组类型

typedef struct node {
    int data;
    struct node *next;
} aNode; 
或
typedef struct node aNode; // 这样用aNode就可以代替 struct node
*/

int main(int argc, char const *argv[]) 
{
        typedef int Length; // Length就等价与int类型
        // typedef *char[10] Strings; // Strings 是10个字符串的数组类型

        typedef struct node {
            int data;
            struct node *next;
        } aNode; 

        typedef struct node aNode; // 这样用aNode就可以代替 struct node

    
   
    
    return 0;   
}