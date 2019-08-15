#include <iostream>
#include "queue.h"


int main1()
{
	queue_t *queue;
	int data;
	int i = 10;
	int *ret;

	queue = initQueue(10);
	if (!queue) {
		std::cout << "init queue false" << std::endl;
		system("pause");
	}

	while (i) {
		std::cout << "�������: ";
		std::cin >> data;

		enqueue(queue, data);
		--i;
	}

	while (queue->head != queue->tail) {
		ret = dequeue(queue);
		printf("��������: %d\n", *ret);
	}

	system("pause");
	return 0;
}