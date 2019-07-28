#include <cstddef>
#include <iostream>
#include "../include/cycleSingleList.h"


CYList *createCYList()
{
	CYList *head;

	head = new CYList;
	if (!head) {
		return head;
	}

	head->next = head;
	head->data = 0;
	return head;
}

CYList *insertCYListTail(CYList *head, CYList *node)
{
	CYList *p;

	if (!head || !node) {
		return NULL;
	}

	// ��ѭ������������һ���ڵ�ָ��ͷ�ڵ�
	p = head;
	while (p->next != head) {
		p = p->next;
	}

	p->next = node;
	node->next = head;
	return node;
}

void traverseCYList(CYList *head)
{
	CYList *p;

	if (!head || !head->next) {
		return;
	}

	std::cout << "����ѭ��������";
	p = head;
	while (p->next != head) {
		p = p->next;
		// to do
		std::cout << p->data << " ";
	}
	std::cout << std::endl;
}

CYList *delCYListNode(CYList *head, int num)
{
	CYList *p, *del;
	int s = 0;

	if (!head) {
		return head;
	}

	// ͳ��ѭ����������Ľڵ����
	p = head;
	while (p->next != head) {
		p = p->next;
		++s;
	}

	// �ж�Ҫɾ���ڵ�ĺϷ���
	if (num < 1 || num > s) {
		return NULL;
	}

	// ɾ��ָ���Ľڵ�
	p = head;
	del = head->next;
	while (num - 1) {
		p = p->next;
		del = del->next;
		--num;
	}
	p->next = del->next;
	delete del;
	return head;
}

bool josephus(CYList *head, int interval)
{
	CYList *p, *del;
	int c, i, cycle, d;

	c = i = cycle = d = 0;
	p = head;

	if (!head || interval < 1) {
		return false;
	}

	do {
#if 0
		while (p->next) {
			if (p->next != head) {
				++c;		// ����ͷ�ڵ㱨��
			}

			if (c == interval) {
				break;	// ��������
			}

			p = p->next;
		}
#endif
		for (; p->next; p = p->next) {
			if (p->next != head) {
				++c;
			}

			if (interval == c) {
				break;
			}
		}

		c = 0;		// ��������
		++cycle;		// ����ڼ���

		del = p->next;		// Ҫ���߳��Ľڵ�
		d = del->data;

		if (5 == cycle) {
			std::cout << "��5�ֱ��߳�����: " << d << std::endl;
		}

		p->next = del->next;
		delete del;

		traverseCYList(head);
	} while (head->next->next != head);

	std::cout << "����߳�����: " << d << std::endl;

	return true;
}