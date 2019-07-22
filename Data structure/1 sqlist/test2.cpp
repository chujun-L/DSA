#include <iostream>
#include <ctime>
#include <Windows.h>
#include "include/sqlist.h"


int main()
{
	time_t now, timeout;
	unsigned i, j = 0;
	sqlist l;
	client c;

	time(&now);
	timeout = now;

	init_sqlist(l);
	for (i = 0; i < 10; i++) {
		c.fd = i;
		c.timeout = now + 5 + 2 * i;
		add_sqlist(l, c);
	}
	traversal_sqlist(l);

	do {
		// ÑÓÊ±1Ãë
		if (timeout + 1 < now) {
			// do something
			std::cout << "delet: fd-> " << l.elems[j].fd << "	"\
				<< "timeout-> " << l.elems[j].timeout << std::endl;
			delete_elem_sqlist(l, j);
		
			timeout = now;	// ¸üÐÂtimeout
		}
		time(&now);

		Sleep(1);
	} while (1);


	system("pause");
	return 0;
}