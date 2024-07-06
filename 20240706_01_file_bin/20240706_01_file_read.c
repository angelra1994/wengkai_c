#include <stdio.h>
#include "student.h"

void read(FILE *fp, int index);
// void read(FILE *, int);



/** 在文件中定位
long ftell(FILE *stream)                                
    long __cdecl ftell(FILE *_File);
int fseek(FILE *stream, long offset, int whence);       
    int __cdecl fseek(FILE *_File,long _Offset,int _Origin);
 SEEK_SET: 从头开始
 SEEK_CUR: 从当前位置开始
 SEEK_END: 从尾开始（倒过来）

 */


int main(int argc, char const *argv[])
{
    FILE *fp = fopen("student.data", "r");
    if (fp) {
        fseek(fp, 0L, SEEK_END);  // 执行完后，当前位置在文件尾部。0L的位置是文件位置指针从文件末尾向后移动0个字节
        long size = ftell(fp);    // 得到现在所在的位置
        int number = size/sizeof(Student);
        int index = 0;
        printf("有%d个数据，你要看第几个:", number);
        scanf("%d", &index);
        read(fp, index - 1);
        fclose(fp);
    }
    return 0;
}

/** 可移植性
这样的二进制文件不具有可移植性
在 int 为32位的机器上写成的数据文件，无法直接在int为64的机器正确读出
解决方案之一时放弃使用int，而是typedef具有明确大小的类型
更好的方案是使用文本
 */


void read(FILE *fp, int index)
{
    fseek(fp, index*sizeof(Student), SEEK_SET); // 从文件头开始，往前走 index*sizeof(Student) 字节 位置
    Student stu;
    if (fread(&stu, sizeof(Student), 1, fp) == 1) {
        printf("第%d个学生: ", index + 1);
        printf("\t姓名: %s", stu.name);
        printf("\t性别: ");
        switch (stu.gender)
        {
            case 0: printf("男生"); break;
            case 1: printf("女生"); break;
            case 2: printf("其他"); break;
        }
        printf("\t年龄: %d\n", stu.age);
    }
}