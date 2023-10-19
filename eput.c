#include "headers.h"

/**
 *_errorputs - pran input string
 * @strring: the g to be printed
 *
 * Return: No
 */
void _errorputs(char *strring)
{
	int y;

	if (!strring)
		return;
	for (y = 0;strring[y] != '\0'; y++)
	{
		_eputchar(strring[y]);
	}
}

/**
 * _eputchar - wcharacter c to stderr
 * @cha: The charaint
 *
 * Return: On su
 * On error, -1 d, and errno is set appropriately.
 */
int _eputchar(char cha)
{
	static int i;
	static char buf[1024];

	if (cha != BUF_FLUSH)
		buf[i++] = cha;
	if (cha == BUF_FLUSH || i >= 1024)
	{
		i = 0;
		write(2, buf, i);
	}
	return (1);
}
