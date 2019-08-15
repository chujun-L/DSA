#include <iostream>
#include "circular_queue.h"



int main()
{
	cq_t *cq;
	int data;
	int i = 5;
	int ret;

	cq = creat_circular_queue(5);
	if (!cq) {
		std::cout << "create circular queue false" << std::endl;
		system("pause");
		return -1;
	}


	while (i) {
		std::cout << "入队的数据: ";
		std::cin >> data;

		enqueue(cq, data);

		--i;
	}

	while (!is_circular_queue_empty(cq)) {
		ret = dequeue(cq);

		std::cout << "出队: " << ret << std::endl;
	}

	system("pause");
	return 0;
}