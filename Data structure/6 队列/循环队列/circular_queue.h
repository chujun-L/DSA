#ifndef _CIRCULAR_QUEUE_H_
#define _CIRCULAR_QUEUE_H_



typedef struct circular_queue_s {
	int *elems;		// ���г�Ա
	int circular;	// ���л��Ĵ�С
	int head;		// ��ͷ
	int tail;		// ��β
}cq_t;


#define is_circular_queue_empty(cq)		((cq)->head == (cq)->tail)
#define is_circular_queue_full(cq)			(((cq)->tail + 1) % (cq)->circular == (cq)->head)

// ����ѭ������
cq_t *creat_circular_queue(int size);
// ���
bool enqueue(cq_t *cq, int elem);
// ����
int dequeue(cq_t *cq);


#endif // !_CYCLE_QUEUE_H_
