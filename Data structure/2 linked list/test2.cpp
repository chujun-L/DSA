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

	cout << "����Ҫ��������1�����ݵĸ�����";
	cin >> num;
	while (num) {
		cout << "�����������ݣ�";
		cin >> data;

		node = new singleList;
		node->data = data;

		//singleListInsertHead(head, node);
		singleListInsertTail(head, node);

		--num;
	}

	singleListTraverse(head);

#if 0
	cout << "����Ҫ��������2�����ݵĸ�����";
	cin >> num;
	while (num) {
		cout << "�����������ݣ�";
		cin >> data;

		node = new singleList;
		node->data = data;

		//singleListInsertHead(head, node);
		singleListInsertTail(head2, node);

		--num;
	}

	cout << "�ϲ�����1������2" << endl;
	singleListMerge(head, head2);
	singleListTraverse(head);

	while (1) {
		cout << "Ҫɾ���Ľڵ㣺";
		cin >> num;

		singleListDelNode(head, num);
		singleListTraverse(head);
	}

	head = singleListDestroy(head);
	singleListTraverse(head);

	singleListRewind(head);
	singleListTraverse(head);
#endif

	cout << "ɾ�������ڼ����ڵ㣺";
	cin >> num;
	singleListDelNode(head, num);
	singleListTraverse(head);

	system("pause");
	return 0;
}