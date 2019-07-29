
#include <iostream>
#include "../include/array.h"


array_t *createArray(uint n, size_t size)
{
	array_t *a;
	a = new array_t;
	if (!a) {
		return a;
	}

	a->nelts = 0;
	a->size = size;
	a->nalloc = n;

	a->elts = new int[n];
	if (!a->elts) {
		return NULL;
	}

	return a;
}

int *pushArray(array_t *a, int data)
{
	int *elt, *exp;
	size_t size;

	size = a->size * a->nalloc;

	// 判断数组容量是否满
	if (a->nelts == a->nalloc) {
		std::cout << "数组已满" << std::endl;

		// 扩容2倍 
		exp = new int[2 * size];
		if (!exp) {
			return NULL;
		}

		memcpy(exp, a->elts, size);
		delete a->elts;
		a->elts = exp;
		a->nalloc *= 2;
	}

	elt = a->elts + a->size * a->nelts;
	a->elts[a->nelts] = data;

	a->nelts++;

	return elt;
}