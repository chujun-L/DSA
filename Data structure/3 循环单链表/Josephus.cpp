#include <iostream>
#include "include/cycleSingleList.h"


int main()
{
	CYList *head, *node;
	int num;

	head = createCYList();

	std::cout << "����Ҫ����ѭ��������ĸ���: ";
	std::cin >> num;
	while (num) {
		node = new CYList;

		std::cout << "Ҫ���������: ";
		std::cin >> node->data;

		insertCYListTail(head, node);
		--num;
	}

	//traverseCYList(head);

#if 0
	std::cout << "ɾ��ָ���Ľڵ�: ";
	std::cin >> num;
	delCYListNode(head, num);
	traverseCYList(head);
#endif

	josephus(head, 9);


	system("pause");
	return 0;
}
