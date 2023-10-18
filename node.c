#include "headers.h"

/**
 * add_node_end - addde to the end of the list
 * @h_h: address of r to head node
 * @st: str field of
 * @mun: node index u history
 *
 * Return: size of li
 */
list *add_node_end(list **h_h, const char *st, int mun)
{
	list *one_new, *node;

	if (!h_h)
		return (NULL);

	node = *h_h;
	one_new = malloc(sizeof(list));
	if (!one_new)
		return (NULL);
	_mem_set((void *)one_new, 0, sizeof(list));
	one_new->num = mun;
	if (st)
	{
		one_new->str = _strdup(st);
		if (!one_new->str)
		{
			free(one_new);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = one_new;
	}
	else
		*h_h = one_new;
	return (one_new);
}


/**
 * delete_node_at_index - delete index
 * @h_h: address of pointer to
 * @idx: index of node to dele
 *
 * Return: 1 on success, 0 on fa
 */
int delete_node_at_index(list **h_h, unsigned int idx)
{
	list *node, *pre;
	unsigned int i = 0;

	if (!h_h || !*h_h)
		return (0);

	if (!idx)
	{
		node = *h_h;
		*h_h = (*h_h)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *h_h;
	while (node)
	{
		if (i == idx)
		{
			pre->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		pre = node;
		node = node->next;
	}
	return (0);
}

