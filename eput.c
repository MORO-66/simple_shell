#include "headers.h"

/**
 *_eputs - pran input string
 * @str: the g to be printed
 *
 * Return: No
 */
void _errorputs(char *strring)
{
	int y = 0;

	if (!strring)
		return;
	while (strring[y] != '\0')
	{
		_eputchar(strring[y]);
		y++;
	}
}

/**
 * _eputchar - wcharacter c to stderr
 * @c: The charaint
 *
 * Return: On su
 * On error, -1 d, and errno is set appropriately.
 */
int _eputchar(char cha)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (cha == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (cha != BUF_FLUSH)
		buf[i++] = cha;
	return (1);
}
