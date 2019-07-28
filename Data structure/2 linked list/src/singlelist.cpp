#include <cstddef>
#include <iostream>
#include "../include/singlelist.h"

singleList *singleListGreat()
{
	singleList *head;

	head = new singleList;
	if (!head) {
		return head;
	}

	head->next = NULL;
	head->data = 0;
	return head;
}

singleList *singleListInsertHead(singleList *head, singleList *node)
{
	if (!head || !node) {
		return node;
	}

	node->next = head->next;
	head->next = node;
	return node;
}

singleList *singleListInsertTail(singleList *head, singleList *node)
{
	singleList *p;

	if (!head || !node) {
		return node;
	}

	p = head;
	while (p->next) {
		p = p->next;
	}
	
	p->next = node;
	node->next = NULL;
	return node;
}

void singleListDelNode(singleList *head, int index)
{
	singleList *p, *del;
	int i = 0, j = 0;

	// 统计节点数并判断index的合法性
	p = head;
	while (p->next) {
		++i;
		p = p->next;
	}

	if (!head || index <= 0 || index > i) {
		return;
	}

	// 删除index指定的节点
	p = head;
	del = head->next;
	//while (index - 1) {
	//	p = p->next;
	//	del = del->next;
	//	--index;
	//}

	j = i - index;
	while (j) {
		p = p->next;
		del = del->next;
		--j;
	}

	p->next = del->next;
	delete del;
}

singleList *singleListDestroy(singleList *head)
{
	singleList *p;

	if (!head) {
		return head;
	}

	p = head;
	while (p) {
		head = head->next;
		delete p;
		p = head;
	}
	return p;
}

singleList *singleListRewind(singleList *head)
{
	singleList *p, *pre, *next;
	p = pre = next = NULL;

	p = head->next;
	while (p) {
		next = p->next;
		p->next = pre;
		pre = p;
		p = next;
	}
	head->next = pre;
	return head;
}

singleList *singleListMerge(singleList *head1, singleList *head2)
{
	singleList *ph1, *ph2;

	if (!head1 || !head2) {
		return NULL;
	}

	// ph1定位到链表head1的结尾处
	ph1 = head1;
	while (ph1->next) {
		ph1 = ph1->next;
	}

	ph2 = head2->next;
	ph1->next = ph2;
	delete head2;

	return head1;
}

bool singleListCheckCycle(singleList *head)
{
	singleList *fast, *slow;

	if (!head || !head->next) {
		return false;
	}

	fast = slow = head;
	while (slow != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;
		}
	}

	return false;
}

void singleListTraverse(singleList *head)
{
	singleList *p;

	if (!head) {
		return;
	}

	p = head->next;
	while (p) {
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}