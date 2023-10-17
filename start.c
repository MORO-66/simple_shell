#include "headers.h"
/**
 * starts_with - checks if n with haystack
 * @haystack: string to sear
 * @needle: the substring to
 *
 * Return: address of next cack or NULL
 */
char *start(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
