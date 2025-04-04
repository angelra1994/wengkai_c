#ifndef _ARRAY_H_
#define _ARRAY_H_

/**
 * provide a mechanism of resizable array of int
 * 1. Growable
 * 2. Get the current size
 * 3. Access to the elements 
 * 
 * Array array_create(int init_size);
 * void array_free(Array *a);
 * int array_size(const Array *a);
 * int* array_at(Array *a, int index);
 * void array_inflate(Array *a, int more_size);
 * int array_get(const Array *a, int index);
 * void array_set(Array *a, int index, int value);
 */


const int BLOCK_SIZE = 20;

typedef struct {
    int *array;
    int size;
} Array;

Array array_create(int init_size);
void array_free(Array *a);
int array_size(const Array *a);
int* array_at(Array *a, int index);
void array_inflate(Array *a, int more_size);
int array_get(const Array *a, int index);
void array_set(Array *a, int index, int value);

#endif //_ARRAY_H_
