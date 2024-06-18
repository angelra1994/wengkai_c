#include <stdio.h>


void f(void);

int main(int argc, char const *argv[])
{
    f();
    printf("here\n");


    return 0;
}

void f()
{
    int a[10];
    //llvm 严格的编译器
    a[10] = 0;

}