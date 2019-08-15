#include <iostream>
#include "queue.h"


queue_t *initQueue(int size)
{
	queue_t *queue = new queue_t;
	if (!queue) {
		return queue;
	}

	queue->q = new int[size];
	queue->head = 0;
	queue->tail = 0;
	queue->size = size;

	return queue;
}

// 入队
bool enqueue(queue_t *q, int data)
{
	int i = q->tail;

	// 队满
	if (!q || i == q->size) {
		std::cout << "queue is full" << std::endl;
		return false;
	}

	q->q[i] = data;
	++q->tail;

	return true;
}

// 出队
int *dequeue(queue_t *q)
{
	int i = q->head;
	int *ret;

	// 队空
	if (!q || i == q->tail) {
		return NULL;
	}

	ret = &q->q[i];
	++q->head;

	return ret;
}

