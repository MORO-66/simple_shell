#include "headers.h"
/**
 * starts_with - checks if n with haystack
 * @haystack: string to sear
 * @needle: the substring to
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
