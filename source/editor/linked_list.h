#ifndef LINKED_LIST_H
# define LINKED_LIST_H

typedef struct {
	list_node*	prev;
	list_node*	next;
	void*		data;
}	list_node;

typedef struct {
	list_node**	first;
	list_node**	last;
	list_node**	cursor;
	list_node*	arena;
	unsigned int	size;
	unsigned int	capacity;
}	list_t;

list_t*	list_init();
int	list_expend(list_t*);
void	list_clear(list_t*);

#ifdef LLIST_IMPLEMENTATION

list_t*	list_init() {
	list_t* lst = 0x00;
	lst = calloc(1, sizeof(list_t));
	assert(lst);
	lst->size = 0;
	lst->capacity = 256;
	lst->arena = calloc(lst->capacity, sizeof(list_node));
	lst->
	return (lst);
}

int	list_expend(list* lst) {
	return (0);
}

void	list_clear() {

}

#endif

#endif
