#include "headers.h"

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @inputs: the input
 * @filediscribe: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int inputs, int filediscribe)
{
	unsigned int _abs_, current;
	int i, count = 0;
	int (*__putchar)(char) = _putchar;

	if (filediscribe == STDERR_FILENO)
		__putchar = _eputchar;
	if (inputs < 0)
	{
		count++;
		_abs_ = -inputs;
		__putchar('-');
	}
	else
		_abs_ = inputs;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

