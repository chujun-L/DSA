#ifndef _SQLIST_H_
#define _SQLIST_H_

#include <iostream>
#include "star.h"

using std::cin;
using std::cout;
using std::endl;

#define SQLIST_MAX_SIZE		99

typedef unsigned int sqlist_uint_t;
typedef int sqlist_int_t;
//typedef unsigned elem_type;

typedef struct {
	elem_type *elems;
	sqlist_uint_t length;
	sqlist_uint_t size;
}sqlist;

elem_type *init_sqlist(sqlist &l);
bool is_empty_sqlist(const sqlist &l);
bool is_full_sqlist(const sqlist &l);
sqlist_int_t add_sqlist(sqlist &l, const elem_type elem);
sqlist_int_t insert_sqlist(sqlist &l, const sqlist_uint_t pos, const elem_type elem);
sqlist_int_t delete_elem_sqlist(sqlist &l, const sqlist_uint_t pos);
sqlist_int_t modify_elem_sqlist(sqlist &l, const sqlist_uint_t pos, const elem_type elem);
elem_type get_elem_sqlist(sqlist &l, sqlist_uint_t pos);
void traversal_sqlist(const sqlist &l);
void destroy_sqlist(sqlist &l);

#endif // !_SQLIST_H_
