#include "headers.h"
/**
 * _put_as_fd - writes the character c to given fd
 * @ch: The character to print
 * @filed: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _put_as_fd(char ch, int filed)
{
	static int i;
	static char buf[1024];

	if (ch == BUF_FLUSH || i >= 1024)
	{
		write(filed, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buf[i++] = ch;
	return (1);
}

/**
 *_puts_as_fd - prints an input string
 * @strring: the string to be printed
 * @filedd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _puts_as_fd(char *strring, int filedd)
{
	int i = 0;

	if (!strring)
		return (0);
	while (*strring)
	{
		i += _put_as_fd(*strring++, filedd);
	}
	return (i);
}
