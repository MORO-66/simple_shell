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
void free_info(inf *info, int all)
{
	kno_free(info->argv);
	info->argv = NULL;
	info->path_ = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->enviro)
			free_list(&(info->enviro));
		if (info->history)
			free_list(&(info->history));
		if (info->aliases)
			free_list(&(info->aliases));
		kno_free(info->environ);
			info->environ = NULL;
		info->cmd_buf = NULL;
			//must_free((void **)(info->cmd_buf));
		if (info->r_fd > 2)
			close(info->r_fd);
		_putchar(BUF_FLUSH);
	}
}


/**
 * free_list - f nodes of a list
 * @head_ptr: ad pointer to head node
 *
 * Return: void
 */
void free_list(list **head_ptr)
{
	list *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
/**
 * bfree - frees ULLs the address
 * @ptr: address to free
 *
 * Return: 1 if f 0.
 */
int must_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
