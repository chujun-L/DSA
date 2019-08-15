#include <iostream>
#include "circular_queue.h"


// 创建循环队列
cq_t *creat_circular_queue(int size)
{
	cq_t *cq = new cq_t;
	if (!cq) {
		return cq;
	}

	cq->elems = new int[size];
	if (!cq->elems) {
		return NULL;
	}

	cq->head = 0;
	cq->tail = 0;
	cq->circular = size;

	return cq;
}

// 入队
bool enqueue(cq_t *cq, int elem)
{
	int i, size;

	if (!cq || is_circular_queue_full(cq)) {
		std::cout << "queue is full" << std::endl;
		return false;
	}

	i = cq->tail;
	size = cq->circular;

	cq->elems[i] = elem;
	cq->tail = (cq->tail + 1) % size;

	return true;
}



// 出队
int dequeue(cq_t *cq)
{
	int ret, i, size;

	if (!cq || is_circular_queue_empty(cq)) {
		std::cout << "queue is empty" << std::endl;
		return -1;
	}

	i = cq->head;
	size = cq->circular;

	ret = cq->elems[i];
	cq->head = (cq->head + 1) % size;

	return ret;
}