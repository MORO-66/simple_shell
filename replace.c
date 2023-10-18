#include "headers.h"

/**
 * replace_vars - replacthe tokenized string
 * @info: the parameter 
 *
 * Return: 1 if replacedse
 */
/*
int dollar_handler(inf *f)
{
	int y = 0;
	list *no;

	for (y = 0; f->argv[y]; y++)
	{
		if (f->argv[y][0] != '$' || !f->argv[y][1])
			continue;

		if (!_strcmp(f->argv[y], "$?"))
		{
			replace_string(&(f->argv[y]),
				_strdup(convert_number(f->status, 10, 0)));
			continue;
		}
		if (!_strcmp(f->argv[y], "$$"))
		{
			replace_string(&(f->argv[y]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		no = node_s_with(f->enviro, &f->argv[y][1], '=');
		if (no)
		{
			replace_string(&(f->argv[y]),
				_strdup(_chr_search(no->str, '=') + 1));
			continue;
		}
		replace_string(&f->argv[y], _strdup(""));

	}
	return (0);
}
*/
/**
 * replace_string - repling
 * @old: address of old 
 * @new: new string
 *
 * Return: 1 if replacedrwise
 */
int replace_string(char **curr, char *now)
{
	free(*curr);
	*curr = now;
	return (1);
}
