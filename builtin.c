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
int which_cmd(inf *f)
{
	int iter, Builtin_retation = -1;
	builtin_table builtintbl[] = {
/*		{"exit", _myexit},*/
		{"help", _myhelp},
/*		{"history", _myhistory},*/
		{NULL, NULL}
	};

	for (iter = 0; builtintbl[iter].type; iter++)
		if (_strcmp(f->argv[0], builtintbl[iter].type) == 0)
		{
			f->line_c++;
			Builtin_retation = builtintbl[iter].func(f);
			break;
		}
	return (Builtin_retation);
}
