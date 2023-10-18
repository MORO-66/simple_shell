#include "headers.h"

/**
 * clear_info - inlizes info_t struct
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
 * free_info - fre_t struct fields
 * @info: struct a
 * @all: true if fall fields
 */
void free_info(inf *f, int all_in)
{
	kno_free(f->argv);
	f->argv = NULL;
	f->path_ = NULL;
	if (all_in)
	{
		if (!f->cmd_buf)
			free(f->arg);
		if (f->enviro)
			free_list(&(f->enviro));
		if (f->history)
			free_list(&(f->history));
		kno_free(f->environ);
			f->environ = NULL;
		/*info->cmd_buf = NULL;*/
		if (f->r_fd > 2)
			close(f->r_fd);
		_putchar(BUF_FLUSH);
	}
}


/**
 * free_list - f nodes of a list
 * @head_ptr: ad pointer to head node
 *
 * Return: void
 */
void free_list(list **h_ptr)
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