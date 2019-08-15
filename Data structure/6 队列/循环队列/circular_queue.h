#ifndef _CIRCULAR_QUEUE_H_
#define _CIRCULAR_QUEUE_H_



typedef struct circular_queue_s {
	int *elems;		// 队列成员
	int circular;	// 队列环的大小
	int head;		// 环头
	int tail;		// 环尾
}cq_t;


#define is_circular_queue_empty(cq)		((cq)->head == (cq)->tail)
#define is_circular_queue_full(cq)			(((cq)->tail + 1) % (cq)->circular == (cq)->head)

// 创建循环队列
cq_t *creat_circular_queue(int size);
// 入队
bool enqueue(cq_t *cq, int elem);
// 出队
int dequeue(cq_t *cq);


#endif // !_CYCLE_QUEUE_H_
