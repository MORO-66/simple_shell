#include "headers.h"

/**
 * add_node - addthe start of the list
 * @head: addressto head node
 * @str: str fiel
 * @num: node indistory
 *
 * Return: size o
 */
list *add_node(list **head, const char *str, int num)
{
	list *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list));
	if (!new_head)
		return (NULL);
	_mem_set((void *)new_head, 0, sizeof(list));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - addde to the end of the list
 * @head: address of r to head node
 * @str: str field of
 * @num: node index u history
 *
 * Return: size of li
 */
list *add_node_end(list **head, const char *str, int num)
{
	list *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list));
	if (!new_node)
		return (NULL);
	_mem_set((void *)new_node, 0, sizeof(list));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}


/**
 * delete_node_at_index - delete index
 * @head: address of pointer to 
 * @index: index of node to dele
 *
 * Return: 1 on success, 0 on fa
 */
int delete_node_at_index(list **head, unsigned int index)
{
	list *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

