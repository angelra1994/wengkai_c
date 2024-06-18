#include <stdio.h>

int main(int argc, char const *argv[])
{
    int max_num = 100;
    int is_prime[max_num];
    int i;
    int x;
    for (i = 0; i < max_num; i++)
    {
        is_prime[i] = 1;
    }
    

    for (x = 2; x < max_num; x++)
    {
        if (is_prime[x]) {
            for (i = 2; i*x < max_num; i++)
            {
                is_prime[i*x] = 0;
            }
        }
    }

    for (i = 2; i < max_num; i++)
    {
        if(is_prime[i]) {
            printf("%d\t", i);
        }
    }
    printf("\n");
    

    return 0;
}
