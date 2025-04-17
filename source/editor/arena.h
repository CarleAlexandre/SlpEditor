#ifndef ARENA_H
# define ARENA_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	uint8_t		buffer[4096];
	bool		empty;
	uint16_t	size;
}	page_t;

typedef struct {
	page_t*		pages;
	uint32_t	capacity;
	uint32_t	size;
	uint32_t	latest_access;
}	arena_t;

typedef struct {
}	forgotten_t;//??what is this i forgot what as was doing ffs

typedef inline void	arena_init(uint32_t);
typedef inline void	arena_alloc();


#ifdef ARENA_IMPLEMENTATION

static inline void arena_init(uint32_t n_page) {

}

#endif

#endif