#ifndef _DLINK_LIST_H_
#define _DLINK_LIST_H_


typedef struct dlink_head_s {
	struct dlink_head_s *next, *prev;
}dlink_t;


#define offsetof(type, member)	((size_t)&((type *)0)->member)

#define container_of(ptr, type, member)	({							\
		const typeof( ((type *)0)->member  ) *__mptr = (ptr);   	\
		(type *)( (char *)__mptr - offsetof(type,member) );})



static inline void init_list_head(dlink_t *list)
{
	list->next = list;
	list->prev = list;
}

static inline void __list_add(dlink_t *new, dlink_t *prev, dlink_t *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static inline void list_add(dlink_t *new, dlink_t *head)
{
	__list_add(new, head, head->next);
}

static inline void list_add_tail(dlink_t *new, dlink_t *head)
{
	__list_add(new, head->prev, head);
}

static inline void __list_del(dlink_t *prev, dlink_t *next)
{
	next->prev = prev;
	prev->next = next;
}

static inline void list_del(dlink_t *entry)
{
	__list_del(entry->prev, entry->next);
}

static inline int list_empty(dlink_t *head)
{
	return head->next == head;
}


#define list_for_each(pos, head)	\
	for (pos = (head)->next; pos != (head); pos = (pos)->next)



#endif

