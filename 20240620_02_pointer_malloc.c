#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    int number;
    int* a;
    int i;
    printf("请输入数量：");
    scanf("%d", &number);
    // int a[number];

    /*c99之前写法，给int* 的指针a 分配 number个连续的int内存空间。当作数组使用*/
    a = (int*)malloc(number*sizeof(int));
    /**
     * 如果空间不够了，malloc申请失败。返回0地址或者叫做NULL
     * 
     */

    for (i = 0; i < number; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for (i = number - 1; i >= 0; i--) 
    {
        printf("a[%d]=%d\t",i, a[i]);
    }
    /*把 malloc 借来的内存还掉*/
    free(a);

    void *p;
    int cnt = 0;
    while ((p=malloc(100*1024*1024)))
    {
        cnt++;
    }
    printf("分配了%d00MB的空间\n",cnt);  //分配了65400MB的空间
    return 0;
}
