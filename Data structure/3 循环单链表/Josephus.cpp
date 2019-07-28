#include <iostream>
#include "include/cycleSingleList.h"


int main()
{
	CYList *head, *node;
	int num;

	head = createCYList();

	std::cout << "输入要插入循环单链表的个数: ";
	std::cin >> num;
	while (num) {
		node = new CYList;

		std::cout << "要插入的数据: ";
		std::cin >> node->data;

		insertCYListTail(head, node);
		--num;
	}

	//traverseCYList(head);

#if 0
	std::cout << "删除指定的节点: ";
	std::cin >> num;
	delCYListNode(head, num);
	traverseCYList(head);
#endif

	josephus(head, 9);


	system("pause");
	return 0;
}
