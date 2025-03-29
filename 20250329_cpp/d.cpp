#include <stdlib.h>
#include <string.h>
#include <stdio.h>

class TA
{
public:
    int x;
    char y;
    char *z;
};

int main(int argc, char const *argv[])
{
    TA a, b;
    a.x = 1;
    a.y = 2;
    a.z = (char *)malloc(10);
    strcpy(a.z, "0123456789");

    TA *pa, *pb;
    pa = &a;
    pb = &b;
    printf("a.z = %s\n", a.z);
    printf("pb->z = %p\n", pb->z);
    return 0;
}
