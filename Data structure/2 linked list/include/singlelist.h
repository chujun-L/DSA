#ifndef _SINGLE_LIST_H_
#define _SINGLE_LIST_H_

typedef struct singleList {
	struct singleList *next;
	int data;
}singleList;

singleList *singleListGreat();
singleList *singleListInsertHead(singleList *head, singleList *node);
singleList *singleListInsertTail(singleList *head, singleList *node);
void singleListDelNode(singleList *head, int index);
singleList *singleListDestroy(singleList *head);
singleList *singleListRewind(singleList *head);
singleList *singleListMerge(singleList *head1, singleList *head2);
bool singleListCheckCycle(singleList *head);
void singleListTraverse(singleList *head);

#endif
