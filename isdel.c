#include "headers.h"
/**
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char cch, char *d)
{
	while (*d)
		if (*d++ == cch)
			return (1);
	return (0);
}
