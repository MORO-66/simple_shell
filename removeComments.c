#include "headers.h"

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void removeComments(char *buff)
{
	int y;

	for (y = 0; buff[y] != '\0'; y++)
		if (buff[y] == '#' && (!y || buff[y - 1] == ' '))
		{
			buff[y] = '\0';
			break;
		}
}
