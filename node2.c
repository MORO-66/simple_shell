#include "headers.h"

/**
 * list_len - determines length of linked list
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
 * @head: pointer to first node
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


/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list *node_s_with(list *no, char *pre, char ch)
{
	char *p = NULL;

	while (no)
	{
		p = start(no->str, pre);
		if (p && ((ch == -1) || (*p == ch)))
			return (no);
		no = no->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_in_index(list *h_h, list *no)
{
	size_t i = 0;

	while (h_h)
	{
		if (h_h == no)
			return (i);
		h_h = h_h->next;
		i++;
	}
	return (-1);
}
