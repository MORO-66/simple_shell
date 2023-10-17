#include "headers.h"
/**
 * set_info - initiinfo_t struct
 * @info: struct ad
 * @av: argument ve
 */
void reset_info(inf *info, char **av)
{
	int i = 0;

	info->filename = av[0];
	if (info->arg)
	{
		info->argv = string_to_words(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		change_alias(info);
		dollar_handler(info);
	}
}