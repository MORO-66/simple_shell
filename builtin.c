#include "headers.h"
/**
 * find_builtin - fi
 * @info: the parame
 *
 * Return: -1 if bui
 *			0 if buily,
 *			1 if buissful,
 *			-2 if bu
 */
int which_cmd(inf *info)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _my_setenv},
		{"unsetenv", _my_unsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_c++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}
