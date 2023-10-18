#include "headers.h"
/**
 * is_delim - checks if character is a delimeter
 * @cch: the char to check
 * @d: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char cch, char *d)
{
	while (*d)
		if (*d++ == cch)
			return (1);
	return (0);
}
