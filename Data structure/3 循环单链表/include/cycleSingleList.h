#ifndef _CYCLE_SINGLE_LIST_
#define _CYCLE_SINGLE_LIST_

typedef struct cycle_single_list {
	struct cycle_single_list *next;
	int data;
}CYList;

CYList *createCYList();
CYList *insertCYListTail(CYList *head, CYList *node);
void traverseCYList(CYList *head);
CYList *delCYListNode(CYList *head, int num);
bool josephus(CYList *head, int interval);

#endif // !_CYCLE_SINGLE_LIST_
