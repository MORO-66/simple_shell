#include "headers.h"
/**
 * _getenv - gf an environ variable
 * @f: Strug potential arguments. Used to maintain
 * @filename: env
 *
 * Return: the
 */
char *_getenv(inf *f, const char *filename)
{
	char *p;
	list *node = f->enviro;

	while (node)
	{
		p = start(node->str, filename);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}
/**
 * get_h_f - gfile
 * @info: paramestr
 *
 * Return: alloc ststory file
 */

char *get_h_f(inf *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}
