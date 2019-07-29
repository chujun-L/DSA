#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef unsigned int uint;

typedef struct array_s {
	int *elts;		// �����׵�ַ
	uint nelts;		// ������Ԫ�ص�����
	size_t size;		// Ԫ�صĴ�С
	uint nalloc;		// ����������
}array_t;

array_t *createArray(uint n, size_t size);
int *pushArray(array_t *a, int data);

#endif // !_ARRAY_H_
