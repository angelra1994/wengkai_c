#include <stdio.h>

/*
FILE

  FILE *__cdecl fopen(const char * __restrict__ _Filename,const char * __restrict__ _Mode) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  FILE *fopen64(const char * __restrict__ filename,const char * __restrict__  mode);

  int __cdecl fclose(FILE *_File);
  _CRTIMP int __cdecl _fcloseall(void);

  int __cdecl fscanf(FILE * __restrict__ _File,const char * __restrict__ _Format,...);
  int __cdecl fprintf(FILE * __restrict__ _File,const char * __restrict__ _Format,...);
*/

/* 打开文件的标准代码
FILE* fp = fopen("file", "r");
if(fp) {
    fscanf(fp, ...);
    fclose(fp,);
} else {
    .... 
}
*/
int main(int argc, char const *argv[])
{

/*
$ ./file.exe 
12345

rm -rf 12.in

$ ./file.exe 
*/

    FILE *fp = fopen("12.in", "r");
    if (fp) {
        int num;
        fscanf(fp, "%d", &num);
        printf("%d\n", num);
        fclose(fp);
    } else {
        printf("无法打开文件\n");
    }
    return 0;
}

/*
fopen
+----+-----------------------------------------------------+
| r  | 打开只读                                            |
| r+ | 打开读写，从文件头开始                              |
| w  | 打开只写，如果不存在则新建，如果存在则清空          |
| w+ | 打开读写，如果不存在则新建，如果存在则清空          |
| a  | 打开追加，如果不存在则新建，如果存在则从文件尾开始  |
|..x | 只新建，如果文件已存在则不能打开                    |
+----+-----------------------------------------------------+
*/
