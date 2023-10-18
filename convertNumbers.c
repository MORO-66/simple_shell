#include "headers.h"

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int inputs, int filediscribe)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (filediscribe == STDERR_FILENO)
		__putchar = _eputchar;
	if (inputs < 0)
	{
		_abs_ = -inputs;
		__putchar('-');
		count++;
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

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int number, int b, int f)
{
	static char *array;
	static char buffer[50];
	char nhgis = 0;
	char *ptr_s;
	unsigned long n = number;

	if (!(f & CONVERT_UNSIGNED) && number < 0)
	{
		n = -number;
		nhgis = '-';

	}
	array = f & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr_s = &buffer[49];
	*ptr_s = '\0';

	do	{
		*--ptr_s = array[n % b];
		n /= b;
	} while (n != 0);

	if (nhgis)
		*--ptr_s = nhgis;
	return (ptr_s);
}
