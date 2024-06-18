#include <stdio.h>


int main(int argc, char const *argv[])
{
    const int num = 10;
    int x;
    int count[num];

    for (int i = 0; i < num; i++)
    {
        count[i] = 0;
    }
    scanf("%d", &x);
    while (x != -1)
    {
        if (x >= 0 && x <= 9) {
            count[x] ++;
        }
        scanf("%d", &x);
    }
    
    for (int i = 0; i < num; i++)
    {
        printf("%d: 出现了%d次\n", i , count[i]);
    }
    

    return 0;
}
