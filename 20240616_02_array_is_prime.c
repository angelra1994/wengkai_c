#include <stdio.h>
#include <stdlib.h>

#define NUM 10

// int is_prime(int x, int know_primes[], int num_of_know_primes);
int is_prime(int, int[], int);

int main(int argc, char const *argv[])
{
    const int num = NUM;
    int prime[NUM] = {2};
    int count = 1;
    int i = 3;
    while (count < num)
    {
        if (is_prime(i, prime, count))
        {
            prime[count++] = i;
            // printf("%d\t", i);
        }

        {
            printf("i=%d\tcnt=%d\t", i, count);
            int i;
            for (i = 0; i < num; i++)
            {
                printf("%d\t", prime[i]);
            }
            printf("\n");
        }
        i++;
    }

    return 0;
}

int is_prime(int x, int know_primes[], int num_of_know_primes)
{
    int ret = 1;
    int i;
    for (i = 0; i < num_of_know_primes; i++)
    {
        if (x % know_primes[i] == 0)
        {
            ret = 0;
            break;
        }
    }
    return ret;
}
