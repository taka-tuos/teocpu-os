/*
 * malloc.c
 *
 * Very simple linked-list based malloc()/free().
 */

#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "malloc.h"

extern void *__malloc(size_t siz);
extern void __free(void *ptr);

void *malloc(size_t size)
{
	return __malloc(size);
}

void free(void *ptr)
{
	__free(ptr);
}
