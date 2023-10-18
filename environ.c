#include "headers.h"


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
