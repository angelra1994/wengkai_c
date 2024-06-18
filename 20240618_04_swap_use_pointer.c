#include <stdio.h>
// void swap(int *pa, int *pb);
void swap(int *, int *);

/**
 * 以下四种函数原型是等价的
 int sum(int *a, int n);
 int sum(int *, int);
 int sum(int a[], int n);
 int sum(int [], int);
 * 
 */
// void minmax(int a[], int len, int *min, int *max);
void minmax(int [], int, int *, int *);

int main(int argc, char const *argv[])
{
    int a, b;
	a = 5, b=6;
	
	/**
	 * 
	 函数需要返回多个值，某些值就只能通过指针返回
	 传入的参数实际上是需要保存带回来的结果的变量
	 * 
	 */
	swap(&a, &b);
	printf("a=%d, b=%d\n", a, b);
	

	/**
	 数组变量是特殊的指针，数组变量本身表达数组首地址 a <==> &a[0] 
	 	int a[10]; int *p = a; 无需用&取地址
	 	a == &a[0]
	 [] 运算符可以对数组左，也可以对指针做
	 	p[0] <==> a[0]
	 *运算符可以对指针做，也可以对数组做：
	 	*a = 25;
	 数组变量是const的指针，所以数组变量不能被赋值
	 	int a[] <==> int * const a 
	 */
	int arr[] = {1,2,3,4,5,6,7,8,9,12,13,14,15,16,17,23,24,25,26,27,55,};
	int min, max;
	printf("main sizeof(arr)=%lu\n", sizeof(arr));
	printf("main arr=%p(%%p)\n", arr);
	minmax(arr, sizeof(arr) / sizeof(arr[0]), &min, &max);
	printf("main arr[0]=%d, &arr[0]=%p(%%p)\n", arr[0], &arr[0]);
	printf("max=%d, min=%d\n", max, min);

	int *p = &min;
	printf("*p=%d(%%d), p=%p(%%p)\n", *p, p);
	printf("p[0]=%d(%%d), &p[0]=%p(%%p)\n", p[0], &p[0]);
	printf("p[1]=%d(%%d), &p[1]=%p(%%p)\n", p[1], &p[1]);
	printf("*arr=%d\n", *arr);

	// int brr[];  --> int * const brr
	return 0;

	/**
	指针是const, 表示一旦得到了某一个变量的地址，不能在指向其他变量
	 1. int * const q = &i; // q 是 const，q不能指向别的地址了
	 2. *q = 26;            // OK
	 3. q++;                // ERROR
	 */

	/**
	所指是const，表示不能通过这个指针去修改那个变量（并不能使得那个变量成为const）
	 1. const int *p = &i
	 2. *p = 26;             // ERROR,  (*p)是 const int
	 3. i = 26;              // OK
	 4. p = &j;              // OK
	 */

	/**
	 int i;
	 const int* p1 = &i;
	 int const* p2 = &i;
	 int *const p3 = &i;
	 
	 只有两种情况， const和*的位置
	 *在const前面，指针是const 和&i绑定了。p1和p2不能指向其他地址了 
	 const在*前面，所指是const *p的方式不能修改变量。*p3不能修改变量值（作为函数声明中参数成员）
	 */

	/**
	 const数组

	 const int a[] = {1,2,3,4,5,};
	 数组a已经是const的指针，即a不能指向其他地址；此处表示数组的每一个单元都是 const int
	 所以必须通过初始化进行赋值
	 int sum(const int a[], int len); 可以保护在函数内部不会修改数组成员的值
	 */
}

void swap(int *pa, int *pb) {
	int t = *pa;
	*pa = *pb;
	*pb = t;
}


// void minmax(int a[], int len, int *min, int *max) {
void minmax(int *a, int len, int *min, int *max) {
	int i;
	/**
	 * 函数参数列表里面的数组，实际上在函数内部是一个指针类型
	 * sizeof(a) == sizeof(int*)
	 * 但是可以用数组的运算符[] 进行计算
	 */
	// [警告] 'sizeof' on array function parameter 'a' will return size of 'int *' [-Wsizeof-array-argument]
	printf("minmax sizeof(a)=%lu\n", sizeof(a));
	printf("minmax a=%p(%%p)\n", a);
	*min = *max = a[0];
	a[0] = 1000;
	for (i=1; i<len; i++) {
		if (a[i] < *min ) {
			*min = a[i];
		}
		if (a[i] > *max) {
			*max = a[i];
		}
	}
}

