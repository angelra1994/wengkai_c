#include <stdio.h>

/*
char **a;  a是一个指针，指向另外一个指针。另外的指针指向字符(串)，
char a[][]
*/

/* argv[0] 是命令本身，当使用Unix符号链接时，反映符号链接的名字 */
int main(int argc, char const *argv[]) 
{
    int i;
    for (i = 0; i < argc; i++)
    {
        // argv[0]:D:\lzycode\c_cpp\wengkai_c\20240621_03_string_array.exe
        printf("argv[%d]:%s\n", i, argv[i]);
    }
/*
D:\lzycode\c_cpp\wengkai_c>
D:\lzycode\c_cpp\wengkai_c>20240621_03_string_array.exe 1 23 4
argv[0]:20240621_03_string_array.exe
argv[1]:1
argv[2]:23
argv[3]:4
*/

    
    // char a[][] = {"Hello"};  // 不允许使用不完整的类型 "char [][]"C/C++(70)
    // a[0] -> char [10]。 每一个成员都是一个 char[10] 的数组
    char a[][10] = {
        "Hello1",
        "Hello1",
        // "Hello23456789",     //  initializer-string for array of 'char' is too long
    };

    // b[0] -> char*。 每一个成员都是 char* 指针
    char *b[] = {
        "Hello1",
        "Hello1",
        "Hello23456789",    
    };

}
