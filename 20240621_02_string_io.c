#include <stdio.h>

/*
char *t = "tilte"; 
char *s; 
s = t; //并没有产生新的字符串，只是让指针s指向了t所指向的字符串，对s的任何操作就是对t做的
*/

void f(void)
{
    char word1[8];
    char word2[8];
    // scanf("%s", word1);   // scanf 读入一个单词（到空格、tab或回车为止）
    // scanf("%s", word2);   // 此处的scanf是不安全的。因为不知道要读入的内容的长度 (容易越界)

    // 在%和s之间的数字，表示最多允许读入多少的字符数量。需要比数组的大小小1
    scanf("%7s", word1);
    scanf("%7s", word2); 
    // /**
    //  12345678
    //  1234567## ##8
    //  * 
    //  */
    printf("%s## ##%s\n", word1, word2);


    /**
     1. char buffer[] = """";
        这是一个空字符串，buffer[0] = '\0';
     2. char buffer[] = "";  这个数组长度只有1;
     */
    char buffer[] = """";
    printf("buffer[0]=%c(%%c),buffer[1]=%c(%%c),buffer[2]=%c(%%c)\n", buffer[0], buffer[1], buffer[2]);
    printf("buffer[0]=%d(%%d),buffer[1]=%d(%%d),buffer[2]=%d(%%d)\n", buffer[0], buffer[1], buffer[2]);

}

int main(int argc, char const *argv[]) 
{
    f();  // 如果scanf的字符串长度超过了7个。容易出现 Abort trap(视编译器而定)
    return 0;
}
