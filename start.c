#include "headers.h"
/**
 * start - checks if n with haystack
 * @stack: string to sear
 * @dle: the substring to
 *
 * Return: address of next cack or NULL
 */
char *start(const char *stack, const char *dle)
{
	while (*dle)
		if (*dle++ != *stack++)
			return (NULL);
	return ((char *)stack);
}
