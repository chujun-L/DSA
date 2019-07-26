#include <iostream>
#include "../include/sqlist.h"

elem_type *init_sqlist(sqlist &l)
{
	l.elems = new elem_type[SQLIST_MAX_SIZE]();
	if (l.elems) {
		l.length = 0;
		l.size = SQLIST_MAX_SIZE * sizeof(elem_type);
		return l.elems;
	}

	return NULL;
}

bool is_empty_sqlist(const sqlist &l)
{
	if (0 == l.length) {
		return true;
	}

	return false;
}

bool is_full_sqlist(const sqlist &l)
{
	if (SQLIST_MAX_SIZE - 1 < l.length) {
		return true;
	}

	return false;
}

sqlist_int_t add_sqlist(sqlist &l, const elem_type elem)
{
	if (is_full_sqlist(l)) {
		cout << "sqlist is full" << endl;
		return -1;
	}

	l.elems[l.length] = elem;
	l.length++;

	return 0;
}

sqlist_int_t insert_sqlist(sqlist &l, const sqlist_uint_t pos, const elem_type elem)
{
	sqlist_uint_t i;

	if (is_full_sqlist(l)) {
		cout << "sqlist is full" << endl;
		return -1;
	}

	if (pos >= 0 && pos < l.length) {
		for (i = l.length; i > pos; --i) {
			l.elems[i] = l.elems[i - 1];
		}

		l.elems[pos] = elem;
		l.length++;

		return 0;
	}

	cout << "out of sqlist length's range" << endl;
	return -1;
}

sqlist_int_t delete_elem_sqlist(sqlist &l, const sqlist_uint_t pos)
{
	sqlist_uint_t i;

	if (is_empty_sqlist(l)) {
		cout << "sqlist is empty" << endl;
		return -1;
	}

	if (pos >= 0 && pos < l.length) {
		for (i = pos; i < l.length; ++i) {
			l.elems[i] = l.elems[i + 1];
		}

		l.length--;
		return 0;
	}

	cout << "out of sqlist length's range" << endl;
	return -1;
}

sqlist_int_t modify_elem_sqlist(sqlist &l, const sqlist_uint_t pos, const elem_type elem)
{
	if (is_empty_sqlist(l)) {
		cout << "sqlist is empty" << endl;
		return -1;
	}

	if (pos >= 0 && pos < l.length) {
		l.elems[pos] = elem;
		return 0;
	}

	cout << "out of sqlist length's range" << endl;
	return -1;
}

#if 0
elem_type get_elem_sqlist(sqlist &l, sqlist_uint_t pos)
{
	if (is_empty_sqlist(l)) {
		cout << "sqlist is empty" << endl;
		return -1;
	}

	if (pos >= 0 && pos < l.length) {
		return l.elems[pos]; 
	}

	cout << "out of sqlist length's range" << endl;
	return -1;
}


void traversal_sqlist(const sqlist &l)
{
	sqlist_uint_t i;

	for (i = 0; i < l.length; ++i) {
		cout << "fd: " << l.elems[i].fd << " " \
			<< "timeout: " << l.elems[i].timeout << endl;
	}
	cout << endl;
}
#endif

void destroy_sqlist(sqlist &l)
{
	if (l.elems) {
		delete[] l.elems;
	}
}