#include "headers.h"


/**
 * replace_string - repling
 * @old: address of old 
 * @new: new string
 *
 * Return: 1 if replacedrwise
 */
int replace_string(char **curr, char *now)
{
	free(*curr);
	*curr = now;
	return (1);
}
