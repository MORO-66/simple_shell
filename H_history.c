#include "headers.h"


/**
 * build_history_list - a tstory linked list
 * @info: Structure contaenrguments. Used to maintain
 * @buf: buffer
 * @linecount: the historntcount
 *
 * Return: Always 0
 */
int Creat_his_l(inf *info, char *buf, int linecount)
{
	list *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - renumbthe history linked list after changes
 * @info: Structure containiotential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int resum(inf *info)
{
	list *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->hist_c = i);
}
