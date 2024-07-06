#include <stdio.h>
#include "student.h"

/*
其实所有的文件最终都是二进制的
文本文件无非是最简答的方式可以读写的文件
二进制文件则需要专门的程序来读写的操作
文本文件的输入输出是格式化，可能经过转码

Unix常用文本文件来做数据存储和程序配置，交互式的终端（交互式的终端实现人和计算机talk）
Windows常用二进制文件，DOS能力有限，二进制更接近底层

文本的优势是方便人类读写，跨平台。缺点是输入输出要经过格式化，开销较大
二进制的缺点是人类读写困难，不跨平台。int大小不一致，大小端的问题.. 优势是程序读写快

配置：Unix使用文本，Windows使用注册表
媒体：只能是二进制的

二进制读写
  参数表：那个指针(要读或写的内存)，这单个块内存有多大，有几个这样的内存，文件指针
  size_t __cdecl fread(void * __restrict__ _DstBuf,size_t _ElementSize,size_t _Count,FILE * __restrict__ _File);
  size_t __cdecl fwrite(const void * __restrict__ _Str,size_t _Size,size_t _Count,FILE * __restrict__ _File);
FILE指针是最后一个参数，返回的是成功读写的字节数
size_t _Count，二进制文件的读写一般都是通过对一个结构变量的操作来进行的，用于表示这次的操作读写几个结构变量
*/

void getList(Student aStu[], int number);
//void getList(Student [], int);

int save(Student aStu[], int number);
// int save(Student [], int);

int main(int argc, char const *argv[])
{
    int number = 0;
    printf("输入学生数量:");
    scanf("%d", &number);
    Student aStu[number];
    getList(aStu, number);
    if (save(aStu, number)) {
        printf("保存成功");
    } else {
        printf("保存失败");
    }
    return 0;
}

void getList(Student aStu[], int number)
{
    char format[STR_LEN];
    /** printf: 向标准输出输出 */
    /** fprintf: 向文件输出 */
    /** sprintf: 向字符串输出 */
    sprintf(format, "%%%ds", STR_LEN - 1); //"%19s"  产生一个格式字符串

    int i;
    for (i = 0; i < number; i++)
    {
        printf("第%d个学生: \n", i);
        printf("\t姓名: ");
        scanf(format, aStu[i].name);       //scanf("%19s", aStu[i].name);  
        printf("\t性别(0-男, 1-女, 2-其他):");
        scanf("%d", &aStu[i].gender);
        printf("\t年龄: ");
        scanf("%d", &aStu[i].age);
    }

}

/**
$ od student.data
0000000 064172 067141 071547 067141 000000 000000 000000 000000
0000020 000002 000000 000000 000000 000014 000000 064554 064563
0000040 007400 146142 077775 000000 176234 100077 000061 000000
0000060 000002 000000 000014 000000
0000070
 */

int save(Student aStu[], int number)
{
    int ret = -1;
    FILE *fp = fopen("student.data", "w");
    if (fp) {
        ret = fwrite(aStu, sizeof(Student), number, fp);
        fclose(fp);
    }
    return ret == number;
}
