#include "headers.h"

/**
 * populate_env_list - ponked list
 * @info: Structure contal arguments. Used to maintain
 *          constant func.
 * Return: Always 0
 */
int prepare_env(inf *f)
{
	list *node = NULL;
	size_t iter;

	for (iter = 0; environ[iter]; iter++)
		add_node_end(&node, environ[iter], 0);
	f->enviro = node;
	return (0);
}


/**
 * get_environ - rettring array copy of our environ
 * @info: Structure  potential arguments. Used to maintain
 *          constantprototype.
 * Return: Always 0
 */
char ** take_environ(inf *f)
{
	if (!f->environ || f->env_ch)
	{
		f->environ = list_to_strings(f->enviro);
		f->env_ch = 0;
	}

	return (f->environ);
}
