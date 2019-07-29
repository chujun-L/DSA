#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef unsigned int uint;

typedef struct array_s {
	int *elts;		// 数组首地址
	uint nelts;		// 数组内元素的数量
	size_t size;		// 元素的大小
	uint nalloc;		// 数组总容量
}array_t;

array_t *createArray(uint n, size_t size);
int *pushArray(array_t *a, int data);

#endif // !_ARRAY_H_
