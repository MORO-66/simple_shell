#include "headers.h"
/**
 * print_list_str - pr only the str element of a list_t linked list
 * @h: pointer to firsde
 *
 * Return: size of lis
 */
size_t print_list_sstring(const list *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * print_list - printents of a list_t linked list
 * @h: pointer to fir
 *
 * Return: size of li
 */
size_t print_list(const list *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}
