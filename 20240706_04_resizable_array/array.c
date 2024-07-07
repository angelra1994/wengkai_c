#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "array.h"

// typedef struct {
//     int *array;
//     int size;
// } Array;

/*
Array* array_create(Array* a, int init_size)
{
    // 1. a == NULL?
    // 2. a 是一个有效的Array， 先free(a)？
    a -> size = init_size;
    Array arr;
    arr.array = (int*)malloc(sizeof(int)*(a -> size));
    a -> array = &arr;
    return a;
}
*/

Array array_create(int init_size)
{
    Array a;
    a.size = init_size;
    a.array = (int*)malloc(sizeof(int)*a.size);
    return a;      // 此处 array是本地变量，函数返回Array的指针，则本地变量无效(指针应该作为参数传入)
}

void array_free(Array *a)
{
    free(a -> array);
    a->array = NULL;
    a -> size = 0;
}

/*封装*/
int array_size(const Array *a)
{
    return a -> size;
}

int* array_at(Array *a, int index)
{
    if(index >= a->size) {
        /* 当 index 和 a->size 相等时，index++ 场景，都会触发 array_inflate(内部 O(N)复杂度) */
        //array_inflate(a, index - a->size + 1);

        array_inflate(a, (index/BLOCK_SIZE + 1) * BLOCK_SIZE - a->size);
    }
    return &(a->array[index]);
}

int array_get(const Array *a, int index)
{
    return a->array[index];
}

void array_set(Array *a, int index, int value)
{
    a->array[index] = value;
}

void  array_inflate(Array *a, int more_size)
{
    // 传入a->array 是 malloc出来的数组(a->array 是数组首地址)，无法增长对应内存空间大小
    int *p = (int*)malloc(sizeof(int) * (a->size + more_size));
    
    
	memcpy(p, a->array, (a->size) * sizeof(int));
//    int i;
//    for (i = 0; i < a->size; i++)
//    {
//        p[i] = a->array[i];
//    }

    printf("p[0]=%d\n", p[0]);
    printf("p[1]=%d\n", p[1]);
    printf("p[2]=%d\n", p[2]);
	
	
	printf("p[98]=%d\n", p[98]);
	printf("p[99]=%d\n", p[99]);
	printf("p[100]=%d\n", p[100]);

    printf("sizeof(a->array)=%llu, a->array(%%p)=%p, sizeof(p)=%llu, p(%%p)=%p\n", sizeof(a->array), a->array, sizeof(p), p);

   
    free(a->array);
    a->array = p;
    a->size += more_size;

}

int main(int argc, char const *argv[])
{
    Array a = array_create(100);
    printf("array_size(&a)=%d\n", array_size(&a));
    printf("a.size=%d\n", a.size);
    
    *array_at(&a, 0) = 10;        // 返回的是一个指针，*得到指向的变量。作为左值，进行赋值 (即把右值10写到 a.array[0])    
    printf("a.array[0]=%d\n", *array_at(&a, 0));
    array_set(&a, 1, 11);
    printf("a.array[1]=%d\n", array_get(&a, 1));
    

    /*
    99 100 101 -1

    p[0]=10
    p[1]=11
    p[2]=-39616960
    sizeof(a->array)=8, a->array(%p)=0000027EFDA405C0, sizeof(p)=8, p(%p)=0000027EFDA42780
    
    a.array[98]=0
    a.array[99]=0
    a.array[100]=100
    a.array[101]=101
    a.array[102]=0
    a.array[103]=0
    */
    int number = 0;
    int cnt = 99;
    while (number != -1)
    {
        // scanf("%d", array_at(&a, cnt++));
        scanf("%d", &number);
        if ( number != -1) {
            *array_at(&a, cnt++) = number;
        }
    }
    printf("a.array[%d]=%d\n", 98, array_get(&a, 98));
    printf("a.array[%d]=%d\n", 99, array_get(&a, 99));
    printf("a.array[%d]=%d\n", 100, array_get(&a, 100));
    printf("a.array[%d]=%d\n", cnt-1, array_get(&a, cnt-1));
    printf("a.array[%d]=%d\n", cnt, array_get(&a, cnt));
    printf("a.array[%d]=%d\n", cnt+1, array_get(&a, cnt+1));
    

    array_free(&a);         // 需要free a.array
    return 0;
}
