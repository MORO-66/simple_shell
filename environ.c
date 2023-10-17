#include "headers.h"

/**
 * populate_env_list - ponked list
 * @info: Structure contal arguments. Used to maintain
 *          constant func.
 * Return: Always 0
 */
int prepare_env(inf *info)
{
	list *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->enviro = node;
	return (0);
}


/**
 * get_environ - rettring array copy of our environ
 * @info: Structure  potential arguments. Used to maintain
 *          constantprototype.
 * Return: Always 0
 */
char ** take_environ(inf *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->enviro);
		info->env_ch = 0;
	}

	return (info->environ);
}
