#include "headers.h"


/**
 * Creat_his_l - a tstory linked list
 * @f: Structure contaenrguments. Used to maintain
 * @buff: buffer
 * @line_cou: the historntcount
 *
 * Return: Always 0
 */
int Creat_his_l(inf *f, char *buff, int line_cou)
{
	list *node = NULL;

	if (f->history)
		node = f->history;
	add_node_end(&node, buff, line_cou);

	if (!f->history)
		f->history = node;
	return (0);
}

/**
 * resum - renumbthe history linked list after changes
 * @f: Structure containiotential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int resum(inf *f)
{
	list *node = f->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (f->hist_c = i);
}
