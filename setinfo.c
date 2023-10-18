#include "headers.h"
/**
 * set_info - initiinfo_t struct
 * @info: struct ad
 * @av: argument ve
 */
void reset_info(inf *f, char **argv)
{
	int y = 0;

	f->filename = argv[0];
	if (f->arg)
	{
		f->argv = string_to_words(f->arg, " \t");
		if (!f->argv)
		{

			f->argv = malloc(sizeof(char *) * 2);
			if (f->argv)
			{
				f->argv[0] = _strdup(f->arg);
				f->argv[1] = NULL;
			}
		}
		for (y = 0; f->argv && f->argv[y]; y++)
			;
		f->argc = y;

		change_alias(f);
		/*dollar_handler(f);*/
	}
}