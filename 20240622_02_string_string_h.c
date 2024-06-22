#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
string.h

strlen,   size_t __cdecl strlen(const char *_Str);  返回_Str的字符串长度(不包含结尾的0)  
strcmp,   int __cdecl strcmp(const char *_Str1,const char *_Str2); 比较两个字符串
          0: s1 == s2
          1: s1 > s2
          -1:s1 < s2

strcpy,   char * __cdecl strcpy(char * __restrict__ _Dest,const char * __restrict__ _Source);
          1. 把src的字符串拷贝到dst, restrict表明src和dst不重叠(C99)。内存区域不能有重叠
          2. 返回dst。为了能链起代码来
strcat,   char * __cdecl strcat(char * __restrict__ _Dest,const char * __restrict__ _Source);
          1. 把src拷贝到dst后面，追加方式。拼接成为一个长的字符串
          2. 返回dst, dst必须有足够的空间   dst[strlen[dst]] = src[0]

strcpy 和 strcat 都可能出现安全问题。如果目的地没有足够空间会出现越界问题
安全版本， _Count最多能拷贝过去的长度，多了会掐掉
  char *strncpy(char * __restrict__ _Dest,const char * __restrict__ _Source,size_t _Count) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  char *__cdecl strncat(char * __restrict__ _Dest,const char * __restrict__ _Source,size_t _Count) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _MaxCount  用于判断前 _MaxCount字符是否一致
  int __cdecl strncmp(const char *_Str1,const char *_Str2,size_t _MaxCount);

字符串中找字符
strchr,   _CONST_RETURN char *__cdecl strchr(const char *_Str,int _Val);  
          1. 在字符串中找_Val第一次出现的位置(指向第一个 _Val的指针)
          2. 返回 NULL表示没有找到
strrchr,  _CONST_RETURN char *__cdecl strrchr(const char *_Str,int _Ch);
          1. 在字符串中找_Ch最后一次出现的位置(指向最后一个 _Ch的指针)
          2. 返回 NULL表示没有找到

字符串中找字符串
strstr,    _CONST_RETURN char *__cdecl strstr(const char *_Str,const char *_SubStr);
strcasestr, 不是C语言标准库的一部分，而是一些特定系统或库提供的函数，比如GNU C库（glibc）。strcasestr 函数用于在字符串中查找子串，与 strstr 函数类似，但它不区分大小写。
*/

int my_len(const char*);
int my_cmp(const char*, const char*);
int my_cmp1(const char*, const char*);
char* my_cpy(char*, const char*);
char* my_cpy1(char*, const char*);
char* my_cat(char*, const char*);
char* my_cat1(char*, const char*);

/* argv[0] 是命令本身，当使用Unix符号链接时，反映符号链接的名字 */
int main(int argc, char const *argv[]) 
{
    // char line[] = "Hello!你好";
    char line[] = "Hello!你好";
    printf("strlen=%lu\n", strlen(line));  // 12
    printf("my_len=%lu\n", my_len(line));  // 12
    printf("sizeof=%lu\n", sizeof(line));  // 13


    char s1[] = "abc";
    char s2[] = "abc";
	/* 不同编译器结果不一致，此处或许会有编译告警 */ 
    printf("s1==s2: %d\n", s1 == s2);     // array comparison always evaluates to false [-Wtautological-compare]
    printf("strcmp=%d\n", strcmp(s1, s2));
    printf("my_cmp=%d\n", my_cmp(s1, s2));
    s2[0] = 'b';  
    printf("strcmp=%d\n", strcmp(s1, s2));// "abc" < "bbc"  返回-1
    printf("my_cmp=%d\n", my_cmp(s1, s2));// "abc" < "bbc"  返回-1
    s2[0] = 'A';
    printf("strcmp=%d\n", strcmp(s1, s2));// "abc" > "Abc"  返回32
    printf("my_cmp=%d\n", my_cmp1(s1, s2));// "abc" > "Abc"  返回32
    printf("a-A=%d\n", 'a'-'A');          //  97 - 65      

    char* ret;
    char* src = "hello!";
    char* dst = (char*)malloc(strlen(src) + 1);  
//    char src[] = "hello!";
//	char dst[100];  
    ret = strcpy(dst, src); 
    printf("strcpy(dst, src), *dst=%s, ret=%s\n", dst, ret);
    char dst1[100];
    ret = my_cpy(dst1, src); 
    printf("my_cpy(dst1, src), *dst=%s, ret=%s\n", dst1, ret);
    ret = my_cpy1(dst1, src); 
    printf("my_cpy1(dst1, src), *dst1=%s, ret=%s\n", dst1, ret);

    char all[1000] = "start";
    // char* all = "start";   strcat restrict 限制了 *all 和 *append 不能有重叠
    char* append = "append";
    printf("strlen(all)=%d, sizeof(all)=%d\n", strlen(all), sizeof(all));
    ret = strcat(all, append); 
    printf("strcat(all, append), *all=%s, ret=%s\n", all, ret);
	printf("strlen(all)=%d, sizeof(all)=%d\n", strlen(all), sizeof(all));
    ret = my_cat(all, append); 
    printf("my_cat(all, append), *all=%s, ret=%s\n", all, ret);
    printf("strcat(all, append), *all=%s, ret=%s\n", all, ret);
	printf("strlen(all)=%d, sizeof(all)=%d\n", strlen(all), sizeof(all));
    ret = my_cat1(all, append); 
    printf("my_cat1(all, append), *all=%s, ret=%s\n", all, ret);


    char s[] = "hello!";
    char *p = strchr(s, 'l');
    printf("p: %s\n", p);
    char *t1 = (char *)malloc(strlen(p) + 1);
    strcpy(t1, p);
    printf("t1: %s\n", t1);
    free(t1);
    char *q = strchr(p+1, 'l');
    printf("q: %s\n", q);
    char c = *p;
    *p = '\0';
    char *t2 = (char *)malloc(strlen(s) + 1);
    strcpy(t2, s);
    printf("t2: %s\n", t2);
    free(t2);
    printf("s *p=0: %s\n", s);
    *p = c;
    printf("s *p=c: %s\n", s);
    return 0;
    
}


int my_len(const char* s) {
    int idx = 0;
    // while (s[idx] != '\0')
    while (*(s++) != '\0')
    {
        idx ++;
    }
    return idx;
}

int my_cmp(const char* s1, const char* s2) {
    int idx = 0;
    while (s1[idx] == s2[idx] && s1[idx] != '\0')
    // while (1)
    {
        // if(s1[idx] != s2[idx]) {
        //     break;
        // } else if (s1[idx] == '\0'){
        //     break;
        // }
        idx ++;
     }
     return s1[idx] - s2[idx];
}

int my_cmp1(const char* s1, const char* s2) {
    while (*s1 == *s2 && *s1 != '\0')
    {
        s1++;
        s2++;
     }
     return *s1 - *s2;
}


char* my_cpy(char * dst, const char * src) {
    int idx = 0;
    while (src[idx])
    // while (src[idx] != '\0')
    {
        dst[idx] = src[idx];
        idx++;
    }
    dst[idx] = '\0';
    return dst;
}

char* my_cpy1(char* dst, const char * src) {
    char* ret = dst;
    while (*src != '\0') {
        *dst = *src;
        dst++;
        src++;
    }

    // while (*src != '\0') {
    //     *dst++ = *src++;
    // }

    // while (*src) {
    //     *dst++ = *src++;
    // }

    // while (*dst++ = *src++) {
    //     ;
    // }
    *dst = '\0';
    return ret;
}

char* my_cat(char* dst, const char * src) {
    int idx = 0;
	int offset = strlen(dst);
    while (src[idx])
    // while (src[idx] != '\0')
    {
        dst[offset+idx] = src[idx];
        idx++;
    }
    dst[offset+idx] = '\0';
    return dst;
}

char* my_cat1(char* dst, const char * src) {
    // int idx = 0;
	
    // while (src[idx])
    // // while (src[idx] != '\0')
    // {
    //     dst[offset+idx] = src[idx];
    //     idx++;
    // }
    // dst[offset+idx] = '\0';


    char* ret = dst;
    dst += strlen(dst);
    while (*src != '\0') {
        *dst = *src;
        dst++;
        src++;
    }

    // while (*src != '\0') {
    //     *dst++ = *src++;
    // }

    // while (*src) {
    //     *dst++ = *src++;
    // }

    // while (*dst++ = *src++) {
    //     ;
    // }
    *dst = '\0';
    return ret;
}
