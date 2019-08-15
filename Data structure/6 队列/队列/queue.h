#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct queue_s {
	int *q;
	int head;
	int tail;
	int size;
}queue_t;

queue_t *initQueue(int size);
bool enqueue(queue_t *q, int data);
int *dequeue(queue_t *q);


#endif // !_QUEUE_H_

