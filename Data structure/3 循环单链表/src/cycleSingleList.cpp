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

	// 在循环单链表里，最后一个节点指向头节点
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

	std::cout << "遍历循环单链表：";
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

	// 统计循环单链表里的节点个数
	p = head;
	while (p->next != head) {
		p = p->next;
		++s;
	}

	// 判断要删除节点的合法性
	if (num < 1 || num > s) {
		return NULL;
	}

	// 删除指定的节点
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
				++c;		// 跳过头节点报数
			}

			if (c == interval) {
				break;	// 到达间隔数
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

		c = 0;		// 报数清零
		++cycle;		// 计算第几轮

		del = p->next;		// 要被踢除的节点
		d = del->data;

		if (5 == cycle) {
			std::cout << "第5轮被踢除的是: " << d << std::endl;
		}

		p->next = del->next;
		delete del;

		traverseCYList(head);
	} while (head->next->next != head);

	std::cout << "最后被踢除的是: " << d << std::endl;

	return true;
}