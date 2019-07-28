#include <iostream>
#include "include/singlelist.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	singleList *head, *head2, *node;
	int num, data;

	head = singleListGreat();
	head2 = singleListGreat();

	cout << "输入要插入链表1的数据的个数：";
	cin >> num;
	while (num) {
		cout << "输入插入的数据：";
		cin >> data;

		node = new singleList;
		node->data = data;

		//singleListInsertHead(head, node);
		singleListInsertTail(head, node);

		--num;
	}

	singleListTraverse(head);

#if 0
	cout << "输入要插入链表2的数据的个数：";
	cin >> num;
	while (num) {
		cout << "输入插入的数据：";
		cin >> data;

		node = new singleList;
		node->data = data;

		//singleListInsertHead(head, node);
		singleListInsertTail(head2, node);

		--num;
	}

	cout << "合并链表1、链表2" << endl;
	singleListMerge(head, head2);
	singleListTraverse(head);

	while (1) {
		cout << "要删除的节点：";
		cin >> num;

		singleListDelNode(head, num);
		singleListTraverse(head);
	}

	head = singleListDestroy(head);
	singleListTraverse(head);

	singleListRewind(head);
	singleListTraverse(head);
#endif

	cout << "删除倒数第几个节点：";
	cin >> num;
	singleListDelNode(head, num);
	singleListTraverse(head);

	system("pause");
	return 0;
}