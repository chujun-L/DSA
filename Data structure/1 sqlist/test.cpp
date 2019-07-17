#include <iostream>
#include "include/sqlist.h"

int main()
{
	sqlist l;
	int i, j;

	if (!init_sqlist(l))
	{
		cout << "init sqlist fail" << endl;
		return -1;
	}

	for (j = 0; j < 5; ++j) {
		cout << "add elem:";
		cin >> i;
		add_sqlist(l, i);
	}

	//insert_sqlist(l, 5, 7);
	//delete_elem_sqlist(l, 5);
	//modify_elem_sqlist(l, 5, 8);

	traversal_sqlist(l);

	destroy_sqlist(l);
	system("pause");
	return 0;
}