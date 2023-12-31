#include "headers.h"

/**
 **_mem_set - fillth a constant byte
 *@sand: the pointerory area
 *@m: the byte toth
 *@nam: the amount  be filled
 *Return: (s) a phe memory area s
 */
char *_mem_set(char *sand, char m, unsigned int nam)
{
	unsigned int iter;

	for (iter = 0; iter < nam; iter++)
		sand[iter] = m;
	return (sand);
}

/**
 * kno_free - frees aof strings
 * @ptrptr: string of
 */
void kno_free(char **ptrptr)
{
	char **a = ptrptr;

	if (!ptrptr)
		return;
	while (*ptrptr)
		free(*ptrptr++);
	free(a);
}

/**
 * _realloc - ra block of memory
 * @p: pointeus malloc'ated block
 * @one_old: b previous block
 * @one_new: b new block
 *
 * Return: poinl'block nameen.
 */
void *_realloc(void *p, unsigned int one_old, unsigned int one_new)
{
	char *ptr;

	if (!p)
		return (malloc(one_new));
	if (!one_new)
		return (free(p), NULL);
	if (one_new == one_old)
		return (p);

	ptr = malloc(one_new);
	if (!ptr)
		return (NULL);

	one_old = one_old < one_new ? one_old : one_new;
	while (one_old--)
		ptr[one_old] = ((char *)p)[one_old];
	free(p);
	return (ptr);
}
