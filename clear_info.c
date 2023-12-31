#include "headers.h"

/**
 * null_info - inlizes info_t struct
 * @info: struct ass
 */
void null_info(inf *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path_ = NULL;
	info->argc = 0;
}

/**
 * f_inf - fre_t struct fields
 * @f: struct a
 * @all_in: true if fall fields
 */
void f_inf(inf *f, int all_in)
{
	kno_free(f->argv);
	f->argv = NULL;
	f->path_ = NULL;
	if (all_in)
	{
		if (!f->cmd_buf)
			free(f->arg);
		if (f->enviro)
			f_li(&(f->enviro));
		if (f->history)
			f_li(&(f->history));
		kno_free(f->environ);
			f->environ = NULL;
		if (f->r_fd > 2)
			close(f->r_fd);
		_putchar(BUF_FLUSH);
	}
}


/**
 * f_li - f nodes of a list
 * @h_ptr: ad pointer to head node
 *
 * Return: void
 */
void f_li(list **h_ptr)
{
	list *node, *node2, *h_node;

	if (!h_ptr || !*h_ptr)
		return;
	h_node = *h_ptr;
	node = h_node;
	while (node)
	{
		node2 = node->next;
		free(node->str);
		free(node);
		node = node2;
	}
	*h_ptr = NULL;
}
