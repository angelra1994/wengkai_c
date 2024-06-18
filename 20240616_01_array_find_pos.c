#include <stdio.h>

/**
 * 找出key在数组a中的位置
 * @param key 要找的数字
 * @param a 要寻找的数组
 * @param length 数组a的长度
 * @return int 如果找到。返回key在a中的位置；否则返回-1
 * 
 * 数组元素本身不能被赋值
 * 要把一个数组的元素交给另外一个数组，必须使用遍历
 */
int search(int key, int a[], int length);

int main(int argc, char const *argv[])
{
    // 数组的集成初始化
    int a[] = {2, 3, 6, 7, 11, 13, 12, 3, 56, 32, 4, 6, 12,};
    int a[13] = {2};              // 需要指定长度，其他位置成员都是0
    int a[] = {[1]=2,3,[5]=6}; // C99 only。给指定的位置赋值，数组成员中很多是0，部分不是0

    {
        printf("%lu\n", sizeof a);
        int i;
        for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        {
            printf("%d\t", a[i]);
        }
        printf("\n");
    }


    // int x;
    // int loc;
    // printf("请输入一个数字");
    // scanf("%d", &x);
    // loc = search(x, a, sizeof(a)/sizeof(a[0]));
    // if (loc != -1) {
    //     printf("%d在%d位置上", x, loc);
    // } else {
    //     printf("%d不存在", x);
    // }


    return 0;
}

/**
 * 数组作为函数参数时候，往往必须再传入一个参数记录数组大小
 * 不能在[]中给出数组的大小，不能用 sizeof(a)/sizeof(a[0])计算数组的大小
 */
int search(int key, int a[], int length)
{
    int ret = -1;
    int i;
    for (i = 0; i < length; i++)
    {
        if (a[i] == key) {
            ret = i;
            break;
        }
    }

    return ret;
}