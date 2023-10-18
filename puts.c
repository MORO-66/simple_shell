#include "headers.h"
/**
 *_puts - prints an input string
 *@string: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *string)
{
	int y = 0;

	if (!string)
		return;
	while (string[y] != '\0')
	{
		_putchar(string[y]);
		y++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char ch)
{
	static int i;
	static char buf[1024];

	if (ch == BUF_FLUSH || i >= 1024)
	{
		write(1, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buf[i++] = ch;
	return (1);
}
