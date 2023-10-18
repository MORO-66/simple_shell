#include "headers.h"
/**
 * _myenv - prrent environment
 * @info: Struning potential arguments. Used to maintain
 *          coion prototype.
 * Return: Alw
 */
/*
int _myenv(inf *f)
{
	print_list_sstring(f->enviro);
	return (0);
}
*/

/**
 * _mysetenv - Ine a new environment variable,
 *             or an existing one
 * @info: Structuaining potential arguments. Used to maintain
 *        constanion prototype.
 *  Return: Alway
 */
/*
int _my_setenv(inf *info)
{
	if (info->argc != 3)
	{
		_errorputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}
*/
/**
 * _myunsetenv -  environment variable
 * @info: Structuning potential arguments. Used to maintain
 *        constann prototype.
 *  Return: Alway
 */
/*
int _my_unsetenv(inf *info)
{
	int i;

	if (info->argc == 1)
	{
		_errorputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}
*/

/**
 * _unsetenv - Removet variable
 * @info: Structure cntial arguments. Used to maintain
 *        constant fupe.
 *  Return: 1 on delee
 * @var: the string ey
 */
/*
int _unsetenv(inf *info, char *var)
{
	list *node = info->enviro;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = start(node->str, var);
		if (p && *p == '=')
		{
			info->env_ch = delete_node_at_index(&(info->enviro), i);
			i = 0;
			node = info->enviro;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_ch);
}
*/
/**
 * _setenv - Initenvironment variable,
 *             oristing one
 * @info: Structu potential arguments. Used to maintain
 *        constanototype.
 * @var: the strioperty
 * @value: the stvalue
 *  Return: Alway
 */
int _setenv(inf *info, char *var, char *value)
{
	char *buf = NULL;
	list *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->enviro;
	while (node)
	{
		p = start(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_ch = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->enviro), buf, 0);
	free(buf);
	info->env_ch = 1;
	return (0);
}
