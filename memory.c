#include "headers.h"

/**
 **_memset - fillth a constant byte
 *@s: the pointerory area
 *@b: the byte toth
 *@n: the amount  be filled
 *Return: (s) a phe memory area s
 */
char * _mem_set(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - frees aof strings
 * @pp: string of 
 */
void kno_free(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - ra block of memory
 * @ptr: pointeus malloc'ated block
 * @old_size: b previous block
 * @new_size: b new block
 *
 * Return: poinl'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
