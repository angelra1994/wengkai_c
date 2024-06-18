#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x;
    double sum = 0;
    int cnt = 0;
    int number[100];
    scanf("%d", &x);
    while (x != -1)
    {
        number[cnt] = x;
        sum += x;
        cnt ++;
        scanf("%d", &x);
    }

    if (cnt > 0) {
        printf("avg=%f\n", sum/cnt);
    }

    for (int i = 0; i < cnt; i++)
    {
        if (number[i] > sum/cnt) {
            printf("%d\t", number[i]);
        }
    }
    
    

    return 0;
}
