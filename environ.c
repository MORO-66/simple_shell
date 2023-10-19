#include "headers.h"


/**
 * take_environ - rettring array copy of our environ
 * @f: Structure  potential arguments. Used to maintain
 *          constantprototype.
 * Return: Always 0
 */
char **take_environ(inf *f)
{
	if (!f->environ || f->env_ch)
	{
		f->env_ch = 0;
		f->environ = list_to_strings(f->enviro);
	}

	return (f->environ);
}
