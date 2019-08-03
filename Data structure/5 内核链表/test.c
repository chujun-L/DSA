#include <stdio.h>
#include <stdlib.h>
#include "DLinkList.h"

typedef struct node_s {
	int data;
	dlink_t list;
}node_t;




int main()
{
	int i, cycle;
	dlink_t *head = (dlink_t *)malloc(sizeof(dlink_t));
	dlink_t *pos;
	node_t *node;
	
	init_list_head(head);


	cycle = 5;
	while (cycle) {
		printf("add dlink data: ");
		scanf("%d", &i);
	
		node_t *new = (node_t *)malloc(sizeof(node_t));
		new->data = i;
		list_add_tail(&new->list, head);

		--cycle;
	}


	list_for_each(pos, head) {
		node = container_of(pos, node_t, list);

		if (3 == node->data) {
			list_del(&node->list);	
			free(node);	
		}

		printf("node's data: %d\n", node->data);
	}

	return 0;
}


