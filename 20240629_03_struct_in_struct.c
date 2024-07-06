#include <stdio.h>

/**
结构中的结构
struct dateAndTime
{
    struct date sdate;
    struct time stime;
};
 */

/**
 嵌套的结构
struct point
{
    int x;
    int y;
};

struct rectangle
{
    struct point pt1;
    struct point pt2;
};

如有变量 struct rectangle r; 则有 r.pt1.x, r.pt1.y, r.pt2.x, r.pt2.y

如有定义变量: 
struct rectangle r, *rp;
rp = &r;
则如下四种形式是等价的:
r.pt1.x
rp->pt1.x
(r.pt1).x
(rp->t1).x
但是没有 rp->pt1->x 因为pt1不是指针
*/

struct point
{
    int x;
    int y;
};

struct rectangle
{
    struct point pt1;
    struct point pt2;
};

void printRectangle(struct rectangle);

int main(int argc, char const *argv[]) 
{
    int i;
    struct rectangle rects[] = {
        {{1, 2}, {3, 4}},
        {{5, 6}, {7, 8}}
    };  // 2 rectangle
    for (i = 0; i < sizeof(rects)/sizeof(struct rectangle); i++)
    {
        printRectangle(rects[i]);
    }
    
   
    
    return 0;   
}

void printRectangle(struct rectangle r)
{
    printf("<%d, %d> to <%d, %d>\n", r.pt1.x, r.pt1.y, r.pt2.x, r.pt2.y);
}
