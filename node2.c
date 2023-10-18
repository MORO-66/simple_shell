#include "headers.h"

/**
 * len_of_list - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t len_of_list(const list *h)
{
	size_t t = 0;

	while (h)
	{
		h = h->next;
		t++;
	}
	return (t);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @h_h: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list *h_h)
{
	list *node = h_h;
	size_t y = len_of_list(h_h), j;
	char **s_s;
	char *str;

	if (!h_h || !y)
		return (NULL);
	s_s = malloc(sizeof(char *) * (y + 1));
	if (!s_s)
		return (NULL);
	for (y = 0; node; node = node->next, y++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < y; j++)
				free(s_s[j]);
			free(s_s);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		s_s[y] = str;
	}
	s_s[y] = NULL;
	return (s_s);
}
