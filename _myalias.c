#include "headers.h"
/**
 * unset_alias - sias to string
 * @info: parametect
 * @str: the strins
 *
 * Return: Always uccess, 1 on error
 *//*
int unset_aliases(inf *f, char *string)
{
	char *ptr, cha;
	int retation;

	ptr = _chr_search(string, '=');
	if (!ptr)
		return (1);
	cha = *ptr;
	*ptr = 0;
	retation = delete_node_at_index(&(f->aliases),
		get_in_index(f->aliases, node_s_with(f->aliases, string, -1)));
	*ptr = cha;
	return (retation);
}
*/
/**
 * set_alias - se to string
 * @info: paramett
 * @str: the stri
 *
 * Return: Alwaysccess, 1 on error
 */
/*
int do_alias(inf *f, char *string)
{
	char *str;

	str = _chr_search(string, '=');
	if (!str)
		return (1);
	if (!*++str)
		return (/*unset_aliases(f, string)*//* 0);

	/*unset_aliases(f, string);*//*
	return (add_node_end(&(f->aliases), string, 0) == NULL);
}
*/
/**
 * print_alias - pts atring
 * @node: the aliaode
 *
 * Return: Always n suon error
 */
/*
int print_aliases(list *node_)
{
	char *p = NULL, *a = NULL;

	if (node_)
	{
		p = _chr_search(node_->str, '=');
		for (a = node_->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
*/
/**
 * _myalias - mimiltin (man alias)
 * @info: Structurential arguments. Used to maintain
 *          constaotype.
 *  Return: Always
 */
/*int _myalias(inf* f)
{
	int in = 0;
	char *ptr = NULL;
	list *node = NULL;

	if (f->argc == 1)
	{
		node = f->aliases;
		while (node)
		{
			/*print_aliases(node);*//*
			node = node->next;
		}
		return (0);
	}
	for (in = 1; f->argv[in]; in++)
	{
		ptr = _chr_search(f->argv[in], '=');
		if (ptr)
			/*do_alias(f, f->argv[in]);*//*
		else
			/*print_aliases(node_s_with(f->aliases, f->argv[in], '='));
	}

	return (0);
}

*/
/**
 * replace_alias -liases in the tokenized string
 * @info: the para
 *
 * Return: 1 if rerwise
 */
int change_alias(inf *info)
{
	int it;
	list *node;
	char *str;

	for (it = 0; it < 10; it++)
	{
		node = node_s_with(info->aliases, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		str = _chr_search(node->str, '=');
		if (!str)
			return (0);
		str = _strdup(str + 1);
		if (!str)
			return (0);
		info->argv[0] = str;
	}
	return (1);
}
